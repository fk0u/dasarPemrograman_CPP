#include <iostream>

int main() {
  int x = 10;
  int y = 3;

  std::cout << "Addition: " << x + y << std::endl;
  std::cout << "Subtraction: " << x - y << std::endl;
  std::cout << "Multiplication: " << x * y << std::endl;
  std::cout << "Division: " << x / y << std::endl;
  std::cout << "Modulus: " << x % y << std::endl;

  x++;
  y--;
  std::cout << "Incerement: " << x << std::endl;
  std::cout << "Decrement: " << y << std::endl;

  return 0;
}