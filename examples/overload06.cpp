
#include <utility>

// with C++11 we have new opportunities

struct Horse {
  // don't care
};
void gate(Horse const &);
void gate(Horse &&);

void ollie(Horse &&horsie) {
  gate(horsie);            // lvalue
  gate(Horse{});           // rvalue (but really , prvalue)
  gate(std::move(horsie)); // rvalue (but really, xvalue)
}

int main() {}

void gate(Horse const &) {}
void gate(Horse &&) {}

/*
 * C++ Value Categories (C++11 and later)
 *
 *           expression
 *          /          \
 *     glvalue        rvalue
 *      /   \        /     \
 *  lvalue   \      /    prvalue
 *            \    /
 *            xvalue
 *
 * - glvalue: "generalized lvalue" (has identity)
 * - rvalue:  "right value" (can be moved from)
 * - lvalue:  has identity, cannot be moved (named variables)
 * - xvalue:  has identity, can be moved (expiring values, std::move)
 * - prvalue: no identity, can be moved (literals, temporary objects)
 */
