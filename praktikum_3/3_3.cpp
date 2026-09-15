/*
 * Laporan Praktikum Pemrograman Dasar (INF1053)
 * Modul 3: C++ Basic Data Types - Exercise 3.3
 * Nama : Al-Ghani Desta Setyawan
 * NIM  : 2611102441026
 * UMKT - Samarinda
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    string fullName;

    // Membaca baris teks utuh termasuk karakter spasi
    cout << "Enter your full name: ";
    getline(cin, fullName);

    // 1. Menghitung panjang total karakter string
    size_t nameLength = fullName.length();

    // 2. Mencari posisi indeks kemunculan substring "ani"
    size_t pos = fullName.find("ani");

    // 3. Mengekstraksi nama depan (substring sebelum spasi pertama)
    size_t spacePos = fullName.find(" ");
    string firstName = (spacePos != string::npos) ? fullName.substr(0, spacePos) : fullName;

    // 4. Menggabungkan teks baru di akhir string menggunakan append()
    string appendedName = fullName;
    appendedName.append(" - Student");

    // Menampilkan hasil manipulasi string
    cout << "\n=== Hasil Operasi String ===" << endl;
    cout << "Name length: " << nameLength << endl;
    cout << "Name after appending text: " << appendedName << endl;
    if (pos != string::npos) {
        cout << "Position of the word 'ani' in the name: " << pos << endl;
    } else {
        cout << "Word 'ani' not found in the input." << endl;
    }
    cout << "First name (substring): " << firstName << endl;

    return 0;
}
