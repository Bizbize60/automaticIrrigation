# ESP32 Tabanlı Otomatik Sulama Sistemi

Bu proje, iki adet ESP32 modülü kullanılarak oluşturulmuş basit bir **otomatik tarım/sulama sistemi**dir. Sistem, toprak nemini izleyip belirli aralıklarla su pompasını kontrol eder.

## 📦 Sistem Bileşenleri

### 1. Gönderici (Transmitter - `WateringSender`)
- Belirli aralıklarla (örneğin 10 dakikada bir) uyanır.
- Nem sensöründen veri alır.
- ESP-NOW protokolü ile bu veriyi alıcı cihaza gönderir.
- Enerji verimliliği için çoğunlukla derin uyku (deep sleep) modundadır.

### 2. Alıcı (Receiver - `WateringReceiver`)
- Gelen veriyi alır.
- Toprak nemini değerlendirir.
- Gerekirse su pompasını kontrol eden röleyi çalıştırır.

## 🔧 Kurulum

1. **PlatformIO** ile her iki projeyi ayrı ayrı ESP32 cihazınıza yükleyin.
2. Her cihaz için doğru portu ve board tipini `platformio.ini` dosyasında belirtin.
3. Röle modülünü ve nem sensörünü uygun pinlere bağlayın.
4. ESP-NOW üzerinden cihazlar birbirine eşleştirilmelidir.

## 💡 Notlar

- Bu sistemde herhangi bir merkezi sunucu kullanılmaz.
- Tüm haberleşme doğrudan ESP-NOW protokolüyle yapılır.
- Enerji tasarrufu için deep sleep aktif olarak kullanılır.

## 🧪 Geliştirme Durumu

- [x] Temel haberleşme çalışıyor  
- [x] Röle kontrolü test edildi  
- [ ] Gelişmiş istatistik ve zamanlama ayarları (gelecek plan)

## 🧾 Lisans

MIT License

