#include "window.h"
#include "pieces.h"
#include <string.h>
#include <cstdlib>
#include <ctime>

void game(){
  
  /*VARIABLES*/
  int ch;
  string DebugText;
  int h=10,w=10;
  /************/

  
  /*WINDOW_PARAMETERS*/
  Window menu(4,30,1,0);
  Window bestScore(8,30,35,0);
  Window showPiece(19,21,1,7);
  Window plateau(h,w,28,15);
  menu.setCouleurBordure(BRED);
  bestScore.setCouleurBordure(BRED);
  showPiece.setCouleurBordure(WGREEN);
  plateau.setCouleurBordure(BBLUE);

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

  showPiece.print(2,1,"Pieces Availables", WGREEN);
  /**************/

  
  /*PIECES_CREATE*/
  Piece p1;
  Piece p2(JDOWN, JRIGHT);
  Piece p3(JRIGHT, JRIGHT, JRIGHT, JUP);
  Piece p4(JRIGHT, JUP, JLEFT);
  Piece p5(JLEFT, JDOWN);
  /**************/

  /**Random_choose*/

  Piece randomTable[5]={p1, p2, p3, p4, p5};
  int pieceBan[5]={0,0,0,0,0};
  Piece pieceChoose[3]={};

  int chooseId=0;
  
  srand(time(NULL));
  while(chooseId<3)
    {
      int randomNumber=rand()%5;
      if(pieceBan[randomNumber]==0)
	{
	  pieceBan[randomNumber]=1;
	  pieceChoose[chooseId]=randomTable[randomNumber];
	  chooseId++;
	}
    } 
  
  //pieceChoose[0].drawPiece(&showPiece);
  

  /********/

  /*****DRAWING***/

  pieceChoose[0].drawPiece(&showPiece,4,6);
  pieceChoose[1].drawPiece(&showPiece,14,6);
  pieceChoose[2].drawPiece(&showPiece,10,11);
     

  /***************/


  int x=w/2,y=h/2;
  char p='X';
  Color col=WBLUE;
  plateau.print(x,y,p,col);
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
	plateau.print(x,y,' ');
	plateau.print(x,--y,p,col);
	break;
      case KEY_DOWN:
	plateau.print(x,y,' ');
	plateau.print(x,++y,p,col);
	break;
      case KEY_LEFT:
	plateau.print(x,y,' ');
	plateau.print(--x,y,p,col);
	break;
      case KEY_RIGHT:
	plateau.print(x,y,' ');
	plateau.print(++x,y,p,col);
	break;
      case '\n':
	x=w/2,y=h/2;
	p='X';
	plateau.print(x,y,p,col);
	//pieceChoose[0].drawPiece(&plateau,x,y);
	break;
      case '\t':
	Color tmp= menu.getCouleurBordure();
	menu.setCouleurBordure(plateau.getCouleurBordure());
	plateau.setCouleurBordure(tmp);
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
    cout<<"1010 - Version 0.6 ALPHA"<<endl;
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
