#include <iostream>
#include <time.h>
#include <conio.h>
#include "Tamagachi.h"

using namespace std;

time_t time2, time1 = clock();

int main(void) {
  Tamagachi tama{"Tama"};

  while (tama.isAlive()) {
    time2 = clock();
    bool timelimit = time2 - time1 > 1000; // pause 1 sec
    if (timelimit) {
      time1 = clock();
      system("clear"); // clear screen
      tama.heartbeat();
      tama.draw();
    }
  }
  printf("Your tamagachi has died!");
  tama.draw();
  getch();
  return 0;
}