
// only basic option in C++98
void oldSeparation(int &);
void oldSeparation(int const &);

int main() {
  for (int i{42}; i != 52; ++i) {
    oldSeparation(i);
  }
  oldSeparation(53);
}

#include <iostream>
void oldSeparation(int &ch) { std::cout << static_cast<char>(ch); }
void oldSeparation(int const &) { std::cout << "END\n"; }
