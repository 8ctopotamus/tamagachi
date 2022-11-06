#ifndef TAMAGACHI_H
#define TAMAGACHI_H

#include <iostream>

using namespace std;

class Tamagachi {
  public:
    Tamagachi(string name);
    void draw();
    bool heartbeat();
    bool isAlive();
  private:
    string name{};
    int age{0};
    int hp{100};
    bool sleeping{false};
    int mood{5};
    int moodDuration{5};
    string thought{"Hello!"};
    bool _isAlive();
    void _drawCharacter();
    void _printStats();
    bool _wantsSomething();
    int _getRandInt(int max);
};

#endif