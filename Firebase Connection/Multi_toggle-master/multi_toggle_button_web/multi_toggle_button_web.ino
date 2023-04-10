//https://github.com/mobizt/Firebase-ESP8266
//#include <Adafruit_NeoPixel.h>

#if defined(ESP32)
#include <FirebaseESP32.h>
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#endif

#define WIFI_SSID "Mekki" // your wifi SSID
#define WIFI_PASSWORD "25733004A" //your wifi PASSWORD

#define Solenoid 4
#define Buzzer 2
//#define FLASH 4
//#define LedPin 16         // pin d0 as toggle pin
//#define NUM_PIXELS 8      //number of rgb led
//#define PIN_PIXELS 14     //pin d5 as neopixel input  
#define FIREBASE_HOST "safe-home-4e6a1-default-rtdb.firebaseio.com/" // change here
#define FIREBASE_AUTH "UQ4VoO9Z18UJukg1dJMAtDktCksrAqWCGV3zcybD"// change here
FirebaseData firebaseData;

//Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, PIN_PIXELS, NEO_GRB + NEO_KHZ800);
void setup ()
{
  pinMode(Solenoid, OUTPUT);
  pinMode(Buzzer, OUTPUT);
//  pinMode(27, OUTPUT);
//  pixels.begin();
  Serial.begin(9600);
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ") ;
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);     
}
void loop ()
{
  /*
  if(Firebase.getString(firebaseData, "/Led3Status"))
  {
    String ledstatus = firebaseData.stringData();
    if(ledstatus.toInt() == 1){
      Serial.println("on3");
//        pixels.setPixelColor(2, pixels.Color(0, 1, 1));  // #21ecf3 color cyan
//        pixels.show();
    }
    else {
      Serial.println("off3");
//        pixels.setPixelColor(2, pixels.Color(0, 0, 0)); // turn off neopixel
//        pixels.show();
    }
  }
  else{
    Serial.print("Error in getInt, ");
    Serial.println(firebaseData.errorReason());
  } */
  if(Firebase.getString(firebaseData, "settings/test/doorlock")){
    String ledstatus1 = firebaseData.stringData();
    if(ledstatus1.toInt() == 1){
      Serial.println("on Solenoid");
        digitalWrite(Solenoid, HIGH);
    }
    else {
      Serial.println("off Solenoid");
       digitalWrite(Solenoid, LOW);
    }
  }
  if(Firebase.getString(firebaseData, "settings/test/tripping")){
    String ledstatus1 = firebaseData.stringData();
    if(ledstatus1.toInt() == 1){
      Serial.println("on Buzzer");
        digitalWrite(Buzzer, HIGH);
    }
    else {
      Serial.println("off Buzzer");
       digitalWrite(Buzzer, LOW);
    }
  }
  else{
    Serial.print("Error in getInt, ");
    Serial.println(firebaseData.errorReason());
  } /*
  if(Firebase.getString(firebaseData, "/Led2Status")){
    String ledstatus2 = firebaseData.stringData();
    if(ledstatus2.toInt() == 1){
      Serial.println("on2");
//        pixels.setPixelColor(1, pixels.Color(1, 0, 1));  // #f3219c color pink
//        pixels.show();
    }
    else {
      Serial.println("off2");
//        pixels.setPixelColor(1, pixels.Color(0, 0, 0)); // turn off neopixel
//        pixels.show();
    }
  }
  else{
    Serial.print("Error in getInt, ");
    Serial.println(firebaseData.errorReason());
  } 
  if(Firebase.getString(firebaseData, "/Led4Status")){
    String ledstatus3 = firebaseData.stringData();
    if(ledstatus3.toInt() == 1){
      Serial.println("on4");
//        pixels.setPixelColor(3, pixels.Color(0, 1, 0));  // #a3f321 color
//        pixels.show();
    }
    else {
      Serial.println("off4");
//        pixels.setPixelColor(3, pixels.Color(0, 0, 0)); // turn off neopixel
//        pixels.show();
    }
  }
  else{
    Serial.print("Error in getInt, ");
    Serial.println(firebaseData.errorReason());
  } */
//  digitalWrite(27, HIGH);
//  delay(1000);
//  digitalWrite(27, LOW);
}
