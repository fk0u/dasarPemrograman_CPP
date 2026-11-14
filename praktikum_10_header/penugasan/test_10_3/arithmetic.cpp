// arithmetic.cpp
#include <iostream>
#include "arithmetic.h"

// Menjumlahkan dua bilangan bulat a dan b
int addition(int a, int b)
{
    return a + b;
}

// Mengurangkan bilangan b dari a
int subtraction(int a, int b)
{
    return a - b;
}

// Mengalikan dua bilangan bulat a dan b
int multiplication(int a, int b)
{
    return a * b;
}

// Membagi bilangan a dengan b secara aman (mencegah division by zero)
int division(int a, int b)
{
    if (b == 0)
    {
        std::cerr << "[Error] Division by zero is undefined!" << std::endl;
        return 0;
    }
    return a / b;
}
