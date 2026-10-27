/*
 * Laporan Praktikum Pemrograman Dasar (CSE1053)
 * Modul 8: Set & Map - Test 8.4: Using Functions on Map
 * Nama : Al-Ghani Desta Setyawan
 * NIM  : 2611102441026
 * UMKT - Samarinda
 */

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    // 1. Membuat Map berisi beberapa mahasiswa (nama sebagai key, umur sebagai value)
    map<string, int> students = {
        {"Andi", 20},
        {"Budi", 22},
        {"Citra", 21},
        {"Desta", 20}
    };

    // 2. Menampilkan keys, values, dan key-value pairs menggunakan first dan second
    cout << "=== Students Data (Iterating with .first & .second) ===" << endl;
    for (const auto &s : students) {
        cout << "Key (Name): " << s.first 
             << " | Value (Age): " << s.second << endl;
    }

    // 3. Memeriksa keberadaan key tertentu menggunakan count()
    cout << "\n=== Checking Key Existence using count() ===" << endl;
    string target1 = "Desta";
    string target2 = "Zaki";

    if (students.count(target1)) {
        cout << "'" << target1 << "' is found in the map." << endl;
    } else {
        cout << "'" << target1 << "' is NOT in the map." << endl;
    }

    if (students.count(target2)) {
        cout << "'" << target2 << "' is found in the map." << endl;
    } else {
        cout << "'" << target2 << "' is NOT in the map." << endl;
    }

    // 4. Menghapus seluruh data mahasiswa menggunakan clear()
    cout << "\n--> Clearing all data using clear()..." << endl;
    students.clear();

    // 5. Menampilkan ukuran Map menggunakan size()
    cout << "\n=== Map State After clear() ===" << endl;
    cout << "Map Size : " << students.size() << endl;

    // 6. Memeriksa apakah Map kosong menggunakan empty()
    if (students.empty()) {
        cout << "Map is empty (empty() == true)." << endl;
    } else {
        cout << "The map still contains data." << endl;
    }

    return 0;
}
