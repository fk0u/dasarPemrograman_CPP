import io
import os
import zipfile
import docx
from docx.shared import Inches, Pt, RGBColor
from docx.enum.text import WD_ALIGN_PARAGRAPH
from docx.oxml import OxmlElement
from docx.oxml.ns import qn

BASE_DIR = os.path.dirname(os.path.abspath(__file__))
PRAKTIKUM_DIR = os.path.dirname(BASE_DIR)
ASSETS_DIR = os.path.join(BASE_DIR, 'assets')
OUT_DOCX = os.path.join(PRAKTIKUM_DIR, 'Module 10 Header Files.docx')
MOD9_DOCX = os.path.join(os.path.dirname(PRAKTIKUM_DIR), 'praktikum_9_lambda', 'Module 9 Functions and Lambda.docx')


def extract_umkt_logo():
    with zipfile.ZipFile(MOD9_DOCX, 'r') as z:
        return io.BytesIO(z.read('word/media/image1.png'))


def format_run(run, bold=False, italic=False, size_pt=12, font_name='Times New Roman', color=None):
    run.font.name = font_name
    run.font.size = Pt(size_pt)
    run.bold = bold
    run.italic = italic
    if color:
        run.font.color.rgb = color


def add_p(container, text='', bold=False, italic=False, size_pt=12, space_before=0, space_after=4, align=WD_ALIGN_PARAGRAPH.LEFT):
    p = container.add_paragraph()
    p.paragraph_format.space_before = Pt(space_before)
    p.paragraph_format.space_after = Pt(space_after)
    p.alignment = align
    if text:
        run = p.add_run(text)
        format_run(run, bold=bold, italic=italic, size_pt=size_pt)
    return p


def add_img(container, img_path, width=Inches(5.5), space_after=6):
    p = container.add_paragraph()
    p.paragraph_format.space_after = Pt(space_after)
    p.alignment = WD_ALIGN_PARAGRAPH.CENTER
    p.add_run().add_picture(img_path, width=width)
    return p


def set_table_borders_and_padding(table, border_color='999999'):
    tblPr = table._tbl.tblPr
    borders = OxmlElement('w:tblBorders')
    for edge in ('top', 'left', 'bottom', 'right', 'insideH', 'insideV'):
        el = OxmlElement(f'w:{edge}')
        el.set(qn('w:val'), 'single')
        el.set(qn('w:sz'), '6')
        el.set(qn('w:space'), '0')
        el.set(qn('w:color'), border_color)
        borders.append(el)
    tblPr.append(borders)

    cell_mar = OxmlElement('w:tblCellMar')
    for side, val in (('top', '120'), ('bottom', '120'), ('left', '160'), ('right', '160')):
        el = OxmlElement(f'w:{side}')
        el.set(qn('w:w'), val)
        el.set(qn('w:type'), 'dxa')
        cell_mar.append(el)
    tblPr.append(cell_mar)


def create_report_box(doc, title):
    add_p(doc, title, bold=True, size_pt=12, space_before=10, space_after=4)
    table = doc.add_table(rows=1, cols=1)
    table.autofit = False
    table.columns[0].width = Inches(6.5)
    set_table_borders_and_padding(table)
    cell = table.rows[0].cells[0]
    cell.width = Inches(6.5)
    # Remove default empty paragraph
    p0 = cell.paragraphs[0]
    p0._element.getparent().remove(p0._element)
    return cell


def build_docx():
    doc = docx.Document()

    for section in doc.sections:
        section.top_margin = Inches(1.0)
        section.bottom_margin = Inches(1.0)
        section.left_margin = Inches(1.0)
        section.right_margin = Inches(1.0)

    # ================= COVER PAGE =================
    logo_stream = extract_umkt_logo()
    p_logo = doc.add_paragraph()
    p_logo.alignment = WD_ALIGN_PARAGRAPH.CENTER
    p_logo.paragraph_format.space_after = Pt(18)
    p_logo.add_run().add_picture(logo_stream, width=Inches(2.4))

    add_p(doc, 'Basic Programming Practicum', bold=True, size_pt=14, space_after=4, align=WD_ALIGN_PARAGRAPH.CENTER)
    add_p(doc, 'CSE1053', bold=True, size_pt=14, space_after=18, align=WD_ALIGN_PARAGRAPH.CENTER)
    add_p(doc, 'Practicum Report 10 : Header Files', bold=True, size_pt=15, space_after=36, align=WD_ALIGN_PARAGRAPH.CENTER)

    add_p(doc, 'By :', bold=True, size_pt=12, space_after=6, align=WD_ALIGN_PARAGRAPH.LEFT)
    add_p(doc, 'Al-Ghani Desta Setyawan', bold=True, italic=True, size_pt=12, space_after=4, align=WD_ALIGN_PARAGRAPH.LEFT)
    add_p(doc, 'NIM 2611102441026', bold=True, italic=True, size_pt=12, space_after=48, align=WD_ALIGN_PARAGRAPH.LEFT)

    add_p(doc, 'Teknik Informatika', size_pt=12, space_after=2, align=WD_ALIGN_PARAGRAPH.RIGHT)
    add_p(doc, 'Fakultas Sains & Teknologi', size_pt=12, space_after=2, align=WD_ALIGN_PARAGRAPH.RIGHT)
    add_p(doc, 'Universitas Muhammadiyah Kalimantan Timur', size_pt=12, space_after=8, align=WD_ALIGN_PARAGRAPH.RIGHT)
    add_p(doc, 'Samarinda, 2026', size_pt=12, space_after=0, align=WD_ALIGN_PARAGRAPH.RIGHT)

    doc.add_page_break()

    # ================= HEADER INFO =================
    add_p(doc, 'Practicum Report 10: Header Files', bold=True, size_pt=14, space_after=8)
    add_p(doc, 'Main Topic:', bold=True, size_pt=12, space_after=2)
    add_p(doc, 'Header Files in C++ (.h declarations & .cpp modular implementations).', size_pt=12, space_after=8)
    add_p(doc, 'Learning Objective:', bold=True, size_pt=12, space_after=2)
    add_p(doc, 'Implement header files from C++.', size_pt=12, space_after=12)

    # ================= TEST 10.1 =================
    c1 = create_report_box(doc, 'Code, Output, and Explanation 10.1 — Creating a Header and Using a Source File:')
    add_p(c1, 'A. Header File (cylinder.h):', bold=True, space_after=4)
    add_img(c1, os.path.join(ASSETS_DIR, 'code_10_1_h.png'), width=Inches(5.4))
    add_p(c1, 'B. Source File (cylinder.cpp):', bold=True, space_after=4)
    add_img(c1, os.path.join(ASSETS_DIR, 'code_10_1_cpp.png'), width=Inches(5.4))
    add_p(c1, 'C. Main Program (main.cpp):', bold=True, space_after=4)
    add_img(c1, os.path.join(ASSETS_DIR, 'code_10_1_main.png'), width=Inches(5.4))
    add_p(c1, 'D. Compiled Output:', bold=True, space_after=4)
    add_img(c1, os.path.join(ASSETS_DIR, 'output_10_1.png'), width=Inches(5.2))
    add_p(c1, 'E. Detailed Explanation:', bold=True, space_after=2)
    add_p(c1, '1. Preprocessing (#include "cylinder.h"): Preprocessor menggantikan baris #include "cylinder.h" di dalam main.cpp dan cylinder.cpp dengan isi file cylinder.h (deklarasi prototype double cylinderVolume(double r, double h);). Dengan begitu, compiler mengenali signature fungsi sebelum melihat definisinya.')
    add_p(c1, '2. Separate Compilation: Compiler mengompilasi main.cpp menjadi main.o dan cylinder.cpp menjadi cylinder.o secara terpisah. Pemanggilan cylinderVolume(7, 10) di main.o dicatat sebagai referensi simbol eksternal.')
    add_p(c1, '3. Linking: Linker menggabungkan main.o dan cylinder.o menjadi satu executable (main) dan mencocokkan referensi simbol cylinderVolume dengan implementasinya di cylinder.o sehingga menghasilkan output Cylinder Volume (r=7, h=10): 1538.6.')

    # ================= TEST 10.2 =================
    c2 = create_report_box(doc, 'Code, Output, and Explanation 10.2 — Using Return and Void Functions in a Header File:')
    add_p(c2, 'A. Header File (square.h):', bold=True, space_after=4)
    add_img(c2, os.path.join(ASSETS_DIR, 'code_10_2_h.png'), width=Inches(5.4))
    add_p(c2, 'B. Source File (square.cpp):', bold=True, space_after=4)
    add_img(c2, os.path.join(ASSETS_DIR, 'code_10_2_cpp.png'), width=Inches(5.4))
    add_p(c2, 'C. Main Program (main.cpp):', bold=True, space_after=4)
    add_img(c2, os.path.join(ASSETS_DIR, 'code_10_2_main.png'), width=Inches(5.4))
    add_p(c2, 'D. Compiled Output:', bold=True, space_after=4)
    add_img(c2, os.path.join(ASSETS_DIR, 'output_10_2.png'), width=Inches(5.2))
    add_p(c2, 'E. Difference Between Value-Returning Function and Void Function:', bold=True, space_after=2)
    add_p(c2, '1. Value-Returning Function (float squareArea(float s)): Mengembalikan hasil perhitungan bertipe float melalui pernyataan return s * s;. Nilainya dapat disimpan ke variabel (float area = squareArea(s);) atau digunakan di dalam ekspresi maupun fungsi lain.')
    add_p(c2, '2. Void Function (void displayResult(float s)): Tidak mengembalikan nilai apa pun. Fungsinya berperan sebagai prosedur untuk menjalankan aksi (mencetak sisi dan luas persegi ke layar) dan dipanggil sebagai statement berdiri sendiri.')

    # ================= TEST 10.3 =================
    c3 = create_report_box(doc, 'Code, Output, and Explanation 10.3 — Creating a Complete Arithmetic Header:')
    add_p(c3, 'A. Header File (arithmetic.h):', bold=True, space_after=4)
    add_img(c3, os.path.join(ASSETS_DIR, 'code_10_3_h.png'), width=Inches(5.4))
    add_p(c3, 'B. Source File (arithmetic.cpp):', bold=True, space_after=4)
    add_img(c3, os.path.join(ASSETS_DIR, 'code_10_3_cpp.png'), width=Inches(5.4))
    add_p(c3, 'C. Main Program (main.cpp — Fixed):', bold=True, space_after=4)
    add_img(c3, os.path.join(ASSETS_DIR, 'code_10_3_main.png'), width=Inches(5.4))
    add_p(c3, 'D. Compiled Output:', bold=True, space_after=4)
    add_img(c3, os.path.join(ASSETS_DIR, 'output_10_3.png'), width=Inches(5.2))
    add_p(c3, 'E. What Was Wrong and How It Was Fixed:', bold=True, space_after=2)
    add_p(c3, '1. Kesalahan pada kode modul: Baris ke-4 di main.cpp tertulis #include "arithmetic.hpp", padahal header file yang dibuat bernama arithmetic.h. Hal ini menyebabkan compile error: fatal error: \'arithmetic.hpp\' file not found.')
    add_p(c3, '2. Perbaikan: Mengubahnya menjadi #include "arithmetic.h" agar sesuai dengan header file yang tersedia, serta menambahkan validasi pembagian dengan nol (b == 0) di arithmetic.cpp.')

    # ================= TEST 10.4 =================
    c4 = create_report_box(doc, 'Code and Output 10.4 — Temperature Conversion Header (with Flexible Challenge):')
    add_p(c4, 'A. Header File (conversion.h):', bold=True, space_after=4)
    add_img(c4, os.path.join(ASSETS_DIR, 'code_10_4_h.png'), width=Inches(5.4))
    add_p(c4, 'B. Source File (conversion.cpp):', bold=True, space_after=4)
    add_img(c4, os.path.join(ASSETS_DIR, 'code_10_4_cpp.png'), width=Inches(5.4))
    add_p(c4, 'C. Main Program (main.cpp):', bold=True, space_after=4)
    add_img(c4, os.path.join(ASSETS_DIR, 'code_10_4_main.png'), width=Inches(5.4))
    add_p(c4, 'D. Compiled Output:', bold=True, space_after=4)
    add_img(c4, os.path.join(ASSETS_DIR, 'output_10_4.png'), width=Inches(5.2))
    add_p(c4, 'E. Implementation & Additional Challenge Notes:', bold=True, space_after=2)
    add_p(c4, '1. Mengimplementasikan empat fungsi dasar (celciusToFahrenheit, fahrenheitToCelcius, celciusToKelvin, kelvinToCelcius) serta memperbaiki typo penamaan celciusTofahrenheit pada contoh modul.')
    add_p(c4, '2. Additional Challenge: Menambahkan fahrenheitToKelvin(), kelvinToFahrenheit(), serta router fleksibel convertTemperature(value, fromScale, toScale) yang menormalisasi input ke skala Celcius lalu mengonversinya ke skala target (C, F, atau K secara case-insensitive).')

    # ================= TEST 10.5 =================
    c5 = create_report_box(doc, 'Code, Output, and Explanation 10.5 — Individual Task (2D Vector & Triangle Geometry Analyzer):')
    add_p(c5, 'A. Header File (geometry.h):', bold=True, space_after=4)
    add_img(c5, os.path.join(ASSETS_DIR, 'code_10_5_h.png'), width=Inches(5.4))
    add_p(c5, 'B. Source File (geometry.cpp):', bold=True, space_after=4)
    add_img(c5, os.path.join(ASSETS_DIR, 'code_10_5_cpp.png'), width=Inches(5.4))
    add_p(c5, 'C. Main Program (main.cpp):', bold=True, space_after=4)
    add_img(c5, os.path.join(ASSETS_DIR, 'code_10_5_main.png'), width=Inches(5.4))
    add_p(c5, 'D. Compiled Output:', bold=True, space_after=4)
    add_img(c5, os.path.join(ASSETS_DIR, 'output_10_5.png'), width=Inches(5.2))
    add_p(c5, 'E. Program Explanation:', bold=True, space_after=2)
    add_p(c5, '1. Studi Kasus: Aplikasi analisis geometri 2D dan segitiga menggunakan struct Point2D dengan pemisahan deklarasi di geometry.h dan implementasi di geometry.cpp.')
    add_p(c5, '2. Built-in Functions (<cmath>): Menggunakan pow() dan sqrt() pada euclideanDistance() & triangleArea() (rumus Heron), abs() pada manhattanDistance() & classifyTriangle(), fmax() pada chebyshevDistance(), serta atan2() & acos() pada slopeAngleDegrees().')
    add_p(c5, '3. User-Defined Functions: Seluruh fungsi komputasi dan prosedur displayAnalysis() dipanggil secara modular dari main.cpp melalui #include "geometry.h".')

    # ================= CONCLUSION =================
    cc = create_report_box(doc, "Conclusion of Today's Lesson:")
    add_p(cc, 'Dari praktikum mengenai Header Files dalam C++ hari ini, dapat disimpulkan bahwa:')
    add_p(cc, '1. Pemisahan Interface dan Implementasi: File header (.h) menyimpan deklarasi fungsi (prototype) dan guard (#ifndef/#define/#endif), sedangkan file sumber (.cpp) menyimpan implementasi lengkapnya.')
    add_p(cc, '2. Modularitas dan Reusability: Kode program menjadi lebih terstruktur, mudah dibaca, mudah dipelihara, serta memungkinkan fungsi-fungsi yang sama digunakan kembali di berbagai program tanpa duplikasi.')
    add_p(cc, '3. Proses Kompilasi Multi-File: Memahami bagaimana preprocessor (#include), separate compilation (.o), dan linker bekerja sama untuk menggabungkan banyak file C++ menjadi satu program executable.')

    doc.save(OUT_DOCX)
    print(f'Generated DOCX: {OUT_DOCX}')


if __name__ == '__main__':
    build_docx()
