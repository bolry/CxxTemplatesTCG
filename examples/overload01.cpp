
#include <iostream>

namespace {
  auto &ut = std::cout;
  void pr(int) { ut << "pr(int)\n"; }
  void pr(double) { ut << "pr(double)\n"; }
}

int main() {
  pr(42);
  pr(4.2);
}

/**
 * THE OVERLOAD TRIALS: A Five-Act Tragedy
 * 1. THE INVITATION: Gather the initial overload set (the hopefuls).
 * 2. THE MAKEOVER: Perform template deduction and argument adjustments.
 * 3. THE CULLING: Discard non-matches. If you can't implicitly convert,
 *    you're off the island.
 * 4. THE HIGHLANDER RULE: Perform resolution to find the *best* match.
 *    There can be only one; plurality is an Ambigous Error.
 * 5. THE FINAL INSULT: Check if the winner is private or =delete.
 *    The compiler wins; you get a diagnostic.
 */
