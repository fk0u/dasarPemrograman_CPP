/*
 * Laporan Praktikum Pemrograman Dasar (INF1053)
 * Modul 7: Tuple - Test 7.2: Tuple Packing and Unpacking
 * Nama : Al-Ghani Desta Setyawan
 * NIM  : 2611102441026
 * UMKT - Samarinda
 */

#include <iostream>
#include <string>
#include <tuple>

using namespace std;

int main() {
    // 1. Tuple packing menggunakan make_tuple()
    auto student_data = make_tuple("Al-Ghani Desta Setyawan", 20);

    // 2. Deklarasi variabel penampung untuk unpacking
    string name;
    int age;

    // 3. Unpacking tuple menggunakan tie()
    tie(name, age) = student_data;

    // 4. Menampilkan hasil unpacking
    cout << "=== Student Data (Unpacked) ===" << endl;
    cout << "Name : " << name << endl;
    cout << "Age  : " << age << " years old" << endl;

    return 0;
}
