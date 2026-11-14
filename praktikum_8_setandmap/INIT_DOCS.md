# PRAKTIKUM 8: SET & MAP - EXECUTIVE SUMMARY & RUN INSTRUCTIONS

**Mata Kuliah:** Pemrograman Dasar (CSE1053)  
**Mahasiswa:** Al-Ghani Desta Setyawan (2611102441026)  
**Institusi:** Teknik Informatika, Universitas Muhammadiyah Kalimantan Timur  

---

## 🚀 Quick Execution Guide

Untuk meng-compile dan menjalankan seluruh program dalam Praktikum 8:

```bash
# 1. Pindah ke direktori praktikum_8
cd /Users/kou/Project/dasarPemrograman_CPP/praktikum_8

# 2. Compile semua kode C++ (Standar C++17)
clang++ -std=c++17 -Wall -Wextra 8_1.cpp -o 8_1
clang++ -std=c++17 -Wall -Wextra 8_2.cpp -o 8_2
clang++ -std=c++17 -Wall -Wextra 8_3.cpp -o 8_3
clang++ -std=c++17 -Wall -Wextra 8_4.cpp -o 8_4

# 3. Eksekusi masing-masing file binary
./8_1
./8_2
./8_3
./8_4
```

---

## 📊 Summary of Implemented Solutions

| Test ID | Topik | File Kode | Operasi Kunci | Output Singkat |
| :--- | :--- | :--- | :--- | :--- |
| **Test 8.1** | Basic Operation on Set | `8_1.cpp` | `insert()`, `erase()`, range loop | Buah bertambah Mango, terhapus Banana, otomatis terurut |
| **Test 8.2** | Advance Operation on Set | `8_2.cpp` | `size()`, `clear()`, `empty()` | Ukuran Set1 (4) dan Set2 (5), validasi status kosong setelah clear |
| **Test 8.3** | Basic Operation on Map | `8_3.cpp` | `insert()`, `erase()`, `at()` | Pasangan mahasiswa ditambah Kara, dihapus Baskara, diambil nilai via at |
| **Test 8.4** | Using Functions on Map | `8_4.cpp` | `.first`, `.second`, `count()`, `clear()`, `size()`, `empty()` | Iterasi pasangan kunci-nilai, validasi eksistensi kunci, reset total |

---

## 🖼️ Visual Assets Generated

Aset visual syntax highlighting dan terminal output tersimpan di direktori `assets/`:
- `code_8_1.png` & `output_8_1.png`
- `code_8_2.png` & `output_8_2.png`
- `code_8_3.png` & `output_8_3.png`
- `code_8_4.png` & `output_8_4.png`

Seluruh aset gambar dan penjelasan telah dimasukkan ke dalam dokumen Word resmi:
`Practical Module 8 Set and Map.docx`.
