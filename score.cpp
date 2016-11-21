#include "score.h"


Score::Score(){scorePlayer=0;}

void Score::setScore(int points){
  scorePlayer+=points;
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
