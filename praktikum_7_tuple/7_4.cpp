/*
 * Laporan Praktikum Pemrograman Dasar (INF1053)
 * Modul 7: Tuple - Test 7.4: Swapping Tuples
 * Nama : Al-Ghani Desta Setyawan
 * NIM  : 2611102441026
 * UMKT - Samarinda
 */

#include <iostream>
#include <string>
#include <tuple>

using namespace std;

int main() {
    // 1. Membuat dua tuple dengan jumlah dan tipe data elemen yang persis sama
    tuple<string, int> person1("Al-Ghani", 20);
    tuple<string, int> person2("Desta", 22);

    // 2. Menampilkan elemen kedua tuple sebelum pertukaran (swap)
    cout << "=== Before Swap ===" << endl;
    cout << "Person 1 -> Name: " << get<0>(person1)
         << ", Age: " << get<1>(person1) << endl;
    cout << "Person 2 -> Name: " << get<0>(person2)
         << ", Age: " << get<1>(person2) << endl;

    // 3. Menggunakan fungsi swap() untuk menukar isi kedua tuple
    person1.swap(person2);

    // 4. Menampilkan elemen kedua tuple setelah pertukaran (swap)
    cout << "\n=== After Swap ===" << endl;
    cout << "Person 1 -> Name: " << get<0>(person1)
         << ", Age: " << get<1>(person1) << endl;
    cout << "Person 2 -> Name: " << get<0>(person2)
         << ", Age: " << get<1>(person2) << endl;

    return 0;
}
