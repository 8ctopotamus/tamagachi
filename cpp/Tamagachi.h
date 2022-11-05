#ifndef TAMAGACHI_H
#define TAMAGACHI_H

#include <iostream>
using namespace std;

class Tamagachi {
  public:
    Tamagachi(string name);
    void draw();
    bool heartbeat();
    void printStats();
    bool isAlive();
  private:
    string name{};
    int age{0};
    int hp{0};
};

#endif