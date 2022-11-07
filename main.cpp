#include <iostream>
#include <chrono>
#include <thread>
#include "Tamagachi.h"

using namespace std;
using namespace std::chrono_literals;

int main(void) {
  Tamagachi tama{"Tama"};
  while (tama.isAlive()) {
    system("clear"); // clear screen
    tama.heartbeat();
    tama.draw();
    std::this_thread::sleep_for(1s);
  }
  return 0;
}