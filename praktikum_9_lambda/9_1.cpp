/*
 * Laporan Praktikum Pemrograman Dasar (INF1053)
 * Modul 9: Functions & Lambda - Test 9.1: Cube Volume Function
 * Nama : Al-Ghani Desta Setyawan
 * NIM  : 2611102441026
 * UMKT - Samarinda
 */

#include <iostream>

using namespace std;

// Fungsi untuk menghitung volume kubus berdasarkan panjang sisi (s)
// Format yang benar: mengembalikan hasil perhitungan menggunakan return statement
int cubeVolume(int s) {
    return s * s * s;
}

int main() {
    int side = 5;
    int volume = cubeVolume(side);

    cout << "=== Test 9.1: Cube Volume Calculation ===" << endl;
    cout << "Side length (s) : " << side << " cm" << endl;
    cout << "Cube Volume (v) : " << volume << " cm^3" << endl;

    // Pengujian tambahan dengan input nilai lain
    cout << "Volume of cube (s = 3) : " << cubeVolume(3) << " cm^3" << endl;
    cout << "Volume of cube (s = 8) : " << cubeVolume(8) << " cm^3" << endl;

    return 0;
}

