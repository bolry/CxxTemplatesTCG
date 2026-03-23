
void badSeparation(int);
void badSeparation(int &);
void badSeparation(int const &);

int main() {
  for (int i{42}; i != 52; ++i) {
    badSeparation(i);
  }
  badSeparation(53);
}
