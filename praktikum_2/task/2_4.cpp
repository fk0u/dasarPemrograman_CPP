#include <iostream>

int main() {
  int x = 10;

  x += 5;
  std::cout << x << std::endl; // 15
  x -= 5;
  std::cout << x << std::endl; // 10
  x *= 2;
  std::cout << x << std::endl; // 20
  x /= 2;
  std::cout << x << std::endl; // 10
  x %= 3;
  std::cout << x << std::endl; // 1

  return 0;
}