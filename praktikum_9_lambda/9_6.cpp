/*
 * Laporan Praktikum Pemrograman Dasar (INF1053)
 * Modul 9: Functions & Lambda - Test 9.6: Lambda Exercise II (Capture Clause)
 * Nama : Al-Ghani Desta Setyawan
 * NIM  : 2611102441026
 * UMKT - Samarinda
 */

#include <iostream>

using namespace std;

int main() {
    // Variabel luar (outer scope)
    int a = 10, b = 5;

    // Perbaikan: Menambahkan [a, b] atau [&] / [=] pada capture clause
    // agar variabel 'a' dan 'b' dapat diakses dari dalam blok lambda
    auto addition = [a, b](int x, int y) {
        cout << "Capture:   " << a + b << endl;
        cout << "Parameter: " << x + y << endl;
    };

    cout << "=== Test 9.6: Lambda Capture vs Parameter ===" << endl;
    addition(10, 24);

    return 0;
}

