#ifndef __SCORE_H
#define __SCORE_H
#include <iostream>
#include <string.h>
#include <sstream>
#include "window.h"

using namespace std;

class Score{
 private:
  int scorePlayer;

 public:
  Score();
  void refresh(Window *window, int score);
  void setScore(int points);
  int getScore();
};


#endif
