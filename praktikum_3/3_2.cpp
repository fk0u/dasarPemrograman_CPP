/*
 * Laporan Praktikum Pemrograman Dasar (INF1053)
 * Modul 3: C++ Basic Data Types - Exercise 3.2
 * Nama : Al-Ghani Desta Setyawan
 * NIM  : 2611102441026
 * UMKT - Samarinda
 */

#include <iostream>
#include <cmath> // Diperlukan untuk pow(), fabs(), round()

using namespace std;

int main() {
    double num1, num2;

    // Inisialisasi dan pembacaan input floating-point dinamis
    cout << "Enter the first number: ";
    if (!(cin >> num1)) {
        cerr << "Error: Input pertama tidak valid!" << endl;
        return 1;
    }

    cout << "Enter the second number: ";
    if (!(cin >> num2)) {
        cerr << "Error: Input kedua tidak valid!" << endl;
        return 1;
    }

    // 1. Perpangkatan: num1 ^ num2
    double powerResult = pow(num1, num2);

    // 2. Nilai absolut dari -num1 menggunakan fabs()
    double absoluteValue = fabs(-num1);

    // 3. Pembulatan num2 ke bilangan bulat terdekat
    double roundNumber = round(num2);

    // Menampilkan hasil format
    cout << "\n=== Hasil Fungsi <cmath> ===" << endl;
    cout << "Power Result: " << powerResult << endl;
    cout << "Absolute Value: " << absoluteValue << endl;
    cout << "Rounded Value: " << roundNumber << endl;

    return 0;
}
