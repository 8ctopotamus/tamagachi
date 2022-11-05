#include <iostream>
#include <time.h>
#include <conio.h>
#include "Tamagachi.h"

using namespace std;

time_t t2, t1 = clock();

int main(void) {
  Tamagachi tama{"Tama"};
  while (tama.isAlive()) {
    t2 = clock();
    if (t2-t1 > 1000) {
      printf("test\n");
      t1 = clock();
    }
  }

  printf("hello world");
  return 0;
}