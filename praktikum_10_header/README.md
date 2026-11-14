# Praktikum 10: Header Files (C++)

**Basic Programming Practicum (INF1053)**  
**Program Studi:** S1 Teknik Informatika — Universitas Muhammadiyah Kalimantan Timur  

## 📂 Struktur Direktori

```text
praktikum_10_header/
├── README.md
├── latihan/
└── penugasan/
    ├── TUGAS.md                  # Laporan lengkap (penjelasan, gambar kode & output, kesimpulan)
    ├── render_images.py          # Script rendering gambar kode & output terminal
    ├── assets/                   # Output image code & output image compiled output (.png)
    ├── test_10_1/                # Cylinder Volume (cylinder.h, cylinder.cpp, main.cpp, main)
    ├── test_10_2/                # Square Area Return vs Void (square.h, square.cpp, main.cpp, main)
    ├── test_10_3/                # Arithmetic Header & Bug Fix (arithmetic.h, arithmetic.cpp, main.cpp, main)
    ├── test_10_4/                # Temperature Conversion + Challenge (conversion.h, conversion.cpp, main.cpp, main)
    └── test_10_5/                # Individual Task: 2D Distance Analysis (geometry.h, geometry.cpp, main.cpp, main)
```

## 🚀 Cara Kompilasi & Menjalankan

Setiap sub-tugas dikompilasi dengan menyertakan `main.cpp` dan file implementasi `.cpp`-nya:

```bash
# Test 10.1
clang++ -std=c++17 penugasan/test_10_1/main.cpp penugasan/test_10_1/cylinder.cpp -o penugasan/test_10_1/main && ./penugasan/test_10_1/main

# Test 10.2
clang++ -std=c++17 penugasan/test_10_2/main.cpp penugasan/test_10_2/square.cpp -o penugasan/test_10_2/main && ./penugasan/test_10_2/main

# Test 10.3
clang++ -std=c++17 penugasan/test_10_3/main.cpp penugasan/test_10_3/arithmetic.cpp -o penugasan/test_10_3/main && ./penugasan/test_10_3/main

# Test 10.4
clang++ -std=c++17 penugasan/test_10_4/main.cpp penugasan/test_10_4/conversion.cpp -o penugasan/test_10_4/main && ./penugasan/test_10_4/main

# Test 10.5
clang++ -std=c++17 penugasan/test_10_5/main.cpp penugasan/test_10_5/geometry.cpp -o penugasan/test_10_5/main && ./penugasan/test_10_5/main
```

Lihat laporan lengkap beserta seluruh gambar kode dan output terkompilasi di [penugasan/TUGAS.md](penugasan/TUGAS.md).
