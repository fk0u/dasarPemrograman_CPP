// conversion.h
#ifndef CONVERSION_H
#define CONVERSION_H

#include <string>

// Fungsi konversi dasar sesuai spesifikasi modul
float celciusToFahrenheit(float c); // Mengonversi Celcius ke Fahrenheit
float fahrenheitToCelcius(float f); // Mengonversi Fahrenheit ke Celcius
float celciusToKelvin(float c);     // Mengonversi Celcius ke Kelvin
float kelvinToCelcius(float k);     // Mengonversi Kelvin ke Celcius

// Additional Challenge: Konversi lintas skala secara fleksibel
float fahrenheitToKelvin(float f);  // Mengonversi Fahrenheit ke Kelvin (F -> C -> K)
float kelvinToFahrenheit(float k);  // Mengonversi Kelvin ke Fahrenheit (K -> C -> F)

// Router konversi fleksibel antar skala ('C', 'F', 'K') menggunakan Celcius sebagai pivot
float convertTemperature(float value, char fromScale, char toScale);

// Mengembalikan nama lengkap skala suhu berdasarkan kode karakter ('C', 'F', 'K')
std::string getScaleName(char scale);

// Memvalidasi apakah kode skala suhu dikenali ('C', 'F', atau 'K')
bool isValidScale(char scale);

#endif
