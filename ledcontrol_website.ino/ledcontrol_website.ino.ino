
#include <WiFi.h>
const char* ssid="Galaxy A21sD2C4";
const char* password="hotspot29";
const int ledPin=4;

WiFiServer server(80);

void setup(){
  pinMode(ledPin, OUTPUT); 
  Serial.begin(115200);

  WiFi.begin(ssid,password);
  Serial.println("Wifi is connected");

  while(WiFi.status()!= WL_CONNECTED){
    delay(500);
    Serial.println(".");
  }
  Serial.println("IP Adress:");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  

  WiFiClient client = server.available();
  if(client){
    Serial.println("Client connected");
    while(client.connected()){
      if(client.available()){
        String request = client.readStringUntil('\r');
        Serial.println(request);
        client.read();

        if(request.indexOf("GET /LED=ON") != -1){
          digitalWrite(ledPin,HIGH);
        }
        if(request.indexOf("GET /LED=OFF") !=-1){
          digitalWrite(ledPin,LOW);

        }
        client.println("HTTP/1.1 200 OK");
        client.println("Content-type:text/html");
        client.println();

        client.println("<!DOCTYPE html><html>");
        client.println("<head><title>ESP32 LED ON OFF</title></head>");
        client.println("<body style='text-align:center;'>");
        client.println("<h2>WELCOME TO LED BLINKING WEBSITE</h2>");
        client.println("<p><a href=\"/LED=ON\"><button style='font-size:20px; background-color:green;'>LED ON</button></a></p>");
        client.println("<p><a href=\"/LED=OFF\"><button style='font-size:20px; background-color:red;'>LED OFF</button></a></p>");
        client.println("</body></html>");

        break;

      }
      
    } 
  }
}
 
    


















