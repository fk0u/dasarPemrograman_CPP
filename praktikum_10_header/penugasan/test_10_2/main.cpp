// main.cpp
#include <iostream>
#include <string>
#include "square.h" // Mengimpor deklarasi squareArea() dan displayResult()

using namespace std;

int main()
{
    float s;
    cout << "Enter the length of the side: ";
    cin >> s;

    // Validasi agar panjang sisi bernilai positif
    if (s <= 0) {
        cout << "Error: Side length must be greater than 0." << endl;
        return 1;
    }

    // Memanggil fungsi bertipe return value (hasil dapat disimpan/diolah)
    float area = squareArea(s);
    (void)area; // Menandakan variabel sengaja dihitung sebelum ditampilkan oleh displayResult

    // Memanggil fungsi void untuk menampilkan hasil perhitungan ke layar
    displayResult(s);
    return 0;
}
