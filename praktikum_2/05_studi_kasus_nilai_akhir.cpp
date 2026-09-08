//
//  05_studi_kasus_nilai_akhir.cpp
//  dasarPemrograman_CPP - Praktikum 2
//
//  Topik: Studi Kasus Komprehensif Kalkulasi Nilai Akhir Mahasiswa
//         (Menggabungkan variabel, tipe data, operator aritmatika,
//          relasional, logika, distinct check, dan formatted output)
//  Created by Al-Ghani Desta Setyawan
//

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
  cout << "====================================================\n";
  cout << "  05. STUDI KASUS: SISTEM PENILAIAN PRAKTIKUM       \n";
  cout << "====================================================\n\n";

  // 1. Deklarasi Identitas Mahasiswa
  string namaMahasiswa = "Al-Ghani Desta Setyawan";
  string nim = "2611102441026";
  string mataKuliah = "Dasar Pemrograman (C++)";

  // 2. Nilai Komponen Praktikum
  double nilaiTugas = 88.5;
  double nilaiKuis = 80.0;
  double nilaiUTS = 85.0;
  double nilaiUAS = 91.5;

  // 3. Konstanta Bobot Penilaian
  const double BOBOT_TUGAS = 0.20; // 20%
  const double BOBOT_KUIS = 0.15;  // 15%
  const double BOBOT_UTS = 0.30;   // 30%
  const double BOBOT_UAS = 0.35;   // 35%

  // 4. Perhitungan Nilai Akhir (Operator Aritmatika)
  double nilaiAkhir = (nilaiTugas * BOBOT_TUGAS) + (nilaiKuis * BOBOT_KUIS) +
                      (nilaiUTS * BOBOT_UTS) + (nilaiUAS * BOBOT_UAS);

  // 5. Pengecekan Keunikan Nilai Komponen (Distinct Check)
  bool isSemuaNilaiDistinct =
      (nilaiTugas != nilaiKuis) && (nilaiKuis != nilaiUTS) &&
      (nilaiUTS != nilaiUAS) && (nilaiTugas != nilaiUTS) &&
      (nilaiTugas != nilaiUAS) && (nilaiKuis != nilaiUAS);

  // 6. Penentuan Huruf Mutu (Grade) menggunakan Operator Ternary
  string grade = (nilaiAkhir >= 85.0)   ? "A (Istimewa)"
                 : (nilaiAkhir >= 75.0) ? "B (Sangat Baik)"
                 : (nilaiAkhir >= 65.0) ? "C (Cukup)"
                 : (nilaiAkhir >= 50.0) ? "D (Kurang)"
                                        : "E (Gagal)";

  // 7. Evaluasi Status Kelulusan (Operator Relasional & Logika)
  // Syarat: Nilai akhir >= 70.0 DAN nilai tugas >= 60.0 DAN nilai UAS >= 60.0
  bool isLulus =
      (nilaiAkhir >= 70.0) && (nilaiTugas >= 60.0) && (nilaiUAS >= 60.0);

  // 8. Tampilan Laporan Hasil Penilaian (Formatted I/O)
  cout << fixed << setprecision(2);
  cout << "Mata Kuliah         : " << mataKuliah << "\n";
  cout << "Praktikan           : " << namaMahasiswa << " (" << nim << ")\n";
  cout << "----------------------------------------------------\n";
  cout << "Nilai Tugas (20%)   : " << nilaiTugas << "\n";
  cout << "Nilai Kuis  (15%)   : " << nilaiKuis << "\n";
  cout << "Nilai UTS   (30%)   : " << nilaiUTS << "\n";
  cout << "Nilai UAS   (35%)   : " << nilaiUAS << "\n";
  cout << "Komponen Distinct?  : "
       << (isSemuaNilaiDistinct ? "Ya (Semua nilai komponen berbeda)"
                                : "Tidak (Ada nilai komponen yang sama)")
       << "\n";
  cout << "----------------------------------------------------\n";
  cout << "Nilai Akhir Total   : " << nilaiAkhir << "\n";
  cout << "Predikat Huruf      : " << grade << "\n";
  cout << "Status Kelulusan    : "
       << (isLulus ? "LULUS / MEMENUHI SYARAT" : "TIDAK LULUS") << "\n";
  cout << "====================================================\n";

  return 0;
}
