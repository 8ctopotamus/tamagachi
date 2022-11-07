#include <cstdlib>
#include <iostream>
#include <string>
#include <time.h>
#include "Tamagachi.h"

using namespace std;

Tamagachi::Tamagachi(string n): 
  name{n}
{}

bool Tamagachi::isAlive() {
  return _isAlive();
}

void Tamagachi::draw() {
  _drawCharacter();
  _printStats();
}

bool Tamagachi::heartbeat() {
  if (_isAlive()) {
    mood = moodDuration <= 0 
      ? _getRandInt(10)
      : mood;
    moodDuration = moodDuration <= 0 
      ? _getRandInt(10)
      : moodDuration;
    if (mood > 9) {
      sleeping = false;
      thought = name + " wants to play!";
    } else if (mood < 9 && mood > 4) {
      thought = name + " is indifferent right now.";
      sleeping = false;
    } else {
      if (!sleeping) {
        thought = name + " fell asleep. ZzZzz";
      } else {
        thought = name + " sleep, gaining hp...";
      }
      sleeping = true;
      hp++;
    }
    age++;
    hp--;
    moodDuration--;
    return true;
  }
  return false;
}

bool Tamagachi::_wantsSomething() {
  cout << thought.c_str() << endl;
  string answer;
  cin >> answer;
  int reaction = (rand() % (2 - 1 + 1)) + 1;
  return reaction > 0;
}

bool Tamagachi::_isAlive() {
  return hp > 0;
}

void Tamagachi::_drawCharacter() {
  bool tickTock = age % 2 == 0;
  string zzz = sleeping ? "   zZzZzz..." : "";
  string ears = "  /\\___ \\" + zzz;
  string happyFace = " ^ U ^ ";
  string emotionlessFace = " - _ - ";
  string face = hp > 90 ? happyFace : emotionlessFace;
  string leftArm = "/";
  string rightArm = "\\";
  string body = leftArm + "(" + face + ")" + rightArm;
  string standing = "   L   L";
  string crouching = "   >   >";
  string legs = tickTock ? standing : crouching;
  if (!_isAlive()) {
    face = " x n x ";
    legs = "   <   >";
  } else if (sleeping) {
    face = tickTock ? " - . - " : " - _ - ";
    leftArm = ",";
    rightArm = ",";
    legs = "   J   J";
  }
  string drawing = "\n" + ears + "\n" + body + "\n" + legs + "\n";  
  cout << drawing << endl;
}

void Tamagachi::_printStats() {
  string sleepMsg = sleeping ? "Yes" : "No";
  if (!_isAlive()) {
    cout << "Your tamagachi has died!";
  }
  cout << thought.c_str() << endl;
  cout << "Mood: " << to_string(mood) << endl;
  cout << "Mood Duration: " << to_string(moodDuration) << endl;
  cout << "Name: " << name.c_str() << endl;
  cout << "HP: " << to_string(hp) << endl;
  cout << "Age: " << to_string(age) << endl;
  cout << "Asleep: " << sleepMsg << endl;
}

int Tamagachi::_getRandInt(int max = 100) {
  srand(time(NULL));
  return rand() % (max + 1);
}