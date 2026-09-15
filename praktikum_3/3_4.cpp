/*
 * Laporan Praktikum Pemrograman Dasar (INF1053)
 * Modul 3: C++ Basic Data Types - Exercise 3.4
 * Nama : Al-Ghani Desta Setyawan
 * NIM  : 2611102441026
 * UMKT - Samarinda
 */

#include <iostream>
#include <string>
#include <typeinfo> // Diperlukan untuk operator typeid

using namespace std;

int main() {
    // 1. Input bilangan real bertipe float
    float num;
    cout << "Enter a number (float): ";
    if (!(cin >> num)) {
        cerr << "Error: Input float tidak valid!" << endl;
        return 1;
    }

    // 2. Menampilkan identifier tipe data sebelum konversi
    cout << "\n=== Informasi Tipe Data & Casting ===" << endl;
    cout << "Real num data type: " << typeid(num).name() << endl;

    // 3. Explicit casting: float ke int (truncation)
    // Standar modern C++: static_cast<int>(num)
    int numInt = static_cast<int>(num);

    // 4. Implicit casting: float ke double (precision widening)
    double numDouble = num;

    // 5. Menampilkan tipe data setelah konversi
    cout << "Num data type after casting to int: " << typeid(numInt).name() << endl;
    cout << "Num data type after casting to double: " << typeid(numDouble).name() << endl;

    cout << "\nNilai setelah konversi:" << endl;
    cout << "Nilai int (truncated): " << numInt << endl;
    cout << "Nilai double: " << numDouble << endl;

    return 0;
}
