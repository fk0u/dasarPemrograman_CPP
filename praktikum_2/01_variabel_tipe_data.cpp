//
//  01_variabel_tipe_data.cpp
//  dasarPemrograman_CPP - Praktikum 2
//
//  Topik: Implementasi Variabel, Beragam Tipe Data (Distinct Types),
//         Konstanta, dan Operator sizeof
//  Created by Al-Ghani Desta Setyawan
//

#include <iostream>
#include <string>

using namespace std;

int main() {
  cout << "====================================================\n";
  cout << "  01. IMPLEMENTASI VARIABEL & TIPE DATA (DISTINCT)  \n";
  cout << "====================================================\n\n";

  // 1. Deklarasi dan Inisialisasi Tipe Data Primitif & Objek
  string nama = "Al-Ghani Desta Setyawan"; // Teks / String
  string nim = "2611102441026";            // String untuk identitas berdigit
  int umur = 19;                           // Bilangan bulat (integer)
  char golonganDarah = 'O';                // Karakter tunggal
  float beratBadan = 65.5f;                // Bilangan riil (float, 32-bit)
  double tinggiBadan = 172.85;  // Bilangan riil presisi ganda (double, 64-bit)
  bool isMahasiswaAktif = true; // Boolean (true/false)

  // Konstanta: nilai tetap yang tidak dapat diubah selama program berjalan
  const string NAMA_KAMPUS = "Universitas Muhammadiyah Kalimantan Timur";
  const double PI = 3.141592653589793;

  // 2. Menampilkan Data Variabel ke Layar menggunakan cout
  cout << "--- Data Mahasiswa ---\n";
  cout << "Nama Kampus         : " << NAMA_KAMPUS << "\n";
  cout << "Nama Mahasiswa      : " << nama << "\n";
  cout << "NIM                 : " << nim << "\n";
  cout << "Umur                : " << umur << " tahun\n";
  cout << "Golongan Darah      : " << golonganDarah << "\n";
  cout << "Berat Badan         : " << beratBadan << " kg\n";
  cout << "Tinggi Badan        : " << tinggiBadan << " cm\n";
  cout << "Status Aktif        : "
       << (isMahasiswaAktif ? "Aktif (true)" : "Non-Aktif (false)") << "\n";
  cout << "Konstanta PI        : " << PI << "\n\n";

  // 3. Mengamati Ukuran Memori Setiap Tipe Data (Distinct Types Memory Size)
  cout << "--- Ukuran Memori Tipe Data (sizeof) ---\n";
  cout << "Ukuran char         : " << sizeof(char) << " byte\n";
  cout << "Ukuran bool         : " << sizeof(bool) << " byte\n";
  cout << "Ukuran int          : " << sizeof(int) << " byte\n";
  cout << "Ukuran float        : " << sizeof(float) << " byte\n";
  cout << "Ukuran double       : " << sizeof(double) << " byte\n";
  cout << "Ukuran string objek : " << sizeof(string) << " byte\n";
  cout << "Panjang teks nama   : " << nama.length() << " karakter\n\n";

  cout << "====================================================\n";
  return 0;
}
