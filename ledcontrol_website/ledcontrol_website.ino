#include <WiFi.h>

String selectedSSID = "";
String password ="";

void setup(){
  Serial.begin(115200);
  delay(1000);
  Serial.println("Scanning for Wi-Fi networks");

  WiFi.mode(WIFI_STA); //Set wifi mode to station.
  WiFi.disconnect();   //Disconnect to any previous network
  delay(100);

  int n =WiFi.scanNetworks(); //Scan for network n returns number of networks
  
  //List all network available:
  if (n==0){
    Serial.println("No network found");
  }
  else{
    Serial.println("Networks found:");
    for (int i=0;i<n;i++){
      Serial.print(i+1); //Print serai number 1,2,3
      Serial.print(":");
      Serial.print(WiFi.SSID(i));//Network name

      Serial.print("(Siganl:");
      Serial.print(WiFi.RSSI(i));//Netword strength
      Serial.print("dBm)");

      Serial.println();
      delay(10);
    }

    Serial.print("Enter network number to connect:");
    while(Serial.available()==0){}  ///waits until something is types in serial monitor
    int choice =Serial.parseInt(); //Gets SSID of selecetd number
    selectedSSID = WiFi.SSID(choice-1); //prints the network name that is selected

    Serial.println("Enter password:");
    while (Serial.available())Serial.read(); // clears input

    while(Serial.available()==0){} // Waits while user type something
    password=Serial.readStringUntil('\n');
    password.trim(); //remove extra spaces

    Serial.print("Connecting to ");
    Serial.print(selectedSSID);
    Serial.print("....");

    WiFi.begin(selectedSSID.c_str(),password.c_str());

    int retry = 0;
    while(WiFi.status()!=WL_CONNECTED && retry<5){ //we are trying to connect 10 times to the network
      delay(500);
      Serial.print(".");
      retry++;
    }

    if (WiFi.status()==WL_CONNECTED){
      Serial.println("Connected!!");
      Serial.print("IP ADDRESS:");
      Serial.print(WiFi.localIP());
    }
    else{
      Serial.println("Connection Failed!");
      Serial.println("Check the password and try again");
    }


  } 
     
     
}

void loop(){

}
