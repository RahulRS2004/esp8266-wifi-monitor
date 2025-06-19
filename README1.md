# 📶 ESP8266 Wi-Fi Signal Strength Monitor

A beginner-friendly project to monitor Wi-Fi signal strength using an ESP8266 and display it as a web page with auto-refresh, colored bars, and data logging using EEPROM.

---

## 📦 Components Required
- 1 × ESP8266 NodeMCU board
- USB cable for programming
- Wi-Fi network
- (Optional) Power sensor or voltage divider to A0

---

## 🛠️ How to Set Up

### 🔹 Step 1: Install Arduino IDE
- Download from: https://www.arduino.cc/en/software

### 🔹 Step 2: Install ESP8266 Board Package
1. Open Arduino IDE → Preferences  
2. Paste into "Additional Board Manager URLs":  
http://arduino.esp8266.com/stable/package_esp8266com_index.json

3. Go to Tools > Board > Board Manager → Search `ESP8266` → Install

## Upload the Code

1. Open `esp8266_wifi_monitor.ino` in Arduino IDE  
2. Replace Wi-Fi credentials in the code  
3. Select board: NodeMCU 1.0 (ESP-12E)  
4. Upload the code


## 🌐 View the Webpage

- Open Serial Monitor → get IP Address  
- Open that IP in your phone/PC browser


##  Author  
**Rahul Raghunatha Shettigar**  
ECE | 6th Semester | Pre-Final Year | 🎓 Graduating in 2026
