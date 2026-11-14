# PRAKTIKUM 9: FUNCTIONS & LAMBDA - EXECUTIVE SUMMARY & RUN INSTRUCTIONS

**Mata Kuliah:** Pemrograman Dasar (INF1053)  
**Mahasiswa:** Al-Ghani Desta Setyawan (2611102441026)  
**Institusi:** Teknik Informatika, Universitas Muhammadiyah Kalimantan Timur  

---

## 🚀 Quick Execution Guide

Untuk meng-compile dan menjalankan seluruh program dalam Praktikum 9:

```bash
# 1. Pindah ke direktori praktikum_9
cd /Users/kou/Project/dasarPemrograman_CPP/praktikum_9

# 2. Compile semua kode C++ (Standar C++17)
clang++ -std=c++17 -Wall -Wextra 9_1.cpp -o 9_1
clang++ -std=c++17 -Wall -Wextra 9_2.cpp -o 9_2
clang++ -std=c++17 -Wall -Wextra 9_3.cpp -o 9_3
clang++ -std=c++17 -Wall -Wextra 9_4.cpp -o 9_4
clang++ -std=c++17 -Wall -Wextra 9_5.cpp -o 9_5
clang++ -std=c++17 -Wall -Wextra 9_6.cpp -o 9_6
clang++ -std=c++17 -Wall -Wextra 9_7.cpp -o 9_7

# 3. Eksekusi masing-masing file binary
./9_1
./9_2
./9_3
./9_4
./9_5
./9_6
./9_7
```

---

## 📊 Summary of Implemented Solutions

| Test ID | Topik | File Kode | Operasi Kunci | Output Singkat |
| :--- | :--- | :--- | :--- | :--- |
| **Test 9.1** | Cube Volume Function | `9_1.cpp` | `return s * s * s` | Volume kubus (s=5) = 125 cm³ |
| **Test 9.2** | Void Function Biodata | `9_2.cpp` | `void biodata()` | Cetak kartu biodata mahasiswa lengkap |
| **Test 9.3** | Function Default Parameter | `9_3.cpp` | `bool checkEven(int n = 4)` | Cek bilangan genap (default 4 = true, 10 = true, 7 = false) |
| **Test 9.4** | Prototype Function | `9_4.cpp` | Deklarasi prototype di atas `main()` | Menghitung volume kubus (s=4 -> 64, s=6 -> 216) |
| **Test 9.5** | Lambda Exercise I | `9_5.cpp` | `[](int x, int y) { return (x + y) * 2; }` | Hasil evaluasi lambda count(10, 2) = 24 |
| **Test 9.6** | Lambda Capture vs Parameter | `9_6.cpp` | `[a, b](int x, int y)` | Capture: 15, Parameter: 34 |
| **Test 9.7** | Individual Task (Recursion as Loop) | `9_7.cpp` | `countdown(n - 1)` dengan base case `n <= 0` | Hitung mundur T-5 sampai T-0 Liftoff tanpa loop for/while |

---

## 🖼️ Visual Assets Generated

Aset visual syntax highlighting dan terminal output tersimpan di direktori `assets/`:
- `code_9_1.png` s.d. `code_9_7.png`
- `output_9_1.png` s.d. `output_9_7.png`

Seluruh aset gambar, penjelasan analisis kode, dan kesimpulan pembelajaran telah dimasukkan ke dalam dokumen Word resmi:
`Module 9 Functions and Lambda.docx`.

