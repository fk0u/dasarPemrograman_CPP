#include <iostream>

int main() {
  int val1 = 5;
  int val2 = 3;
  int val3 = 5;

  // Equal to
  std::cout << (val1 == val2) << std::endl;
  std::cout << (val1 == val3) << std::endl;

  // Not equal
  std::cout << (val1 != val2) << std::endl;

  // Greater than
  std::cout << (val1 > val2) << std::endl;
  std::cout << (val2 > val1) << std::endl;

  // Less than
  std::cout << (val1 < val2) << std::endl;

  // Greater than or equal
  std::cout << (val1 >= val2) << std::endl;

  // Less than or equal
  std::cout << (val1 <= val2) << std::endl;

  return 0;
}