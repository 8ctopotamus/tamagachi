#include <iostream>
#include "Tamagachi.h"

using namespace std;

Tamagachi::Tamagachi(string n):
  name{n}
{

}

bool Tamagachi::heartbeat() {
  age++;
  hp--;
  return true;
}

bool Tamagachi::isAlive() {
  return hp > 0;
}

void Tamagachi::draw() {

}

void Tamagachi::printStats() {
  cout << name.c_str() << endl;
  cout << "HP: " + hp << endl;
}