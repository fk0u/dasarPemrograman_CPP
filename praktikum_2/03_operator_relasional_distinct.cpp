//
//  03_operator_relasional_distinct.cpp
//  dasarPemrograman_CPP - Praktikum 2
//
//  Topik: Operator Relasional (Perbandingan) & Pemeriksaan Nilai Unik (Distinct Values)
//  Created by Al-Ghani Desta Setyawan
//

#include <iostream>

using namespace std;

int main() {
    cout << "====================================================\n";
    cout << "   03. OPERATOR RELASIONAL & DISTINCT VALUES        \n";
    cout << "====================================================\n\n";

    int p = 15;
    int q = 15;
    int r = 25;

    cout << "Nilai: p = " << p << ", q = " << q << ", r = " << r << "\n\n";

    // 1. Evaluasi Operator Relasional (Menghasilkan Boolean 1 atau 0)
    cout << "--- Operator Perbandingan Standar ---\n";
    cout << "Sama dengan (p == q)           : " << (p == q ? "True (1)" : "False (0)") << "\n";
    cout << "Tidak sama dengan (p != r)     : " << (p != r ? "True (1)" : "False (0)") << "\n";
    cout << "Lebih besar (r > p)            : " << (r > p  ? "True (1)" : "False (0)") << "\n";
    cout << "Lebih kecil (p < r)            : " << (p < r  ? "True (1)" : "False (0)") << "\n";
    cout << "Lebih besar sama dengan (p >= q): " << (p >= q ? "True (1)" : "False (0)") << "\n";
    cout << "Lebih kecil sama dengan (q <= r): " << (q <= r ? "True (1)" : "False (0)") << "\n\n";

    // 2. Pemeriksaan Nilai Unik / Distinct Values
    // Nilai dikatakan DISTINCT jika tidak ada sepasang pun variabel yang bernilai sama
    cout << "--- Pemeriksaan Distinct Values (Keunikan Nilai) ---\n";
    bool isAllDistinct = (p != q) && (q != r) && (p != r);
    cout << "Apakah p, q, r bernilai DISTINCT (semuanya berbeda)? : "
         << (isAllDistinct ? "Ya, semua nilai distinct/berbeda" 
                           : "Tidak, ada nilai yang kembar (p == q)") << "\n\n";

    // 3. Studi Kasus: Klasifikasi Segitiga Berdasarkan Keunikan Sisi (Distinct Sides)
    cout << "--- Studi Kasus: Klasifikasi Segitiga (Distinct Sides) ---\n";
    int sisiA = 7;
    int sisiB = 10;
    int sisiC = 12;

    cout << "Panjang Sisi: A = " << sisiA << ", B = " << sisiB << ", C = " << sisiC << "\n";

    bool semuaSisiDistinct = (sisiA != sisiB) && (sisiB != sisiC) && (sisiA != sisiC);
    bool semuaSisiSama     = (sisiA == sisiB) && (sisiB == sisiC);

    if (semuaSisiSama) {
        cout << "Tipe Segitiga: Segitiga Sama Sisi (Equilateral - 0 sisi distinct)\n";
    } else if (semuaSisiDistinct) {
        cout << "Tipe Segitiga: Segitiga Sembarang (Scalene - Ketiga sisi DISTINCT / berbeda)\n";
    } else {
        cout << "Tipe Segitiga: Segitiga Sama Kaki (Isosceles - 2 sisi sama)\n";
    }

    cout << "====================================================\n";
    return 0;
}
