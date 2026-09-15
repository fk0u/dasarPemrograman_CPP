/*
 * Laporan Praktikum Pemrograman Dasar (INF1053)
 * Modul 3: C++ Basic Data Types - Exercise 3.1
 * Nama : Al-Ghani Desta Setyawan
 * NIM  : 2611102441026
 * UMKT - Samarinda
 */

#include <iostream>
#include <cmath> // Diperlukan untuk std::max, std::min, std::round

using namespace std;

int main() {
    // 1. Inisialisasi variabel dan input pengguna
    int num1;
    int num2;

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

    // 2. Operasi aritmatika dasar
    int addition = num1 + num2;
    int subtraction = num1 - num2;
    int multiplication = num1 * num2;
    
    // Explicit type casting untuk mencegah integer division truncation
    // Menggunakan static_cast<double> yang merupakan standar modern C++
    double division = (num2 != 0) ? (static_cast<double>(num1) / num2) : 0.0;
    int modulus = (num2 != 0) ? (num1 % num2) : 0;

    // 3. Operasi menggunakan header <cmath> dan algoritma standar
    int maximum = max(num1, num2);
    int minimum = min(num1, num2);
    double rounded_division = round(division);

    // 4. Menampilkan hasil kalkulasi
    cout << "\n=== Hasil Perhitungan ===" << endl;
    cout << "Addition Result: " << addition << endl;
    cout << "Subtraction Result: " << subtraction << endl;
    cout << "Multiplication Result: " << multiplication << endl;
    
    if (num2 != 0) {
        cout << "Division Result: " << division << endl;
        cout << "Modulus Result: " << modulus << endl;
        cout << "Rounded Division: " << rounded_division << endl;
    } else {
        cout << "Division Result: Undefined (Division by Zero)" << endl;
        cout << "Modulus Result: Undefined (Modulo by Zero)" << endl;
        cout << "Rounded Division: Undefined" << endl;
    }

    cout << "Maximum Number: " << maximum << endl;
    cout << "Minimum Number: " << minimum << endl;

    return 0;
}
