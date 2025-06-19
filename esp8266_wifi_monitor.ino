#include <ESP8266WiFi.h>
#include <EEPROM.h>

const char* ssid = "Your_WiFi_Name";
const char* password = "Your_WiFi_Password";

WiFiServer server(80);
int address = 0;  // EEPROM address

void setup() {
  Serial.begin(115200);
  EEPROM.begin(512);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\\n✅ Connected!");
  Serial.print("📡 IP Address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    int rssi = WiFi.RSSI();
    EEPROM.write(address, rssi + 128);
    EEPROM.commit();
    int powerLevel = analogRead(A0);
    int savedRSSI = EEPROM.read(address) - 128;

    int signalPercent = map(rssi, -100, -30, 0, 100);
    signalPercent = constrain(signalPercent, 0, 100);
    String color = "red";
    if (signalPercent > 66) color = "green";
    else if (signalPercent > 33) color = "orange";

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html\\n");
    client.println("<!DOCTYPE html><html><head><meta http-equiv='refresh' content='5'>");
    client.println("<style>.bar{width:100%;background:#ddd}.fill{height:30px;text-align:center;color:white}</style></head><body>");
    client.println("<h2>📶 ESP8266 Wi-Fi Signal Strength Monitor</h2>");
    client.println("<p><b>RSSI:</b> " + String(rssi) + " dBm (" + String(signalPercent) + "%)</p>");
    client.println("<div class='bar'><div class='fill' style='width:" + String(signalPercent) + "%;background:" + color + ";'>" + String(signalPercent) + "%</div></div>");
    client.println("<p><b>Battery (A0):</b> " + String(powerLevel) + " / 1024</p>");
    client.println("<p><b>Last Saved RSSI (EEPROM):</b> " + String(savedRSSI) + " dBm</p>");
    client.println("<p>Page auto-refreshes every 5 seconds.</p>");
    client.println("</body></html>");
    client.stop();
  }
}
