// main.cpp
#include <iostream>
#include <iomanip>
#include <cctype>
#include "conversion.h" // Mengimpor seluruh deklarasi fungsi konversi suhu

using namespace std;

int main()
{
    float temperature;
    char fromScale, toScale;

    cout << "=== Flexible Temperature Converter ===" << endl;
    cout << "Enter Temperature        : ";
    cin >> temperature;

    cout << "Source Scale (C / F / K) : ";
    cin >> fromScale;

    cout << "Target Scale (C / F / K) : ";
    cin >> toScale;

    // Validasi skala input sebelum diproses
    if (!isValidScale(fromScale) || !isValidScale(toScale)) {
        cout << "[Error] Invalid scale! Please use C, F, or K." << endl;
        return 1;
    }

    float result = convertTemperature(temperature, fromScale, toScale);
    char toUpper = static_cast<char>(toupper(static_cast<unsigned char>(toScale)));

    cout << fixed << setprecision(2);
    cout << "--------------------------------------" << endl;
    cout << "Conversion : " << getScaleName(fromScale)
         << " -> " << getScaleName(toScale) << endl;
    cout << "Result     : " << result << " " << toUpper << endl;
    cout << "--------------------------------------" << endl;

    return 0;
}
