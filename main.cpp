#include "window.h"
#include "pieces.h"
#include "plateau.h"
#include "score.h"
#include <string.h>
#include <cstdlib>
#include <ctime>

void game(){
  
  /*VARIABLES*/
  int ch;
  string DebugText;
  int h=10,w=10;
  /************/

  /*CREATE_BOARD*/
  Board boardGame;
  /*************/

  /*SCORE_PLAYER*/
  Score scorePlayer;
  /*************/

  
  /*WINDOW_PARAMETERS*/
  Window menu(4,30,1,0);
  Window bestScore(8,30,35,0);
  Window showPiece(19,21,1,7);
  Window plateau(h,w,28,15);
  Window scorePlayerW(5,20,41,15);
  
  menu.setCouleurBordure(BRED);
  bestScore.setCouleurBordure(BRED);
  showPiece.setCouleurBordure(WGREEN);
  plateau.setCouleurBordure(BBLUE);
  scorePlayerW.setCouleurBordure(WGREEN);

  /*MENU*/
  menu.print(1,1,"Urthawen",WRED);
  menu.print(1,2,"Push 'Q' for quit");
  menu.print(1,3,"Push 'S' for save");
  /************/

  /*BESTSCORE*/
  bestScore.print(1,1,"Bests Score", WRED);
  bestScore.print(1,2," 15245\t Urthawen");
  bestScore.print(1,3," 13215\t FreeLP");
  bestScore.print(1,4," 11124\t Brouken");
  bestScore.print(1,5," 9758\t Rozsas");
  bestScore.print(1,6," 9574\t Spitalas");
  /**********/

  scorePlayerW.print(1,1,"Score", WGREEN);
  scorePlayerW.print(1,2,"0");

  showPiece.print(2,1,"Pieces Availables", WGREEN);
  /**************/

  
  /*DEFAULT_PIECES_CREATE*/
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
  /**************/

  /**Random_choose*/

  Piece randomTable[14]={p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14};
  int pieceBan[14]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  Piece pieceChoose[3]={};

  int chooseId=0;
  
  srand(time(NULL));
  while(chooseId<3)
    {
      int randomNumber=rand()%14;
      if(pieceBan[randomNumber]==0)
	{
	  pieceBan[randomNumber]=1;
	  pieceChoose[chooseId]=randomTable[randomNumber];
	  chooseId++;
	}
    } 
  

  /********/

  /*****DRAWING***/

  pieceChoose[0].drawPiece(&showPiece,4,6);
  pieceChoose[1].drawPiece(&showPiece,14,6);
  pieceChoose[2].drawPiece(&showPiece,10,11);
     

  /***************/


  int xPiece=0,yPiece=0;
  Color col = BMAGENTA;
  char p ='X';
  int currentCell=0;
  int checkLine=0;
  
  int idPieceChoose=0;
  pieceChoose[idPieceChoose].drawPiece(&plateau,xPiece,yPiece);
  
  while((ch = getch()) != 'q')
    {
      switch (ch) {
      case '1':
	col=BMAGENTA;
	break;
      case '2':
	col=WCYAN;
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
	boardGame.insertPiece(pieceChoose[idPieceChoose], currentCell);
        scorePlayer.setScore(boardGame.checkLF(pieceChoose[idPieceChoose], currentCell));
	currentCell=0;
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
