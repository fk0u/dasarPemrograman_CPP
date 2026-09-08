//
//  main.cpp
//  dasarPemrograman_CPP - Praktikum 2
//
//  Menu Utama / Hub Praktikum 2: Tipe Data, Variabel, dan Operator
//  Created by Al-Ghani Desta Setyawan
//

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void demoVariabelDanTipeData() {
    cout << "\n====================================================\n";
    cout << "  01. IMPLEMENTASI VARIABEL & TIPE DATA (DISTINCT)  \n";
    cout << "====================================================\n";
    string nama = "Al-Ghani Desta Setyawan";
    int umur = 19;
    char golonganDarah = 'O';
    float beratBadan = 65.5f;
    double tinggiBadan = 172.85;
    bool isMahasiswaAktif = true;
    const double PI = 3.14159265;

    cout << "Nama           : " << nama << " (sizeof: " << sizeof(string) << " byte)\n";
    cout << "Umur           : " << umur << " tahun (sizeof: " << sizeof(int) << " byte)\n";
    cout << "Golongan Darah : " << golonganDarah << " (sizeof: " << sizeof(char) << " byte)\n";
    cout << "Berat Badan    : " << beratBadan << " kg (sizeof: " << sizeof(float) << " byte)\n";
    cout << "Tinggi Badan   : " << tinggiBadan << " cm (sizeof: " << sizeof(double) << " byte)\n";
    cout << "Status Aktif   : " << (isMahasiswaAktif ? "Aktif" : "Non-Aktif") << " (sizeof: " << sizeof(bool) << " byte)\n";
    cout << "Konstanta PI   : " << PI << "\n";
}

void demoOperatorAritmatika() {
    cout << "\n====================================================\n";
    cout << "          02. OPERATOR ARITMATIKA & CASTING         \n";
    cout << "====================================================\n";
    int a = 20, b = 6;
    cout << "a = " << a << ", b = " << b << "\n";
    cout << "Penjumlahan (a + b)        : " << (a + b) << "\n";
    cout << "Pengurangan (a - b)        : " << (a - b) << "\n";
    cout << "Perkalian   (a * b)        : " << (a * b) << "\n";
    cout << "Pembagian bulat (a / b)    : " << (a / b) << "\n";
    cout << "Sisa bagi / Modulo (a % b) : " << (a % b) << "\n";
    cout << fixed << setprecision(2);
    cout << "Pembagian desimal (casting): " << (static_cast<double>(a) / b) << "\n";

    int n = 5;
    cout << "Pre-increment  (++n)       : " << ++n << "\n";
    cout << "Post-increment (n++)       : " << n++ << " (sekarang n = " << n << ")\n";
}

void demoOperatorRelasionalDistinct() {
    cout << "\n====================================================\n";
    cout << "   03. OPERATOR RELASIONAL & DISTINCT VALUES        \n";
    cout << "====================================================\n";
    int p = 15, q = 15, r = 25;
    cout << "Nilai: p = " << p << ", q = " << q << ", r = " << r << "\n";
    cout << "p == q : " << (p == q ? "True" : "False") << "\n";
    cout << "p != r : " << (p != r ? "True" : "False") << "\n";
    cout << "r > p  : " << (r > p  ? "True" : "False") << "\n";

    bool isDistinct = (p != q) && (q != r) && (p != r);
    cout << "Apakah p, q, r bernilai DISTINCT (semuanya berbeda)? : "
         << (isDistinct ? "Ya, semuanya berbeda" : "Tidak, ada yang kembar") << "\n";
}

void demoOperatorLogikaPenugasan() {
    cout << "\n====================================================\n";
    cout << "   04. OPERATOR LOGIKA, PENUGASAN, & TERNARY        \n";
    cout << "====================================================\n";
    int score = 80;
    score += 15;
    cout << "Penugasan majemuk (score += 15) -> " << score << "\n";

    bool syarat1 = true, syarat2 = false;
    cout << "Logika AND (true && false)     -> " << (syarat1 && syarat2 ? "True" : "False") << "\n";
    cout << "Logika OR  (true || false)     -> " << (syarat1 || syarat2 ? "True" : "False") << "\n";
    cout << "Logika NOT (!false)            -> " << (!syarat2 ? "True" : "False") << "\n";

    string status = (score >= 75) ? "LULUS" : "REMEDIAL";
    cout << "Ternary: Skor " << score << " -> " << status << "\n";
}

void demoStudiKasusNilaiAkhir() {
    cout << "\n====================================================\n";
    cout << "  05. STUDI KASUS: SISTEM PENILAIAN PRAKTIKUM       \n";
    cout << "====================================================\n";
    string nama = "Al-Ghani Desta Setyawan";
    double tugas = 88.5, kuis = 80.0, uts = 85.0, uas = 91.5;
    double nilaiAkhir = (tugas * 0.20) + (kuis * 0.15) + (uts * 0.30) + (uas * 0.35);

    bool distinct = (tugas != kuis) && (kuis != uts) && (uts != uas);
    string grade = (nilaiAkhir >= 85) ? "A" : (nilaiAkhir >= 75) ? "B" : "C";
    bool lulus = (nilaiAkhir >= 70) && (tugas >= 60) && (uas >= 60);

    cout << fixed << setprecision(2);
    cout << "Praktikan        : " << nama << "\n";
    cout << "Nilai Akhir Total: " << nilaiAkhir << "\n";
    cout << "Predikat Huruf   : " << grade << "\n";
    cout << "Komponen Distinct: " << (distinct ? "Ya (Berbeda semua)" : "Tidak") << "\n";
    cout << "Status           : " << (lulus ? "LULUS" : "TIDAK LULUS") << "\n";
}

int main() {
    int pilihan = 0;

    cout << "====================================================\n";
    cout << "   PRAKTIKUM 2: VARIABEL, TIPE DATA, & OPERATOR     \n";
    cout << "====================================================\n";
    cout << "1. 01_variabel_tipe_data.cpp\n";
    cout << "2. 02_operator_aritmatika.cpp\n";
    cout << "3. 03_operator_relasional_distinct.cpp\n";
    cout << "4. 04_operator_logika_penugasan.cpp\n";
    cout << "5. 05_studi_kasus_nilai_akhir.cpp\n";
    cout << "6. Jalankan Semua Modul Sekaligus\n";
    cout << "----------------------------------------------------\n";
    cout << "Pilih menu (1-6): ";
    
    if (!(cin >> pilihan)) {
        // Default jika dijalankan non-interaktif
        pilihan = 6;
        cout << "6 (Otomatis: Menjalankan semua modul)\n";
    }

    switch (pilihan) {
        case 1:
            demoVariabelDanTipeData();
            break;
        case 2:
            demoOperatorAritmatika();
            break;
        case 3:
            demoOperatorRelasionalDistinct();
            break;
        case 4:
            demoOperatorLogikaPenugasan();
            break;
        case 5:
            demoStudiKasusNilaiAkhir();
            break;
        case 6:
            demoVariabelDanTipeData();
            demoOperatorAritmatika();
            demoOperatorRelasionalDistinct();
            demoOperatorLogikaPenugasan();
            demoStudiKasusNilaiAkhir();
            break;
        default:
            cout << "Pilihan tidak valid!\n";
            break;
    }

    cout << "\nCatatan: Anda juga dapat mengompilasi setiap file materi secara mandiri:\n";
    cout << "Contoh: g++ 01_variabel_tipe_data.cpp -o 01_variabel_tipe_data && ./01_variabel_tipe_data\n";
    cout << "====================================================\n";

    return 0;
}
