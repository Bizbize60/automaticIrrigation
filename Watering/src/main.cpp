#include <Arduino.h>
#include <esp_now.h>
#include <WiFi.h>
#include <sensor.hpp>
#include <esp_sleep.h>

esp_now_peer_info_t slave;
uint8_t humidityPercantage = 0;
time_t now;
void wasSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.println("Gönderim tamamlandı, deep sleep'e geçiliyor...");
  esp_deep_sleep_start();  
}

void setup() {
  time(&now);
  
  Serial.begin(115200);
  delay(100);  
  Serial.println(ctime(&now));

  WiFi.mode(WIFI_STA);
  esp_sleep_enable_timer_wakeup(10 * 60 *1000000ULL);  // 10 dakika 

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW başlatılamadı!");
    return;
  }

  initSensor();

  uint8_t receiverMac[] = {0xD0, 0xEF, 0x76, 0x4C, 0xD5, 0x68};
  memcpy(slave.peer_addr, receiverMac, 6);
  slave.channel = 1;

  if (!esp_now_is_peer_exist(slave.peer_addr)) {
    if (esp_now_add_peer(&slave) != ESP_OK) {
      Serial.println("Peer eklenemedi!");
      return;
    }
  }

  esp_now_register_send_cb(wasSent);

  humidityPercantage = readSensor();
  esp_now_send(slave.peer_addr, &humidityPercantage, sizeof(humidityPercantage));
  delay(1000);
}

void loop() {
  
}
