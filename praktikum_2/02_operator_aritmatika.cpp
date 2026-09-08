//
//  02_operator_aritmatika.cpp
//  dasarPemrograman_CPP - Praktikum 2
//
//  Topik: Operator Aritmatika (+, -, *, /, %), Type Casting,
//         dan Increment/Decrement (Pre & Post)
//  Created by Al-Ghani Desta Setyawan
//

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << "====================================================\n";
    cout << "          02. OPERATOR ARITMATIKA & CASTING         \n";
    cout << "====================================================\n\n";

    int bil1 = 20;
    int bil2 = 6;

    cout << "Nilai bil1 = " << bil1 << ", bil2 = " << bil2 << "\n\n";

    // 1. Operasi Aritmatika Dasar
    cout << "--- Operasi Dasar ---\n";
    cout << "Penjumlahan (bil1 + bil2)        : " << (bil1 + bil2) << "\n";
    cout << "Pengurangan (bil1 - bil2)        : " << (bil1 - bil2) << "\n";
    cout << "Perkalian   (bil1 * bil2)        : " << (bil1 * bil2) << "\n";
    cout << "Pembagian bulat (bil1 / bil2)    : " << (bil1 / bil2) << " (truncation / pemotongan int)\n";
    cout << "Sisa bagi / Modulo (bil1 % bil2) : " << (bil1 % bil2) << "\n\n";

    // 2. Type Casting Eksplisit untuk Pembagian Desimal
    cout << "--- Type Casting Presisi Desimal ---\n";
    double hasilBagiDesimal = static_cast<double>(bil1) / bil2;
    cout << fixed << setprecision(3);
    cout << "Pembagian presisi (static_cast<double>) : " << hasilBagiDesimal << "\n\n";

    // 3. Operator Increment & Decrement (Pre vs Post)
    cout << "--- Increment & Decrement ---\n";
    int n = 5;
    cout << "Nilai awal n           : " << n << "\n";
    cout << "n++ (post-increment)   : " << n++ << " -> Nilai ditampilkan dulu, lalu n bertambah\n";
    cout << "Nilai n sekarang       : " << n << "\n";
    cout << "++n (pre-increment)    : " << ++n << " -> Nilai n ditambah dulu, lalu ditampilkan\n";
    cout << "n-- (post-decrement)   : " << n-- << "\n";
    cout << "--n (pre-decrement)    : " << --n << "\n\n";

    // 4. Studi Kasus Geometri: Luas dan Keliling Lingkaran
    cout << "--- Studi Kasus: Menghitung Geometri Lingkaran ---\n";
    const double PI = 3.14159265;
    double jariJari = 7.0;

    double luasLingkaran = PI * jariJari * jariJari;
    double kelilingLingkaran = 2 * PI * jariJari;

    cout << "Jari-jari (r)          : " << jariJari << " cm\n";
    cout << "Luas Lingkaran (π*r²)  : " << luasLingkaran << " cm²\n";
    cout << "Keliling (2*π*r)       : " << kelilingLingkaran << " cm\n";
    cout << "====================================================\n";

    return 0;
}
