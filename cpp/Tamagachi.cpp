#include <iostream>
#include "Tamagachi.h"

using namespace std;

Tamagachi::Tamagachi(string n):
  name{n}
{

}


bool Tamagachi::heartbeat() {
  return true;
}

void Tamagachi::printStats() {
  printf(name.c_str());
  // cout << name.c_str() << endl;
}

void Tamagachi::draw() {

}