/*
 * Laporan Praktikum Pemrograman Dasar (INF1053)
 * Modul 7: Tuple - Test 7.1: Basic Operation on Tuples
 * Nama : Al-Ghani Desta Setyawan
 * NIM  : 2611102441026
 * UMKT - Samarinda
 */

#include <iostream>
#include <string>
#include <tuple>

using namespace std;

int main() {
    // Membuat tuple yang berisi nama mahasiswa (string) dan NIM (long long)
    tuple<string, long long> student("Al-Ghani Desta Setyawan", 2611102441026LL);

    // Menampilkan nama dan NIM menggunakan get<>
    cout << "Name       : " << get<0>(student) << endl;
    cout << "Student ID : " << get<1>(student) << endl;

    // Menemukan dan menampilkan ukuran tuple menggunakan tuple_size
    cout << "Tuple Size : " << tuple_size<decltype(student)>::value << endl;

    return 0;
}
