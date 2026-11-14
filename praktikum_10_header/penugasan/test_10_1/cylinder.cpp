// cylinder.cpp
#include "cylinder.h"

// Implementasi fungsi cylinderVolume sesuai deklarasi di cylinder.h.
// Menghitung volume tabung menggunakan rumus: V = PI * r^2 * h
double cylinderVolume(double r, double h)
{
    const double PI = 3.14;
    return PI * r * r * h;
}
