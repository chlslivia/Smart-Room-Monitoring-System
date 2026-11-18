
#include "DHT.h"

// =================================
// KONFIGURASI PIN
// =================================

#define DHTPIN 4
#define DHTTYPE DHT22
#define LDRPIN 2

// Membuat objek DHT22
DHT dht(DHTPIN, DHTTYPE);

// =================================
// SETUP
// =================================

void setup() {

  Serial.begin(115200);

  // Memulai sensor DHT22
  dht.begin();

  // Mengatur pin LDR sebagai input
  pinMode(LDRPIN, INPUT);

  Serial.println("==================================");
  Serial.println("    SMART ROOM MONITORING SYSTEM");
  Serial.println("==================================");

  delay(2000);
}

// =================================
// LOOP
// =================================

void loop() {

  // Membaca suhu
  float suhu = dht.readTemperature();

  // Membaca kelembapan
  float kelembapan = dht.readHumidity();

  // Membaca nilai digital LDR
  int nilaiLDR = digitalRead(LDRPIN);

  Serial.println();
  Serial.println("========== DATA SENSOR ==========");

  // Menampilkan suhu
  if (isnan(suhu)) {
    Serial.println("Suhu: Gagal membaca sensor");
  } else {
    Serial.print("Suhu: ");
    Serial.print(suhu);
    Serial.println(" C");
  }

  // Menampilkan kelembapan
  if (isnan(kelembapan)) {
    Serial.println("Kelembapan: Gagal membaca sensor");
  } else {
    Serial.print("Kelembapan: ");
    Serial.print(kelembapan);
    Serial.println(" %");
  }

  // Menampilkan nilai LDR dalam angka
  Serial.print("Nilai LDR: ");
  Serial.println(nilaiLDR);

  Serial.println("=================================");

  delay(2000);
}
