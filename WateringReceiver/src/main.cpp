#include <esp_now.h>
#include <WiFi.h>
#include <esp_wifi.h>
#include <Arduino.h>
int average =0;
const int maxCount = 6;
int currentIndex = 0;
unsigned long lastReceivedTime = millis();
bool dataReceived = false;
int sensorValues[maxCount];
// This is the callback function using the older ESP-NOW API
void OnDataRecv(const uint8_t *mac_addr, const uint8_t *data, int data_len) {
  lastReceivedTime = millis();
  dataReceived = true;
  if(currentIndex<maxCount){
    sensorValues[currentIndex]=*data;
    currentIndex++;

  }
  else{
    currentIndex = 0;
    for(int i=0;i<6;i++){
    average += sensorValues[i];
  }
  average=average/6;
  if(average <= 75){
    digitalWrite(33,HIGH);
    delay(15000);

  }
  }
  Serial.println(*data);
  
}

void setup() {
  pinMode(33,OUTPUT);
  WiFi.mode(WIFI_STA);
  Serial.begin(9600);
  esp_wifi_set_channel(1, WIFI_SECOND_CHAN_NONE);
  
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Register callback function
  esp_now_register_recv_cb(OnDataRecv);
}

void loop() {
  // Your main loop code here
}