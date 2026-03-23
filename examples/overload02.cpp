/**
 * Who "wins" here?
 */

void whoWins(int, double);
void whoWins(long, int);

void question1() {
  // whoWins(1, 2);
  // STATUS: MUTUALLY ASSURED DESTRUCTION.
  // Both candidates have one "Golden Child" arg and one "Lateral Move" arg.
  // If the compiler can't pick a favorite, nobody gets to play.
}

/**
 * THE SELECTION COMMITTEE (Conversion Hierarchy):
 * 1. THE GOLDEN CHILD: Perfect match. No notes. (Ignore 'const' or 'volatile'
 *    baggage; we’re looking at the core soul here).
 * 2. THE CHAMELEON: Minor adjustments only. "I'm not an array, I'm a pointer
 *    with a promotion mindset."
 * 3. THE INTERN PROMOTIONS: Small types (char/short) putting on a suit to
 *    become an 'int' or 'double'. Standard upward mobility.
 * 4. THE LATERAL MOVE: Standard conversions. Changing departments from
 *    'int' to 'float' or 'Derived' to 'Base'. Serviceable, but uninspired.
 * 5. THE DESPERATION MOVE: User-defined conversions. Using a custom
 *    constructor to force a round peg into a square hole.
 * 6. THE "WHATEVER" CLAUSE: The Ellipsis (...). The 'Reply All' of functions.
 *    It accepts everyone, but respects no one.
 */

void question2() {
  int f2(int);
  int f2(double);
  f2(4);
  // VERDICT: The 'int' overload wins. A "Golden Child" beats a "Lateral Move"
  // every day of the week.
}

void question3() {
  int f3(int);
  int f3(char);
  f3(true);
  // VERDICT: 'int' wins. 'bool' to 'int' is a "Promotion" (Rank 3),
  // whereas 'bool' to 'char' is a "Standard Conversion" (Rank 4).
  // In C++, being an 'int' is considered a promotion. Life is hard.
}

class C {
public:
  C(int);
};
void question4() {
  int f4(C);
  int f4(...);
  f4(7);
  // VERDICT: 'C' wins. Even a "Desperation Move" (Rank 5) is
  // legally superior to the "Whatever Clause" (Rank 6).
}

template <typename T> class String {
public:
  String() = default;
  String(T const *);
};
template <typename T> String<T> truncate(String<T> const &, int);

// explicit specialization declarations
template <> String<char>::String(char const *) {}
template <> String<char> truncate<char>(String<char> const &, int) {
  return String<char>();
}

void question5() {
  String<char> str1;
  str1 = truncate<char>("I'm a string, but make it fashion.", 12);
  // STATUS: THE SPOON-FED SUCCESS.
  // You provided <char>. The compiler stops thinking and
  // starts obeying. No deduction required; just execution.

  // str2 = truncate("I'm a string, but make it fashion.>", 12);
  // STATUS: THE CRIPPLING INDECISION.
  // Deduction is a "What You See Is What You Get" department.
  // It sees 'const char*' but wants 'String<T>'. It refuses to
  // use a constructor to "find" T. It just gives up.
}

/**
 * SECTION: OVERKILL (The "I'm not touching that" files)
 */
template <typename T> void plausibilis(T &&, T &&);
template <typename T> void weird(T &&, double &&);

// explicit specialization declarations
template <> void plausibilis<double>(double &&, double &&) {}
template <> void plausibilis<double &>(double &, double &) {}

void question6() {
  plausibilis(2.72, 3.14); // T = double.
  double arg = 5.86;
  plausibilis(arg, arg); // T = double& (Reference Collapsing: The C++ Yoga).

  // plausibilis(arg, 3.14);
  // CONFLICT: First arg says T is 'double&', second says T is 'double'.
  // The compiler hates inconsistency more than it hates you.

  // weird(arg, arg);
  // DENIED: You can't bind a lvalue (arg) to a rvalue reference (double&&).
}

int main() {}

int f2(int) { return 0; }
int f2(double) { return 0; }
int f3(int) { return 0; }
int f3(char) { return 0; }
int f4(C) { return 0; }
int f4(...) { return 0; }
C::C(int) {}
