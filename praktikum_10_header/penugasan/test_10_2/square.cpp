// square.cpp
#include <iostream>
#include <iomanip>
#include "square.h"

using namespace std;

// Menghitung luas persegi berdasarkan panjang sisi s.
// Mengembalikan nilai float hasil perkalian s * s.
float squareArea(float s)
{
    return s * s;
}

// Menampilkan ringkasan panjang sisi dan luas persegi secara terformat.
// Memanfaatkan fungsi squareArea(s) di dalam tubuh fungsi void.
void displayResult(float s)
{
    cout << fixed << setprecision(2);
    cout << "---------------------------" << endl;
    cout << "Square Side : " << s << endl;
    cout << "Square Area : " << squareArea(s) << endl;
    cout << "---------------------------" << endl;
}
