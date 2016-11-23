#include "brain.h"

void initGame(Window *menu, Window *bScore, Window *showP, Window *board, Window *scoreP){
  initMenu(menu);
  initBScore(bScore);
  initShowP(showP);
  initBoard(board);
  initScoreP(scoreP);
}

void initMenu(Window *window){
  window->setCouleurBordure(BRED);
  window->print(1,1,"Urthawen",WRED);
  window->print(1,2,"Push 'Q' for quit");
  window->print(1,3,"Push 'S' for save");
  return;
}
void initBScore(Window *window){
  window->setCouleurBordure(BRED);
  window->print(1,1,"Bests Score", WRED);
  window->print(1,2," 15245\t Urthawen");
  window->print(1,3," 13215\t FreeLP");
  window->print(1,4," 11124\t Brouken");
  window->print(1,5," 9758\t Rozsas");
  window->print(1,6," 9574\t Spitalas");
  return;
}
void initShowP(Window *window){
  window->setCouleurBordure(WGREEN);
  window->print(2,1,"Pieces Availables", WGREEN);
  return;
}
void initBoard(Window *window){
  window->setCouleurBordure(BBLUE);
  return;
}
void initScoreP(Window *window){
  window->setCouleurBordure(WGREEN);
  window->print(1,1,"Score", WGREEN);
  window->print(1,2,"0");
  return;
}

void randomChoose(Piece *randomTable, Piece *pieceChoose, Window *window){  
  srand(time(NULL));
  int randomNumber =0;
  int chooseId=0;
  int pieceBan[14]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  
  while(chooseId<3)
    {
      randomNumber=rand()%14;
      if(pieceBan[randomNumber]==0)
	{
	  pieceBan[randomNumber]=1;
	  pieceChoose[chooseId]=randomTable[randomNumber];
	  chooseId++;
	}
    }

  pieceChoose[0].drawPiece(window,4,6);
  pieceChoose[1].drawPiece(window,14,6);
  pieceChoose[2].drawPiece(window,10,11);
}
