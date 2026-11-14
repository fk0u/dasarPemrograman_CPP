// geometry.h
#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <string>

// Merepresentasikan titik koordinat 2D pada bidang Kartesius (x, y)
struct Point2D {
    double x;
    double y;
};

// Menghitung jarak Euclidean (garis lurus) antara titik a dan b menggunakan pow() & sqrt()
double euclideanDistance(Point2D a, Point2D b);

// Menghitung jarak Manhattan (jarak grid) antara titik a dan b menggunakan abs()
double manhattanDistance(Point2D a, Point2D b);

// Menghitung jarak Chebyshev (maksimum selisih sumbu) menggunakan abs() & fmax()
double chebyshevDistance(Point2D a, Point2D b);

// Menghitung titik tengah (midpoint) antara dua koordinat a dan b
Point2D midpoint(Point2D a, Point2D b);

// Menghitung sudut kemiringan vektor (a -> b) dalam derajat menggunakan atan2()
double slopeAngleDegrees(Point2D a, Point2D b);

// Menghitung luas segitiga dari tiga titik (a, b, c) menggunakan rumus Heron dan sqrt()
double triangleArea(Point2D a, Point2D b, Point2D c);

// Mengklasifikasikan jenis segitiga (Equilateral, Isosceles, Scalene, atau Degenerate)
std::string classifyTriangle(Point2D a, Point2D b, Point2D c);

// Prosedur void untuk mencetak laporan analisis geometri 2D secara terformat
void displayAnalysis(Point2D a, Point2D b, Point2D c);

#endif
