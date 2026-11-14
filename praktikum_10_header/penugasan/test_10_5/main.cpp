// main.cpp
#include <iostream>
#include "geometry.h" // Mengimpor struct Point2D serta seluruh fungsi analisis geometri

using namespace std;

int main()
{
    // Inisialisasi tiga titik koordinat 2D untuk membentuk segitiga siku-siku 3-4-5
    Point2D a = { 1.0, 2.0 };
    Point2D b = { 4.0, 6.0 };
    Point2D c = { 4.0, 2.0 };

    // Memanggil prosedur analisis lengkap dari geometry.cpp melalui geometry.h
    displayAnalysis(a, b, c);
    return 0;
}
