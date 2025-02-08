DHT22 Web Server

Overview

The DHT22 Web Server project is an ESP32-based system that reads temperature and humidity data from a DHT22 sensor and serves it over a web interface. The ESP32 hosts a simple webpage that displays real-time sensor readings.

Components

ESP32 microcontroller

DHT22 temperature and humidity sensor

Resistors and jumper wires

Circuit Diagram

Ensure the components are wired as follows:

DHT22 Data pin → ESP32 GPIO (configured in code)

VCC → 3.3V or 5V

GND → GND

Installation

Install the Arduino IDE and ESP32 board support.

Install the DHT and Adafruit_Sensor libraries from the Arduino Library Manager.

Connect the ESP32 via USB and upload the dht22_webserver.ino code.

Find the ESP32's IP address from the Serial Monitor and access the web interface.

Usage

The web server provides real-time temperature and humidity data.

Open a browser and enter the ESP32's IP address to view the readings.

Notes

Ensure a stable power supply to the ESP32.

Place the DHT22 sensor in a well-ventilated area for accurate readings.

Future Improvements

Add a graph to visualize temperature and humidity trends.

Enable data logging and cloud integration.
