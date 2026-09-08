//
//  04_operator_logika_penugasan.cpp
//  dasarPemrograman_CPP - Praktikum 2
//
//  Topik: Operator Logika (&&, ||, !), Penugasan Majemuk (Compound Assignment),
//         dan Operator Ternary (? :)
//  Created by Al-Ghani Desta Setyawan
//

#include <iostream>
#include <string>

using namespace std;

int main() {
  cout << "====================================================\n";
  cout << "   04. OPERATOR LOGIKA, PENUGASAN, & TERNARY        \n";
  cout << "====================================================\n\n";

  // 1. Operator Penugasan Majemuk (Compound Assignment)
  cout << "--- Operator Penugasan Majemuk ---\n";
  int nilai = 50;
  cout << "Nilai awal : " << nilai << "\n";
  nilai += 20; // nilai = nilai + 20
  cout << "nilai += 20 -> " << nilai << "\n";
  nilai -= 15; // nilai = nilai - 15
  cout << "nilai -= 15 -> " << nilai << "\n";
  nilai *= 2; // nilai = nilai * 2
  cout << "nilai *= 2  -> " << nilai << "\n";
  nilai /= 5; // nilai = nilai / 5
  cout << "nilai /= 5  -> " << nilai << "\n";
  nilai %= 7; // nilai = nilai % 7
  cout << "nilai %= 7  -> " << nilai << "\n\n";

  // 2. Operator Logika (AND, OR, NOT)
  cout << "--- Operator Logika ---\n";
  bool punyaKTP = true;
  bool punyaSIM = false;
  int usia = 19;

  bool bolehMengemudi = (usia >= 17) && punyaSIM;
  bool punyaIdentitas = punyaKTP || punyaSIM;
  bool belumPunyaSIM = !punyaSIM;

  cout << "Usia >= 17 && punyaSIM (AND) : "
       << (bolehMengemudi ? "Boleh" : "Tidak Boleh") << "\n";
  cout << "punyaKTP || punyaSIM   (OR)  : "
       << (punyaIdentitas ? "Ada Dokumen" : "Tidak Ada Dokumen") << "\n";
  cout << "!punyaSIM              (NOT) : "
       << (belumPunyaSIM ? "Benar (Belum punya)" : "Sudah punya") << "\n\n";

  // 3. Operator Ternary (? :)
  cout << "--- Operator Ternary (Kondisional Pendek) ---\n";
  int skor = 78;
  string statusKelulusan = (skor >= 75) ? "LULUS" : "REMEDIAL";
  cout << "Skor: " << skor << " -> Status: " << statusKelulusan << "\n\n";

  // 4. Studi Kasus: Seleksi Calon Asisten Praktikum
  cout << "--- Studi Kasus: Seleksi Asisten Praktikum ---\n";
  double ipk = 3.82;
  int semester = 3;
  char nilaiDaspro = 'A';
  bool adaPelanggaranEtik = false;

  // Kriteria kelayakan: IPK >= 3.50 DAN semester 3-5 DAN nilai 'A' DAN TIDAK
  // ada pelanggaran
  bool lolosSyarat = (ipk >= 3.50) && (semester >= 3 && semester <= 5) &&
                     (nilaiDaspro == 'A') && (!adaPelanggaranEtik);

  string hasilSeleksi = lolosSyarat ? "LOLOS TAHAP BERKAS (Direkomendasikan)"
                                    : "BELUM MEMENUHI SYARAT";

  cout << "IPK Mahasiswa     : " << ipk << "\n";
  cout << "Semester          : " << semester << "\n";
  cout << "Nilai Daspro      : " << nilaiDaspro << "\n";
  cout << "Catatan Etik      : "
       << (adaPelanggaranEtik ? "Ada Pelanggaran" : "Bersih") << "\n";
  cout << "Hasil Evaluasi    : " << hasilSeleksi << "\n";
  cout << "====================================================\n";

  return 0;
}
