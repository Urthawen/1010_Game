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
  int xPiece=0,yPiece=0;   //Position par défaut de la première pièce
  int currentCell=0;       //Cellule actuelle du joueur
  bool changePiece=true;   //Condition pour changer le pool de pièce
  int idPieceChoose=0;     //id de la pièce choisie par le joueur
  
       /***DELETE PLUS TARD**/
       int chooseId=0;
       int randomNumber=0;
       int pieceBan[14]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};
       /*******/ 
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
  /*****/


 
  pieceChoose[idPieceChoose].drawPiece(&plateau,xPiece,yPiece);
  
  while((ch = getch()) != 'q')
    {
      switch (ch) {
      case '1':
	
	break;
      case '2':
	break;
      case 'c':
	plateau.clear();
	break;
      case KEY_UP:
        plateau.clear();
	currentCell-=10;
	yPiece--;
	boardGame.refresh(&plateau);
	pieceChoose[idPieceChoose].drawPiece(&plateau,xPiece,yPiece);
	break;
      case KEY_DOWN:
	plateau.clear();
	currentCell+=10;
	yPiece++;
	boardGame.refresh(&plateau);
        pieceChoose[idPieceChoose].drawPiece(&plateau,xPiece,yPiece);
	break;
      case KEY_LEFT:
	plateau.clear();
	currentCell--;
	xPiece--;
	boardGame.refresh(&plateau);
        pieceChoose[idPieceChoose].drawPiece(&plateau,xPiece,yPiece);
	break;
      case KEY_RIGHT:
	plateau.clear();
	currentCell++;
	xPiece++;
	boardGame.refresh(&plateau);
        pieceChoose[idPieceChoose].drawPiece(&plateau,xPiece,yPiece);
	break;
      case '\n':	
	xPiece=0,yPiece=0;
	plateau.clear();
	if(pieceUse[idPieceChoose]==0){
	  boardGame.insertPiece(pieceChoose[idPieceChoose], currentCell, idPieceChoose, pieceUse);
	  scorePlayer.setScore(boardGame.checkLF(pieceChoose[idPieceChoose], currentCell));
	}
	
	for(int i=0;i<3;i++)
	  {
	    if (pieceUse[i]==0){changePiece=false;}
	  }
	if(changePiece){
	  chooseId=0;
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
  

	  /********/

	  /*****DRAWING***/
	  showPiece.clear();
	  pieceChoose[0].drawPiece(&showPiece,4,6);
	  pieceChoose[1].drawPiece(&showPiece,14,6);
	  pieceChoose[2].drawPiece(&showPiece,10,11);

	  for(int i=0;i<3;i++){pieceUse[i]=0;}
	  for(int i=0;i<14;i++){pieceBan[i]=0;}
	}
	changePiece=true;
	currentCell=0;
	if(idPieceChoose==2){idPieceChoose=0;}
	else{idPieceChoose++;}
	pieceChoose[idPieceChoose].drawPiece(&plateau,xPiece,yPiece);
	
	boardGame.refresh(&plateau);
	scorePlayer.refresh(&scorePlayerW, scorePlayer.getScore());
	break;
      case '\t':
	plateau.clear();
	if(idPieceChoose==2){idPieceChoose=0;}
	else{idPieceChoose++;}
	pieceChoose[idPieceChoose].drawPiece(&plateau,xPiece,yPiece);
	boardGame.refresh(&plateau);
	break;
      }
    }
}

void displayOption(char **argv){
  int ch;
  if(strcmp(argv[1],"--authors")==0){
    cout<<"***Authors****"<<endl;
    cout<<"=== Bouffard-Vercelli Florian"<<endl;
    cout<<"=== Husson Alexi"<<endl;
    cout<<"=== Capron Yvan"<<endl;
    cout<<"=== Lemaître Thomas"<<endl;
    }
  else if(strcmp(argv[1],"--help")==0){
    cout<<"A COMPLETER"<<endl;
  }
  else if(strcmp(argv[1],"--version")==0){
    cout<<"1010 - Version 1.1 ALPHA"<<endl;
  }
  else{
      cout<<"Commande non reconnue. Commandes disponible : (--help, --version et --authors)"<<endl;
    }
  
  return;
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
