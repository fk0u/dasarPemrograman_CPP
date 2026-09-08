#include <iostream>

int main() {
  bool correct = true;
  bool incorrect = false;

  // AND
  std::cout << (incorrect && correct) << std::endl;
  std::cout << (correct && correct) << std::endl;

  // OR
  std::cout << (correct || correct) << std::endl;
  std::cout << (correct || incorrect) << std::endl;
  std::cout << (true || false) << std::endl;

  // NOT
  std::cout << (!incorrect) << std::endl;
  std::cout << (!true) << std::endl;

  return 0;
}