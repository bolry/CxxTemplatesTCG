
struct Toy {
  void story1();
  void story2() &&;
  void story3() &;
};

int main() {
  Toy().story1(); // you are allowed rvalue Toy() implied lvalue of *this
  Toy().story2(); // rvalue Toy() version of function matches rvalue ref *this
  // Toy().story3(); // rvalue Toy() is no match for a lvalue *this
}

void Toy::story1() {}
void Toy::story2() && {}
void Toy::story3() & {}
