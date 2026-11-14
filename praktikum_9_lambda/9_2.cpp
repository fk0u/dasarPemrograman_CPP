/*
 * Laporan Praktikum Pemrograman Dasar (INF1053)
 * Modul 9: Functions & Lambda - Test 9.2: Function without Return Value
 * Nama : Al-Ghani Desta Setyawan
 * NIM  : 2611102441026
 * UMKT - Samarinda
 */

#include <iostream>
#include <string>

using namespace std;

// Fungsi bertipe void (tanpa nilai kembalian) untuk menampilkan biodata mahasiswa
void biodata() {
    string name = "Al-Ghani Desta Setyawan";
    long long nim = 2611102441026LL;
    int age = 20;
    string course = "Pemrograman Dasar (INF1053)";
    string studyProgram = "S1 Teknik Informatika";

    cout << "========================================" << endl;
    cout << "          BIODATA MAHASISWA             " << endl;
    cout << "========================================" << endl;
    cout << "Nama          : " << name << endl;
    cout << "NIM           : " << nim << endl;
    cout << "Umur          : " << age << " tahun" << endl;
    cout << "Mata Kuliah   : " << course << endl;
    cout << "Program Studi : " << studyProgram << endl;
    cout << "========================================" << endl;
}

int main() {
    // Memanggil fungsi void biodata
    biodata();

    return 0;
}

