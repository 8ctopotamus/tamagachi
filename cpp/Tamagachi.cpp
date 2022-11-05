#include <cstdlib>
#include <iostream>
#include <string>
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
  return _isAlive();
}

void Tamagachi::draw() {
  _drawCharacter();
  _printStats();
}

bool Tamagachi::_isAlive() {
  return hp > 0;
}

void Tamagachi::_printStats() {
  cout << "Name: " << name.c_str() << endl;
  cout << "HP: " << to_string(hp) << endl;
  cout << "Age: " << to_string(age) << endl;
}

void Tamagachi::_drawCharacter() {
  bool tickTock = age % 2 == 0;
  string ears = "  /\\___ \\\n";
  string face = tickTock ? " ^ U ^ " : " - _ - ";
  // string face =  ? "- . -" : ". _ .";
  if (!_isAlive()) {
    face = "x n x";
  }
  string leftArm = "/";
  string rightArm = "\\";
  string body = leftArm + "(" + face + ")" + rightArm + "\n";
  string legs = "   L   L\n";
  string drawing = "\n" + ears + body + legs + "\n";  
  cout << drawing << endl;
}