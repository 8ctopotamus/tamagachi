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
    bool timelimit = time2 - time1 > 1000; // 1 sec
    if (timelimit) {
      system("clear");
      time1 = clock();
      tama.draw();
      tama.heartbeat();
      string test{};
      printf("What do you want to do?");
      cin >> test;
      printf(test.c_str());
    }
  }

  printf("Your tamagachi has died!");
  getch();
  return 0;
}