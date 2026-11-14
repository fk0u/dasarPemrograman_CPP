/*
 * Laporan Praktikum Pemrograman Dasar (INF1053)
 * Modul 9: Functions & Lambda - Test 9.7: Individual Task (Recursion as Loop)
 * Studi Kasus: Countdown dan Peluncuran Roket (Rocket Launch Countdown)
 * Nama : Al-Ghani Desta Setyawan
 * NIM  : 2611102441026
 * UMKT - Samarinda
 */

#include <iostream>

using namespace std;

// Fungsi rekursif untuk mendemonstrasikan perulangan mundur tanpa loop statement (for/while)
void countdown(int n) {
    // Base Case: Kondisi berhenti saat hitungan mencapai 0
    if (n <= 0) {
        cout << "[T-0] Liftoff! Roket berhasil diluncurkan ke luar angkasa!" << endl;
        return;
    }

    // Aksi pada setiap iterasi rekursif
    cout << "[T-" << n << "] Hitung mundur menuju peluncuran..." << endl;

    // Recursive Call: Memanggil dirinya sendiri dengan nilai n yang didekrementasikan (n - 1)
    countdown(n - 1);
}

int main() {
    int startSeconds = 5;

    cout << "========================================" << endl;
    cout << "    SIMULASI HITUNG MUNDUR ROKET        " << endl;
    cout << "     (REKURSI TANPA FOR / WHILE)        " << endl;
    cout << "========================================" << endl;

    // Memulai rekursi hitung mundur dari startSeconds
    countdown(startSeconds);

    cout << "========================================" << endl;

    return 0;
}

