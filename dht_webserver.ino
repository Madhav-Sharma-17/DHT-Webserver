#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DHT.h>


const char* ssid = "SSID";
const char* password = "PASSWORD";


#define DHTPIN 2      
#define DHTTYPE DHT22 

DHT dht(DHTPIN, DHTTYPE);
ESP8266WebServer server(80);

void handleRoot() {
  float h = dht.readHumidity();
  float t = dht.readTemperature(); 
  float f = dht.readTemperature(true); 

  if (isnan(h) || isnan(t) || isnan(f)) {
    server.send(200, "text/plain", "Failed to read from DHT sensor!");
    return;
  }

  String html = "<html><body><h1>ESP8266 DHT22 Web Server</h1>";
  html += "<p>Temperature: " + String(t) + " &deg;C</p>";
  html += "<p>Humidity: " + String(h) + " %</p>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);
  delay(10);

  dht.begin();

  // Connect to Wi-Fi
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
