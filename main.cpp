#include "window.h"
#include "pieces.h"
#include "plateau.h"
#include "score.h"
#include "brain.h"
#include <string.h>
#include <cstdlib>
#include <ctime>

void game(){
  
  /**VARIABLES**/
  int ch;                  //Lire le caractère claiver
  int h=10,w=10;           //Hauteur et larguer de la fenêtre Plateau
  srand(time(NULL));       //Random
  int pieceUse[3]={0,0,0}; //Lorsqu'une pièce est utilisée, l'id passe à 1
  int xPiece=4,yPiece=4;   //Position par défaut de la première pièce
  int currentCell=44;       //Cellule actuelle du joueur
  bool changePiece=true;   //Condition pour changer le pool de pièce
  int idPieceChoose=0;     //id de la pièce choisie par le joueur
  /*****/
  

  /**INIT_BOARD_SCORE**/
  Board boardGame;
  Score scorePlayer;
  /*****/
  
  /**INIT_WINDOW**/
  Window menu(4,30,1,0);
  Window bestScore(8,30,35,0);
  Window showPiece(19,21,1,7);
  Window plateau(h,w,28,15);
  Window scorePlayerW(5,20,41,15);
  /*****/
  
  /**CREATE_DEFAULT_PIECES**/
  Piece p1;
  Piece p2(JUP);
  Piece p3(JUP, JUP);
  Piece p4(JUP, JUP, JUP);
  Piece p5(JUP, JUP, JUP, JUP);
  Piece p6(JRIGHT);
  Piece p7(JRIGHT, JRIGHT);
  Piece p8(JRIGHT, JRIGHT, JRIGHT);
  Piece p9(JRIGHT, JRIGHT, JRIGHT, JRIGHT);
  Piece p10(JRIGHT, JDOWN);
  Piece p11(JDOWN, JRIGHT);
  Piece p12(JDOWN, JRIGHT, JDOWN);
  Piece p13(JRIGHT, JUP, JLEFT);
  Piece p14(JUP, JLEFT, JLEFT);
  
  Piece randomTable[14]={p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14};
  Piece pieceChoose[3]={};
  /*****/
  
  /**INIT_GAME**/
  initGame(&menu, &bestScore, &showPiece, &plateau, &scorePlayerW);
  randomChoose(randomTable, pieceChoose, &showPiece);
  pieceChoose[idPieceChoose].drawPiece(&plateau,xPiece,yPiece);
  /*****/
 
  
  while((ch = getch()) != 'q')
    {
      switch (ch) {
      case KEY_UP:
	if(AutPlayerMove(0, pieceChoose[idPieceChoose], currentCell)){
	  playerMove(0, &plateau, &currentCell, &xPiece, &yPiece, &boardGame, pieceChoose, idPieceChoose);
	}
	
	break;
      case KEY_DOWN:
	if(AutPlayerMove(1, pieceChoose[idPieceChoose], currentCell)){
	playerMove(1, &plateau, &currentCell, &xPiece, &yPiece, &boardGame, pieceChoose, idPieceChoose);
	}
	break;
      case KEY_LEFT:
	if(AutPlayerMove(2, pieceChoose[idPieceChoose], currentCell)){
	playerMove(2, &plateau, &currentCell, &xPiece, &yPiece, &boardGame, pieceChoose, idPieceChoose);
	}
	break;
      case KEY_RIGHT:
	if(AutPlayerMove(3, pieceChoose[idPieceChoose], currentCell)){
	playerMove(3, &plateau, &currentCell, &xPiece, &yPiece, &boardGame, pieceChoose, idPieceChoose);
	}
	break;
      case '\n':
	playerAction(&plateau,pieceUse,idPieceChoose,&boardGame,&scorePlayer,pieceChoose,currentCell);
        InteractionPiece(pieceUse,randomTable,pieceChoose,&currentCell,&xPiece,&yPiece,&idPieceChoose,&boardGame,&plateau,&scorePlayer,&scorePlayerW, &showPiece);	
	break;
      case '\t':
	rotationPiece(&plateau,&idPieceChoose,pieceChoose,&boardGame,xPiece,yPiece);
	break;
      }
    }
}


int main(int argc, char **argv){
  switch(argc){
  case 1:
    startProgramX();
    game();
    stopProgramX();
    break;
  case 2:
    displayOption(argv);
    break;
  default:
    cout<<"== ERROR == Vous avez mis trop d'arguments à la suite. (--help, --version ou --authors)"<<endl;
    break;
  }  
  return 0;
}
