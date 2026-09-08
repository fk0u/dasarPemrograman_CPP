#include <iostream>
#include <string>

using namespace std;

int main() {
  int a = 1024;
  short b = 32767;
  long c = 2147483647;
  float d = 2.34f;
  double e = 3.14;
  char f = 'M';
  bool g = true;
  std::string h = "Hello World!";
  auto i = "My name is Al-Ghani Desta Setyawan, nice too meet ya!!";

  const int j = 10;

  a = 12;

  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << c << std::endl;
  std::cout << d << std::endl;
  std::cout << e << std::endl;
  std::cout << f << std::endl;
  std::cout << g << std::endl;
  std::cout << h << std::endl;
  std::cout << i << std::endl;
  std::cout << j << std::endl;

  return 0;
}