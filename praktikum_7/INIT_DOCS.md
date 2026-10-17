# PRAKTIKUM 7: TUPLE - EXECUTIVE SUMMARY & RUN INSTRUCTIONS

**Mata Kuliah:** Pemrograman Dasar (INF1053)  
**Mahasiswa:** Al-Ghani Desta Setyawan (2611102441026)  
**Institusi:** Teknik Informatika, Universitas Muhammadiyah Kalimantan Timur  

---

## 🚀 Quick Execution Guide

Untuk meng-compile dan menjalankan seluruh program dalam Praktikum 7:

```bash
# 1. Pindah ke direktori praktikum_7
cd /Users/kou/Project/dasarPemrograman_CPP/praktikum_7

# 2. Compile semua kode C++ (Standar C++17)
clang++ -std=c++17 -Wall -Wextra 7_1.cpp -o 7_1
clang++ -std=c++17 -Wall -Wextra 7_2.cpp -o 7_2
clang++ -std=c++17 -Wall -Wextra 7_3.cpp -o 7_3
clang++ -std=c++17 -Wall -Wextra 7_4.cpp -o 7_4

# 3. Eksekusi masing-masing file binary
./7_1
./7_2
./7_3
./7_4
```

---

## 📊 Summary of Implemented Solutions

| Test ID | Topik | File Kode | Operasi Kunci | Output Singkat |
| :--- | :--- | :--- | :--- | :--- |
| **Test 7.1** | Basic Operations | `7_1.cpp` | `std::get<>()`, `std::tuple_size` | Nama, NIM, Ukuran Tuple = 2 |
| **Test 7.2** | Packing & Unpacking | `7_2.cpp` | `std::make_tuple()`, `std::tie()` | Nama dan Umur terurai rapi |
| **Test 7.3** | Concatenation | `7_3.cpp` | `std::tuple_cat()` | Gabungan 4 atribut (Nama, Umur, Tinggi, Berat) |
| **Test 7.4** | Swapping | `7_4.cpp` | `tuple::swap()` | Pertukaran nilai element-wise person1 & person2 |

---

## 🖼️ Visual Assets Generated

Aset visual syntax highlighting dan terminal output tersimpan di direktori `assets/`:
- `code_7_1.png` & `output_7_1.png`
- `code_7_2.png` & `output_7_2.png`
- `code_7_3.png` & `output_7_3.png`
- `code_7_4.png` & `output_7_4.png`

Seluruh aset gambar dan penjelasan telah dimasukkan ke dalam dokumen Word resmi:
`Practical Module 7 Tuple.docx`.
