import os
import docx
from docx.shared import Inches, Pt, RGBColor
from docx.enum.text import WD_ALIGN_PARAGRAPH

DOCX_PATH = '/Users/kou/Project/dasarPemrograman_CPP/praktikum_9/Module 9 Functions and Lambda.docx'
ASSETS_DIR = '/Users/kou/Project/dasarPemrograman_CPP/praktikum_9/assets'

doc = docx.Document(DOCX_PATH)

def format_run(run, bold=False, italic=False, size_pt=12, font_name='Times New Roman', color=None):
    run.font.name = font_name
    run.font.size = Pt(size_pt)
    run.bold = bold
    run.italic = italic
    if color:
        run.font.color.rgb = color

def add_p(cell, text, bold=False, italic=False, size_pt=12, space_after=4, align=WD_ALIGN_PARAGRAPH.LEFT):
    p = cell.add_paragraph()
    p.paragraph_format.space_after = Pt(space_after)
    p.alignment = align
    run = p.add_run(text)
    format_run(run, bold=bold, italic=italic, size_pt=size_pt)
    return p

def add_img(cell, img_path, width=Inches(5.5), space_after=6):
    p = cell.add_paragraph()
    p.paragraph_format.space_after = Pt(space_after)
    p.alignment = WD_ALIGN_PARAGRAPH.CENTER
    p.add_run().add_picture(img_path, width=width)
    return p

# 1. Update Student Cover Information
for p in doc.paragraphs:
    if "Name….." in p.text:
        p.text = "Al-Ghani Desta Setyawan"
        if p.runs: format_run(p.runs[0], bold=True, size_pt=12)
    elif "Nim…" in p.text:
        p.text = "NIM 2611102441026"
        if p.runs: format_run(p.runs[0], bold=True, size_pt=12)
    elif "Samarinda, 2025" in p.text:
        p.text = "Samarinda, 2026"
        if p.runs: format_run(p.runs[0], size_pt=12)

# ----------------- TABLE 1: TEST 9.1 -----------------
cell_1 = doc.tables[1].rows[0].cells[0]
for p in list(cell_1.paragraphs)[1:]:
    p._element.getparent().remove(p._element)

add_p(cell_1, "A. Source Code (9_1.cpp):", bold=True, space_after=4)
add_img(cell_1, os.path.join(ASSETS_DIR, 'code_9_1.png'), width=Inches(5.5))
add_p(cell_1, "B. Program Output:", bold=True, space_after=4)
add_img(cell_1, os.path.join(ASSETS_DIR, 'output_9_1.png'), width=Inches(5.2))
add_p(cell_1, "C. Explanation of What Was Wrong with the Function Format:", bold=True, space_after=2)
add_p(cell_1, "1. Masalah pada kode awal: Fungsi dideklarasikan dengan tipe kembalian integer (int cubeVolume(int s)), namun di dalamnya justru mencetak langsung dengan cout << s * s * s tanpa memberikan pernyataan 'return'. Hal ini menyebabkan peringatan/error kompilasi (non-void function does not return a value) dan nilainya tidak dapat disimpan ke variabel atau digunakan dalam perhitungan lain.")
add_p(cell_1, "2. Perbaikan yang dilakukan: Mengganti baris 'cout << s * s * s;' menjadi 'return s * s * s;'. Dengan begitu, fungsi mengembalikan nilai hasil perkalian sisi kubus (s^3) ke pemanggilnya, sehingga di fungsi main() hasilnya dapat ditampung dalam variabel 'int volume = cubeVolume(side);' secara modular dan fleksibel.")

# ----------------- TABLE 2: TEST 9.2 -----------------
cell_2 = doc.tables[2].rows[0].cells[0]
for p in list(cell_2.paragraphs)[1:]:
    p._element.getparent().remove(p._element)

add_p(cell_2, "A. Source Code (9_2.cpp):", bold=True, space_after=4)
add_img(cell_2, os.path.join(ASSETS_DIR, 'code_9_2.png'), width=Inches(5.5))
add_p(cell_2, "B. Program Output:", bold=True, space_after=4)
add_img(cell_2, os.path.join(ASSETS_DIR, 'output_9_2.png'), width=Inches(5.2))
add_p(cell_2, "C. Implementation Notes:", bold=True, space_after=2)
add_p(cell_2, "1. Fungsi biodata didefinisikan menggunakan tipe return 'void', yang menandakan fungsi ini bertindak murni sebagai prosedur untuk melakukan aksi (menampilkan informasi) tanpa mengembalikan suatu nilai ke pemanggil.")
add_p(cell_2, "2. Informasi yang ditampilkan mencakup Nama (Al-Ghani Desta Setyawan), NIM (2611102441026), Umur (20), Mata Kuliah (Pemrograman Dasar INF1053), dan Program Studi (S1 Teknik Informatika).")

# ----------------- TABLE 3: TEST 9.3 -----------------
cell_3 = doc.tables[3].rows[0].cells[0]
for p in list(cell_3.paragraphs)[1:]:
    p._element.getparent().remove(p._element)

add_p(cell_3, "A. Source Code (9_3.cpp):", bold=True, space_after=4)
add_img(cell_3, os.path.join(ASSETS_DIR, 'code_9_3.png'), width=Inches(5.5))
add_p(cell_3, "B. Program Output:", bold=True, space_after=4)
add_img(cell_3, os.path.join(ASSETS_DIR, 'output_9_3.png'), width=Inches(5.2))
add_p(cell_3, "C. Implementation Notes:", bold=True, space_after=2)
add_p(cell_3, "1. Parameter Default: Fungsi dideklarasikan sebagai 'bool checkEven(int n = 4)'. Nilai default '4' akan otomatis digunakan oleh compiler jika fungsi dipanggil tanpa argumen (checkEven()).")
add_p(cell_3, "2. Logika Pengecekan: Menggunakan operasi modulus '(n % 2 == 0)' yang mengembalikan nilai boolean true (1) jika bilangan habis dibagi 2 (genap) dan false (0) jika ganjil.")
add_p(cell_3, "3. Pengujian: Terbukti saat dipanggil checkEven() menghasilkan 1, checkEven(10) menghasilkan 1, dan checkEven(7) menghasilkan 0.")

# ----------------- TABLE 4: TEST 9.4 -----------------
cell_4 = doc.tables[4].rows[0].cells[0]
for p in list(cell_4.paragraphs)[1:]:
    p._element.getparent().remove(p._element)

add_p(cell_4, "A. Source Code (9_4.cpp):", bold=True, space_after=4)
add_img(cell_4, os.path.join(ASSETS_DIR, 'code_9_4.png'), width=Inches(5.5))
add_p(cell_4, "B. Program Output:", bold=True, space_after=4)
add_img(cell_4, os.path.join(ASSETS_DIR, 'output_9_4.png'), width=Inches(5.2))
add_p(cell_4, "C. Difference Between a Regular Function and a Function Prototype:", bold=True, space_after=2)
add_p(cell_4, "1. Regular Function (Definisi Lengkap): Mendefinisikan header sekaligus blok kode tubuh fungsi (body {...}) secara langsung di atas main(). Jika fungsinya banyak, kode di bagian atas menjadi panjang dan compiler belum mengenali fungsi jika ditaruh di bawah main().")
add_p(cell_4, "2. Function Prototype (Deklarasi di Awal): Hanya mendeklarasikan signature fungsi (tipe return, nama fungsi, dan tipe parameter diakhiri titik koma ';', contoh: 'int cubeVolume(int s);') di atas main(), sementara implementasi kodenya diletakkan di bawah main().")
add_p(cell_4, "3. Keuntungan Prototype: Memberitahu compiler sejak awal bahwa fungsi tersebut eksis dan valid, membuat struktur kode lebih rapi, serta memungkinkan pemanggilan fungsi yang saling bergantung (forward referencing / mutual recursion).")

# ----------------- TABLE 6: TEST 9.5 -----------------
cell_6 = doc.tables[6].rows[0].cells[0]
for p in list(cell_6.paragraphs)[1:]:
    p._element.getparent().remove(p._element)

add_p(cell_6, "A. Source Code (9_5.cpp):", bold=True, space_after=4)
add_img(cell_6, os.path.join(ASSETS_DIR, 'code_9_5.png'), width=Inches(5.5))
add_p(cell_6, "B. Program Output:", bold=True, space_after=4)
add_img(cell_6, os.path.join(ASSETS_DIR, 'output_9_5.png'), width=Inches(5.2))
add_p(cell_6, "C. Explanation of How Lambda Works and Output Analysis:", bold=True, space_after=2)
add_p(cell_6, "1. Struktur Lambda: Fungsi lambda '[](int x, int y) { return (x + y) * 2; }' adalah fungsi anonim lokal. Bagian '[]' adalah capture clause kosong (tidak mengambil variabel luar), '(int x, int y)' adalah parameter list, dan di dalam body terdapat operasi aritmatika.")
add_p(cell_6, "2. Penyimpanan ke Objek Callable: Lambda ditampung ke dalam variabel 'auto count', sehingga dapat dipanggil selayaknya fungsi biasa.")
add_p(cell_6, "3. Analisis Output: Pemanggilan 'count(10, 2)' menghitung (10 + 2) * 2 = 12 * 2 = 24. Hasil tercetak tepat 24 pada konsol.")

# ----------------- TABLE 8: TEST 9.6 -----------------
cell_8 = doc.tables[8].rows[0].cells[0]
for p in list(cell_8.paragraphs)[1:]:
    p._element.getparent().remove(p._element)

add_p(cell_8, "A. Source Code (9_6.cpp):", bold=True, space_after=4)
add_img(cell_8, os.path.join(ASSETS_DIR, 'code_9_6.png'), width=Inches(5.5))
add_p(cell_8, "B. Program Output:", bold=True, space_after=4)
add_img(cell_8, os.path.join(ASSETS_DIR, 'output_9_6.png'), width=Inches(5.2))
add_p(cell_8, "C. Difference Between Capture and Parameter in Lambda Functions:", bold=True, space_after=2)
add_p(cell_8, "1. Perbaikan Kode: Pada kode awal tertulis '[]' (capture kosong) padahal tubuh lambda memanggil variabel 'a' dan 'b' dari scope luar, sehingga memicu compile error 'variable a cannot be implicitly captured'. Perbaikannya adalah menuliskan '[a, b]' (atau [=] / [&]) pada capture clause agar variabel outer scope dapat diakses.")
add_p(cell_8, "2. Capture ([...]): Mekanisme bagi lambda untuk 'menangkap' variabel yang sudah dideklarasikan di luar tubuh lambda (enclosing scope). Capture dapat dilakukan secara copy/nilai ([a, b] atau [=]) maupun referensi ([&a, &b] atau [&]).")
add_p(cell_8, "3. Parameter ((...)): Variabel input yang dikirimkan saat fungsi lambda dipanggil secara eksplisit melalui argumen pemanggilan (seperti addition(10, 24)), sama seperti parameter fungsi biasa.")

# ----------------- TABLE 9: TEST 9.7 -----------------
cell_9 = doc.tables[9].rows[0].cells[0]
for p in list(cell_9.paragraphs)[1:]:
    p._element.getparent().remove(p._element)

add_p(cell_9, "A. Source Code (9_7.cpp):", bold=True, space_after=4)
add_img(cell_9, os.path.join(ASSETS_DIR, 'code_9_7.png'), width=Inches(5.5))
add_p(cell_9, "B. Program Output:", bold=True, space_after=4)
add_img(cell_9, os.path.join(ASSETS_DIR, 'output_9_7.png'), width=Inches(5.2))
add_p(cell_9, "C. Explanation of the Recursive Program (Case Study: Rocket Launch Countdown):", bold=True, space_after=2)
add_p(cell_9, "1. Studi Kasus: Simulasi hitung mundur peluncuran roket luar angkasa dari detik ke-5 menuju 0 (T-5 sampai T-0 Liftoff).")
add_p(cell_9, "2. Mekanisme Perulangan Tanpa Loop: Program sama sekali tidak menggunakan instruksi 'for' atau 'while'. Proses iterasi dicapai murni melalui fungsi rekursif 'countdown(int n)'.")
add_p(cell_9, "3. Base Case: Ketika n <= 0, fungsi mencetak pesan peluncuran roket ('[T-0] Liftoff!') lalu mengeksekusi 'return' untuk menghentikan pemanggilan lebih lanjut dan mencegah infinite recursion / stack overflow.")
add_p(cell_9, "4. Recursive Step: Selama n > 0, fungsi mencetak status detik saat ini, kemudian memanggil dirinya sendiri dengan parameter terdekrementasi 'countdown(n - 1)'.")

# ----------------- TABLE 10: CONCLUSION -----------------
cell_10 = doc.tables[10].rows[0].cells[0]
for p in list(cell_10.paragraphs):
    p._element.getparent().remove(p._element)

add_p(cell_10, "Conclusion of Today's Lesson:", bold=True, size_pt=13, space_after=6)
add_p(cell_10, "From today's practicum on Functions & Lambda in C++, here are the key concepts I have learned and implemented:")
add_p(cell_10, "1. Function Structure & Return Values: I learned the difference between value-returning functions (using return statement for computation like cubeVolume) and void functions (used for procedures that perform actions like displaying biodata without returning values).")
add_p(cell_10, "2. Default Parameters: C++ allows assigning default argument values in function declarations (e.g., checkEven(int n = 4)), allowing functions to be called flexibly with or without explicit arguments.")
add_p(cell_10, "3. Function Prototypes: Declaring a function prototype above main() informs the compiler about the function's signature before its actual implementation, keeping the code well-organized and enabling flexible function placement.")
add_p(cell_10, "4. Lambda Expressions: I learned that lambdas provide concise, anonymous inline functions. I understand the crucial distinction between the capture clause ([...]) which accesses variables from the outer scope, and parameter lists ((...)) which receive arguments upon invocation.")
add_p(cell_10, "5. Recursion as Loop Mechanism: Through the rocket launch countdown case study, I demonstrated how a recursive function with a solid base case and recursive call can achieve repetitive execution cleanly without using traditional for or while loops.")

doc.save(DOCX_PATH)
print("Module 9 Functions and Lambda.docx successfully populated and saved!")

