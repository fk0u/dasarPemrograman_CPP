/*
 * Laporan Praktikum Pemrograman Dasar (CSE1053)
 * Modul 8: Set & Map - Test 8.3: Basic Operation on Map
 * Nama : Al-Ghani Desta Setyawan
 * NIM  : 2611102441026
 * UMKT - Samarinda
 */

#include <iostream>
#include <string>
#include <map>

using namespace std;

// Fungsi helper untuk menampilkan isi map
void displayMap(const string &title, const map<string, int> &m) {
    cout << "=== " << title << " ===" << endl;
    for (const auto &pair : m) {
        cout << "  - " << pair.first << " : " << pair.second << " years old" << endl;
    }
}

int main() {
    // 1. Membuat Map berisi data mahasiswa (nama sebagai key, umur sebagai value)
    map<string, int> students = {
        {"Al-Ghani", 20},
        {"Desta", 21},
        {"Baskara", 22}
    };
    displayMap("Initial Student Map", students);

    // 2. Menambahkan data baru menggunakan insert()
    cout << "\n--> Adding new student 'Kara' (Age: 19) using insert()..." << endl;
    students.insert({"Kara", 19});
    displayMap("After Insertion", students);

    // 3. Menghapus data tertentu menggunakan erase()
    cout << "\n--> Removing student 'Baskara' using erase()..." << endl;
    students.erase("Baskara");
    displayMap("After Deletion", students);

    // 4. Mengambil nilai berdasarkan key tertentu menggunakan at()
    cout << "\n=== Value Retrieval using at() ===" << endl;
    cout << "Al-Ghani's Age : " << students.at("Al-Ghani") << " years old" << endl;
    cout << "Kara's Age     : " << students.at("Kara") << " years old" << endl;

    return 0;
}
