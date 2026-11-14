/*
 * Laporan Praktikum Pemrograman Dasar (INF1053)
 * Modul 9: Functions & Lambda - Test 9.3: Function with Default Value Parameter
 * Nama : Al-Ghani Desta Setyawan
 * NIM  : 2611102441026
 * UMKT - Samarinda
 */

#include <iostream>

using namespace std;

// Fungsi checkEven dengan default parameter value (n = 4)
// Mengembalikan true (1) jika genap, dan false (0) jika ganjil
bool checkEven(int n = 4) {
    return (n % 2 == 0);
}

int main() {
    cout << "=== Test 9.3: Check Even with Default Parameter ===" << endl;

    // 1. Pemanggilan tanpa argumen (menggunakan nilai default n = 4)
    cout << "Call checkEven() without argument (default n = 4):" << endl;
    cout << "Result: " << checkEven() << " (true / 1)" << endl;

    // 2. Pemanggilan dengan argumen eksplisit bilangan genap (n = 10)
    cout << "\nCall checkEven(10):" << endl;
    cout << "Result: " << checkEven(10) << " (true / 1)" << endl;

    // 3. Pemanggilan dengan argumen eksplisit bilangan ganjil (n = 7)
    cout << "\nCall checkEven(7):" << endl;
    cout << "Result: " << checkEven(7) << " (false / 0)" << endl;

    return 0;
}

