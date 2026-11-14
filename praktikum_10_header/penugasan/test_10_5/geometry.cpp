// geometry.cpp
#include <iostream>
#include <iomanip>
#include <cmath>
#include "geometry.h"

using namespace std;

// Menghitung jarak Euclidean: d = sqrt((x2 - x1)^2 + (y2 - y1)^2)
// Memanfaatkan built-in function pow() dan sqrt() dari <cmath>.
double euclideanDistance(Point2D a, Point2D b)
{
    return sqrt(pow(b.x - a.x, 2.0) + pow(b.y - a.y, 2.0));
}

// Menghitung jarak Manhattan: d = |x2 - x1| + |y2 - y1|
// Memanfaatkan built-in function abs() dari <cmath>.
double manhattanDistance(Point2D a, Point2D b)
{
    return abs(b.x - a.x) + abs(b.y - a.y);
}

// Menghitung jarak Chebyshev: d = max(|x2 - x1|, |y2 - y1|)
// Memanfaatkan built-in function abs() dan fmax() dari <cmath>.
double chebyshevDistance(Point2D a, Point2D b)
{
    return fmax(abs(b.x - a.x), abs(b.y - a.y));
}

// Mengembalikan titik tengah (midpoint) antara dua titik a dan b
Point2D midpoint(Point2D a, Point2D b)
{
    return { (a.x + b.x) / 2.0, (a.y + b.y) / 2.0 };
}

// Menghitung sudut arah (azimuth/slope angle) vektor dari titik a ke b dalam satuan derajat.
// Memanfaatkan built-in function atan2() dari <cmath>.
double slopeAngleDegrees(Point2D a, Point2D b)
{
    const double PI = acos(-1.0);
    return atan2(b.y - a.y, b.x - a.x) * (180.0 / PI);
}

// Menghitung luas segitiga ABC menggunakan rumus Heron:
// s = (AB + BC + CA) / 2, Luas = sqrt(s * (s - AB) * (s - BC) * (s - CA))
double triangleArea(Point2D a, Point2D b, Point2D c)
{
    double ab = euclideanDistance(a, b);
    double bc = euclideanDistance(b, c);
    double ca = euclideanDistance(c, a);
    double s = (ab + bc + ca) / 2.0;

    double radicand = s * (s - ab) * (s - bc) * (s - ca);
    // Menghindari nilai negatif kecil akibat presisi floating-point pada segitiga kolinear
    return (radicand <= 0.0) ? 0.0 : sqrt(radicand);
}

// Menentukan jenis segitiga berdasarkan perbandingan panjang ketiga sisinya dengan toleransi epsilon
string classifyTriangle(Point2D a, Point2D b, Point2D c)
{
    if (triangleArea(a, b, c) < 1e-9) {
        return "Degenerate (Collinear Points)";
    }

    double ab = euclideanDistance(a, b);
    double bc = euclideanDistance(b, c);
    double ca = euclideanDistance(c, a);
    const double EPS = 1e-6;

    bool eqAB_BC = abs(ab - bc) < EPS;
    bool eqBC_CA = abs(bc - ca) < EPS;
    bool eqCA_AB = abs(ca - ab) < EPS;

    if (eqAB_BC && eqBC_CA) return "Equilateral (Sama Sisi)";
    if (eqAB_BC || eqBC_CA || eqCA_AB) return "Isosceles (Sama Kaki)";
    return "Scalene (Sembarang)";
}

// Menampilkan laporan lengkap analisis segmen AB serta segitiga ABC ke layar
void displayAnalysis(Point2D a, Point2D b, Point2D c)
{
    Point2D mid = midpoint(a, b);

    cout << fixed << setprecision(2);
    cout << "=== 2D Vector & Triangle Geometry Analyzer ===" << endl;
    cout << "Point A           : (" << a.x << ", " << a.y << ")" << endl;
    cout << "Point B           : (" << b.x << ", " << b.y << ")" << endl;
    cout << "Point C           : (" << c.x << ", " << c.y << ")" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Euclidean Dist AB : " << euclideanDistance(a, b) << endl;
    cout << "Manhattan Dist AB : " << manhattanDistance(a, b) << endl;
    cout << "Chebyshev Dist AB : " << chebyshevDistance(a, b) << endl;
    cout << "Midpoint AB       : (" << mid.x << ", " << mid.y << ")" << endl;
    cout << "Slope Angle A->B  : " << slopeAngleDegrees(a, b) << " deg" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Triangle ABC Area : " << triangleArea(a, b, c) << endl;
    cout << "Triangle Type     : " << classifyTriangle(a, b, c) << endl;
    cout << "==============================================" << endl;
}
