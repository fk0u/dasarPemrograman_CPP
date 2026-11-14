// main.cpp
#include <iostream>
#include <string>
#include "arithmetic.h" // PERBAIKAN: Sebelumnya salah tertulis "arithmetic.hpp"

using namespace std;

// Prosedur untuk menampilkan seluruh hasil operasi aritmetika antara a dan b
void displayResult(int a, int b)
{
    cout << "=== Arithmetic Operations (" << a << ", " << b << ") ===" << endl;
    cout << "Addition Result       : " << addition(a, b) << endl;
    cout << "Subtraction Result    : " << subtraction(a, b) << endl;
    cout << "Multiplication Result : " << multiplication(a, b) << endl;
    cout << "Division Result       : " << division(a, b) << endl;
}

int main()
{
    int a = 10, b = 5;
    displayResult(a, b);
    return 0;
}
