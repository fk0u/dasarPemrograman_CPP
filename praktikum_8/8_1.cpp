/*
 * Laporan Praktikum Pemrograman Dasar (CSE1053)
 * Modul 8: Set & Map - Test 8.1: Basic Operation on Set
 * Nama : Al-Ghani Desta Setyawan
 * NIM  : 2611102441026
 * UMKT - Samarinda
 */

#include <iostream>
#include <string>
#include <set>

using namespace std;

// Fungsi helper untuk menampilkan seluruh elemen di dalam set
void displaySet(const string &label, const set<string> &s) {
    cout << label << ": [ ";
    for (const string &item : s) {
        cout << item << " ";
    }
    cout << "]" << endl;
}

int main() {
    // 1. Membuat Set berisi jenis-jenis buah
    set<string> fruits = {"Apple", "Banana", "Orange", "Watermelon"};
    displaySet("Initial Fruits Set", fruits);

    // 2. Menambahkan buah baru menggunakan insert()
    cout << "\n--> Inserting 'Mango'..." << endl;
    fruits.insert("Mango");
    displaySet("After insert('Mango')", fruits);

    // 3. Menghapus buah menggunakan erase()
    cout << "\n--> Erasing 'Banana'..." << endl;
    fruits.erase("Banana");
    displaySet("After erase('Banana')", fruits);

    return 0;
}
