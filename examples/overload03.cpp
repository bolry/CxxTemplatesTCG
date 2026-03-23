
#include <cstddef>

class BadString {
public:
  BadString(char const *) {}

  char &operator[](std::size_t) {
    static char a{'a'};
    return a;
  }

  char const &operator[](std::size_t) const {
    static constexpr char a{'b'};
    return a;
  }

  operator char *() {
    static char non[]{"non-const string"};
    return non;
  }

  operator char const *() { return "const string"; }
};

int main() {
  BadString str("correkt");
  str[5] = 'x'; // Is this really always OK?
}
