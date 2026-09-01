# Repository Praktikum Dasar Pemrograman (C++)

Repository ini berisi kumpulan kode program, latihan, tugas, dan dokumentasi praktikum untuk mata kuliah **Dasar Pemrograman** menggunakan bahasa **C++**.

---

## 📌 Identitas Praktikan

| Informasi | Keterangan |
| :--- | :--- |
| **Nama** | Al-Ghani Desta Setyawan |
| **NIM** | *2611xxxxxxx* |
| **Program Studi** | S1 Teknik Informatika |
| **Kelas / Angkatan** | *Kelas Internasional EE* |
| **Dosen Pengampu** | *Naufal Azmi Verdikha* |
| **Asisten Praktikum**| *Lukman Haidi* |

---

## 📂 Struktur Direktori

```text
dasarPemrograman_CPP/
├── README.md              # Dokumentasi utama repository
├── intro.cpp              # Program perkenalan diri
└── praktikum_1/           # Modul / Pertemuan Praktikum 1
    └── main.cpp           # Program Hello World & latihan dasar
```

> *Struktur folder akan terus diperbarui seiring berjalannya pertemuan praktikum.*

---

## 🛠️ Lingkungan Pengembangan (Development Environment)

- **Bahasa Pemrograman**: C++ (C++11 / C++17 / C++20)
- **Kompiler**: `g++` / `clang++` (Apple Clang / GCC)
- **IDE / Editor**: Xcode, Visual Studio Code / Terminal
- **Sistem Operasi**: macOS

---

## 🚀 Panduan Kompilasi dan Menjalankan Program

Untuk menjalankan salah satu file program C++ melalui terminal:

### 1. Kompilasi menggunakan `g++` atau `clang++`

```bash
# Format umum:
# g++ <nama_file.cpp> -o <nama_executable> && ./<nama_executable>

# Contoh 1: Menjalankan intro.cpp
g++ intro.cpp -o intro && ./intro

# Contoh 2: Menjalankan program di praktikum_1
cd praktikum_1
g++ main.cpp -o main && ./main
```

### 2. Opsi Flag Kompilasi Tambahan (Disarankan)

Gunakan flag `-Wall` untuk menampilkan semua peringatan (warnings) dan standar modern `-std=c++17`:

```bash
g++ -std=c++17 -Wall main.cpp -o main && ./main
```

---

## 📋 Daftar Pertemuan & Materi Praktikum

- [x] **Praktikum 0**: Setup Lingkungan C++ & Perkenalan Diri (`intro.cpp`)
- [ ] **Praktikum 1**: Pengenalan Dasar C++, Struktur Program, Input/Output (`praktikum_1/`)
- [ ] **Praktikum 2**: Tipe Data, Variabel, dan Operator
- [ ] **Praktikum 3**: Struktur Kontrol (Percabangan: `if`, `else`, `switch-case`)
- [ ] **Praktikum 4**: Struktur Perulangan (`for`, `while`, `do-while`)
- [ ] **Praktikum 5**: Array & String
- [ ] **Praktikum 6**: Fungsi (Function) & Prosedur
- [ ] **Praktikum 7**: Pointer & Referensi
- [ ] **Praktikum 8**: Struct & Tipe Data Bentukan
- [ ] **Tugas Akhir / Project**: *[Akan diperbarui]*

---

## 📝 Lisensi & Catatan

Proyek ini dibuat untuk keperluan akademik dan pembelajaran mandiri. Silakan jadikan referensi dengan tetap memperhatikan integritas akademik.
