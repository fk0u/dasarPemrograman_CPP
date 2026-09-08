#include <iostream>
#include <string>

int main() {
  std::string full_name = "Al-Ghani Desta Setyawan";

  // This is a comment
  std::cout << "Hello, " << full_name << "!"
            << std::endl; // This is also a comment

  /*
  This is multi-line comment
  It can span across multiple line
  */

  std::cout << "Hello, Try your name!" << std::endl;

  /*
  This is a multi-line comment
  All text enclosed within a block comment
  will be ignored by the compiler
  */
  return 0;
}