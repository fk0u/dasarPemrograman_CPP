/*
 * Laporan Praktikum Pemrograman Dasar (CSE1053)
 * Modul 8: Set & Map - Test 8.2: Advance Operation on Set
 * Nama : Al-Ghani Desta Setyawan
 * NIM  : 2611102441026
 * UMKT - Samarinda
 */

#include <iostream>
#include <set>

using namespace std;

// Fungsi helper untuk mengecek status kekosongan set
void checkEmpty(const string &name, const set<int> &s) {
    if (s.empty()) {
        cout << name << " is empty (empty() == true)" << endl;
    } else {
        cout << name << " is NOT empty (contains " << s.size() << " elements)" << endl;
    }
}

int main() {
    // 1. Membuat dua Set yang berisi angka
    set<int> set1 = {10, 25, 40, 55};
    set<int> set2 = {12, 34, 48, 60, 72};

    // 2. Menampilkan ukuran dari masing-masing Set menggunakan size()
    cout << "=== Set Sizes ===" << endl;
    cout << "Set1 Size : " << set1.size() << " elements" << endl;
    cout << "Set2 Size : " << set2.size() << " elements" << endl;

    // 3. Menghapus seluruh elemen dari salah satu Set (set1) menggunakan clear()
    cout << "\n--> Clearing all elements from Set1..." << endl;
    set1.clear();

    // 4. Memeriksa apakah Set kosong menggunakan empty()
    cout << "\n=== Checking Empty Status ===" << endl;
    checkEmpty("Set1", set1);
    checkEmpty("Set2", set2);

    return 0;
}
