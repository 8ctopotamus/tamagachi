#include <cstdlib>
#include <iostream>
#include <string>
#include "Tamagachi.h"

using namespace std;

Tamagachi::Tamagachi(string n): 
  name{n} 
{}

bool Tamagachi::heartbeat() {
  if (_isAlive()) {
    int min = 0;
    int max = 10;
    int mood = (rand() % (max - min + 1)) + min;
    if (mood > 9) {
      cout << name << " wants to play!" << endl;
      string toy;
      cin >> toy;
      cout << name << " likes the toy!" << toy;
      hp += 10;
      sleeping = false;
    } else if (mood < 9 && mood > 4) {
      cout << name << " is indifferent right now.";
      sleeping = false;
    } else {
      if (!sleeping) {
        cout << name << " fell asleep.";
      } else {
        cout << name << " is gaining energy while they sleep.";
      }
      sleeping = true;
      hp++;
    }
    age++;
    hp--;
    return true;
  }
  return false;
}

void Tamagachi::_drawCharacter() {
  bool tickTock = age % 2 == 0;
  string zzz = sleeping ? "   zZzZzz..." : "";
  string ears = "  /\\___ \\" + zzz;
  string face = tickTock ? " ^ U ^ " : " - _ - ";
  if (!_isAlive()) {
    face = " x n x ";
  } else if (sleeping) {
    face = tickTock ? " - . - " : " - _ - ";
  }
  string leftArm = "/";
  string rightArm = "\\";
  string body = leftArm + "(" + face + ")" + rightArm;
  string legs = "   L   L";
  string drawing = "\n" + ears + "\n" + body + "\n" + legs + "\n";  
  cout << drawing << endl;
}

void Tamagachi::_printStats() {
  string sleepMsg = sleeping ? "Yes" : "No";
  cout << "Name: " << name.c_str() << endl;
  cout << "HP: " << to_string(hp) << endl;
  cout << "Age: " << to_string(age) << endl;
  cout << "Asleep: " << sleepMsg << endl;
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