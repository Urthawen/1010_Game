#include "score.h"


Score::Score(){scorePlayer=0;}

void Score::setScore(int points){
  switch(points){
  case 0:
    break;
  case 1:
    scorePlayer+=10;
    break;
  case 2:
    scorePlayer+=25;
    break;
  case 3:
    scorePlayer+=45;
    break;
  case 4:
    scorePlayer+=60;
    break;
  case 5:
    scorePlayer+=75;
    break;
  case 6:
    scorePlayer+=90;
    break;
  }
}

int Score::getScore(){
  return scorePlayer;
}

void Score::refresh(Window *window, int score){
  ostringstream oss;  
  string scoreFinal;

  oss<<score;
  scoreFinal = oss.str();
  
  window->clear();
  window->print(1,1,"Score", WGREEN);
  window->print(1,2,scoreFinal);

  return;
}
