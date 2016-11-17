#include "window.h"
#include "pieces.h"
#include <string.h>

void game(){
  
  /*VARIABLES*/
  int ch;
  string DebugText;
  int h=10,w=10;
  /************/

  
  /*WINDOW_PARAMETERS*/
  Window menu(4,30,1,0);
  Window score(4,30,35,0);
  Window showPiece(10,30,15,15);
  Window plateau(h,w,1,15);
  menu.setCouleurBordure(BRED);
  score.setCouleurBordure(BRED);
  showPiece.setCouleurBordure(WGREEN);
  plateau.setCouleurBordure(BBLUE);
  
  menu.print(1,1,"Jeu du 1010",WRED);
  menu.print(1,2,"Appuyez sur Q pour quitter");

  score.print(1,1,"Meilleur score", WRED);
  score.print(1,2,"15245");

  showPiece.print(6,1,"Pièces disponible", WGREEN);
  /**************/

  
  /*PIECES_CREATE*/
  Piece p1;
  Piece p2(JDOWN, JRIGHT);
  Piece p3(JRIGHT, JRIGHT, JRIGHT, JUP);
  /**************/
  
  int x=w/2,y=h/2;
  char p='X';
  Color col=WBLUE;
  plateau.print(x,y,p,col);

  p3.drawPiece(&showPiece);
  
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
	plateau.print(x,y,p,col);
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
  if(strcmp(argv[1],"--author")==0){
    cout<<"***Authors****"<<endl;
    cout<<"=== Bouffard-Vercelli Florian"<<endl;
    cout<<"=== Husson Alexi"<<endl;
    cout<<"=== Capron Yvan"<<endl;
    cout<<"=== Lemaître Thomas"<<endl;
    }
  else if(strcmp(argv[1],"--help")==0){
    cout<<"help"<<endl;
  }
  else if(strcmp(argv[1],"--version")==0){
    cout<<"version"<<endl;
  }
  else{
      cout<<"Commande non reconnue. Commandes disponible : (--help, --version et --author)"<<endl;
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
    cout<<"== ERROR == Vous avez mis trop d'arguments à la suite. (--help, --version ou --author)"<<endl;
    break;
  }  
  return 0;
}
