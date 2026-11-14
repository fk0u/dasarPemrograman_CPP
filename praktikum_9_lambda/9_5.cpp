/*
 * Laporan Praktikum Pemrograman Dasar (INF1053)
 * Modul 9: Functions & Lambda - Test 9.5: Lambda Exercise I
 * Nama : Al-Ghani Desta Setyawan
 * NIM  : 2611102441026
 * UMKT - Samarinda
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    // Definisi fungsi lambda yang menerima dua parameter x dan y
    // Rumus: (x + y) * 2
    auto count = [](int x, int y) {
        return (x + y) * 2;
    };

    cout << "=== Test 9.5: Lambda Function (x + y) * 2 ===" << endl;
    cout << "count(10, 2) = " << count(10, 2) << endl;

    // Uji coba tambahan dengan variasi nilai parameter
    cout << "count(5, 3)  = " << count(5, 3) << endl;
    cout << "count(7, 8)  = " << count(7, 8) << endl;

    return 0;
}

