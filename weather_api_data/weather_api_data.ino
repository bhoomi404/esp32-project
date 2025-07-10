#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid ="Galaxy A21sD2C4";
const char* password = "hotspot29";
const char* apiKey="0015a7f43ae70c66161e7c217a1e8105";
String city = "";
bool cityEntered = false;

void setup() {
  Serial.begin(115200);
  delay(1000);

  WiFi.begin(ssid,password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("/nConnected");
  Serial.println("Enter city name to get weather forcast:");

}

void getWeather() {
  if (WiFi.status()==WL_CONNECTED){
    HTTPClient http;
    
    String url = "http://api.openweathermap.org/data/2.5/weather?q=" + 
             city + "&appid=" + 
             apiKey + "&units=metric";

    Serial.println("/n Sending request to:");
    Serial.println(url);
    http.begin(url);

    int httpCode = http.GET(); // Send HTTP GET request

    if (httpCode > 0){
      String payload = http.getString(); //Getting response
      Serial.print("Weather Data(RAW):");
      Serial.println(payload);
    
    const size_t capacity =1024;
    DynamicJsonDocument doc(capacity); //creates a dynamic document to hold and pasrse json data
    DeserializationError error = deserializeJson(doc,payload); //deserializeJson() parses json 
    //DeserializationError has object error,.f_str() is a function that returns error as human readable string.
    if(error){
      Serial.print("JSON PARSE FAILED:");
      Serial.println(error.f_str());
      return;
       }

    //climate data
    float temp = doc["main"]["temp"];
    int hum = doc["main"]["humidity"];
    String weatherDescription=doc["weather"][0]["description"];
    String cityname = doc["name"];
    int pressure = doc["main"]["pressure"];

    Serial.println("WEATHER INFORMATION");
    Serial.print("City:");
    Serial.println(city);
    Serial.print("Temperature:");
    Serial.println(temp);
    Serial.print("Humidity:");
    Serial.println(hum);
    Serial.print("Condition:");
    Serial.println(weatherDescription);
    Serial.print("Pressure:");
    Serial.println(pressure);
    }
    
    else{
      Serial.println("Error on HTTP request");
      Serial.println(httpCode);
    }
    http.end();
  }
}

void loop(){
  if (Serial.available() && !cityEntered) {
    city = Serial.readStringUntil('\n');
    city.trim();  // remove newline and spaces

    if (city.length() > 0) {
      cityEntered=true;
      getWeather();
      Serial.println("\nYou can enter another city:");
      cityEntered=false;
    }
  }

}


