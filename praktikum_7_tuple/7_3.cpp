/*
 * Laporan Praktikum Pemrograman Dasar (INF1053)
 * Modul 7: Tuple - Test 7.3: Concatenating Tuples
 * Nama : Al-Ghani Desta Setyawan
 * NIM  : 2611102441026
 * UMKT - Samarinda
 */

#include <iostream>
#include <string>
#include <tuple>

using namespace std;

int main() {
    // 1. Membuat dua tuple berbeda
    // c1 berisi data profil mahasiswa (nama dan umur)
    auto c1 = make_tuple("Al-Ghani Desta Setyawan", 20);
    // c2 berisi data fisik mahasiswa (tinggi dalam cm dan berat dalam kg)
    tuple<int, float> c2(172, 63.5f);

    // 2. Menggabungkan kedua tuple menggunakan tuple_cat()
    auto result = tuple_cat(c1, c2);

    // 3. Menampilkan elemen hasil penggabungan
    cout << "=== Concatenated Student Profile ===" << endl;
    cout << "Name   : " << get<0>(result) << endl;
    cout << "Age    : " << get<1>(result) << " years old" << endl;
    cout << "Height : " << get<2>(result) << " cm" << endl;
    cout << "Weight : " << get<3>(result) << " kg" << endl;

    return 0;
}
