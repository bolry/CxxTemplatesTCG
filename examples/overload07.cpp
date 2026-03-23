
class Clock {
public:
  void tick();
  void tick() const;
  void tock() const;
};

void run(Clock &ar_clock) {
  ar_clock.tick(); // who do we call?
  ar_clock.tock(); // and here?
}

int main() {}

void Clock::tick() {}
void Clock::tock() const {}
