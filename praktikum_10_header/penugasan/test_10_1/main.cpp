// main.cpp
#include <iostream>
#include <string>
#include "cylinder.h" // Mengimpor deklarasi fungsi cylinderVolume()

using namespace std;

// Fungsi utama program untuk menguji perhitungan volume tabung
int main()
{
    double radius = 7.0;
    double height = 10.0;

    // Memanggil fungsi cylinderVolume() yang implementasinya berada di cylinder.cpp
    cout << "Cylinder Volume (r=" << radius << ", h=" << height << "): "
         << cylinderVolume(radius, height) << endl;
    return 0;
}
