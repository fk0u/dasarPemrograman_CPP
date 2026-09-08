#include <iostream>

int main() {
  int a = 5; // 0101
  int b = 3; // 0011

  int and_result = a & b;
  std::cout << "AND Result: " << and_result << std::endl;

  int or_result = a | b;
  std::cout << "OR Result: " << or_result << std::endl;

  int xor_result = a ^ b;
  std::cout << "XOR Result: " << xor_result << std::endl;

  int not_result = ~a;
  std::cout << "NOT Result: " << not_result << std::endl;

  int shift_left_result = a << 1;
  std::cout << "Shift Left Result: " << shift_left_result << std::endl;

  int shift_right_result = a >> 1;
  std::cout << "Right Shift Result: " << shift_right_result << std::endl;

  return 0;
}