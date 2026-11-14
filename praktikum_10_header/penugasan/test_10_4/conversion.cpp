// conversion.cpp
#include <cctype>
#include "conversion.h"

// Mengonversi suhu Celcius ke Fahrenheit: F = (C * 9/5) + 32
float celciusToFahrenheit(float c)
{
    return (c * 9.0f / 5.0f) + 32.0f;
}

// Mengonversi suhu Fahrenheit ke Celcius: C = (F - 32) * 5/9
float fahrenheitToCelcius(float f)
{
    return (f - 32.0f) * 5.0f / 9.0f;
}

// Mengonversi suhu Celcius ke Kelvin: K = C + 273.15
float celciusToKelvin(float c)
{
    return c + 273.15f;
}

// Mengonversi suhu Kelvin ke Celcius: C = K - 273.15
float kelvinToCelcius(float k)
{
    return k - 273.15f;
}

// Mengonversi Fahrenheit ke Kelvin melalui skala Celcius sebagai perantara
float fahrenheitToKelvin(float f)
{
    return celciusToKelvin(fahrenheitToCelcius(f));
}

// Mengonversi Kelvin ke Fahrenheit melalui skala Celcius sebagai perantara
float kelvinToFahrenheit(float k)
{
    return celciusToFahrenheit(kelvinToCelcius(k));
}

// Memeriksa apakah karakter skala (case-insensitive) valid: C, F, atau K
bool isValidScale(char scale)
{
    char s = static_cast<char>(std::toupper(static_cast<unsigned char>(scale)));
    return s == 'C' || s == 'F' || s == 'K';
}

// Mengembalikan label nama skala suhu secara lengkap
std::string getScaleName(char scale)
{
    switch (static_cast<char>(std::toupper(static_cast<unsigned char>(scale)))) {
        case 'C': return "Celcius";
        case 'F': return "Fahrenheit";
        case 'K': return "Kelvin";
        default:  return "Unknown";
    }
}

// Mengonversi suhu dari skala asal (fromScale) ke skala tujuan (toScale) secara fleksibel.
// Langkah 1: Normalisasi input ke Celcius. Langkah 2: Konversi dari Celcius ke skala tujuan.
float convertTemperature(float value, char fromScale, char toScale)
{
    char from = static_cast<char>(std::toupper(static_cast<unsigned char>(fromScale)));
    char to   = static_cast<char>(std::toupper(static_cast<unsigned char>(toScale)));

    if (from == to) return value;

    // Normalisasi ke Celcius terlebih dahulu
    float inCelcius = value;
    if (from == 'F')      inCelcius = fahrenheitToCelcius(value);
    else if (from == 'K') inCelcius = kelvinToCelcius(value);

    // Konversi dari Celcius ke skala target
    if (to == 'F')      return celciusToFahrenheit(inCelcius);
    else if (to == 'K') return celciusToKelvin(inCelcius);
    return inCelcius;
}
