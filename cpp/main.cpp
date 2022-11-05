#include <iostream>
#include "lib/Tamagachi.h"

using namespace std;

int main(void) {
  Tamagachi tama{"Tama"};

  // printf(tama.name.c_str());
  cout << tama.name.c_str() << "\n";

  return 0;
}