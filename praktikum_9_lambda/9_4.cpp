/*
 * Laporan Praktikum Pemrograman Dasar (INF1053)
 * Modul 9: Functions & Lambda - Test 9.4: Prototype Function
 * Nama : Al-Ghani Desta Setyawan
 * NIM  : 2611102441026
 * UMKT - Samarinda
 */

#include <iostream>

using namespace std;

// 1. Function Prototype (Deklarasi Fungsi di atas main)
// Memberitahukan compiler mengenai nama fungsi, tipe kembalian, dan tipe parameternya
int cubeVolume(int s);

int main() {
    int side1 = 4;
    int side2 = 6;

    cout << "=== Test 9.4: Cube Volume using Prototype Function ===" << endl;
    cout << "Volume of cube (s = " << side1 << ") : " << cubeVolume(side1) << " cm^3" << endl;
    cout << "Volume of cube (s = " << side2 << ") : " << cubeVolume(side2) << " cm^3" << endl;

    return 0;
}

// 2. Function Definition (Definisi/Implementasi Fungsi di bawah main)
int cubeVolume(int s) {
    return s * s * s;
}

