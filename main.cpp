#include "window.h"
#include "pieces.h"

void game(){
  int ch;
  string DebugText;
  int h=10,w=10;
  Window menu(4,30,1,0);
  Window score(4,30,35,0);
  Window showPiece(10,30,15,15);
  Window debugUrtha(5,70,1,7);
  Window plateau(h,w,1,15);
  menu.setCouleurBordure(BRED);
  score.setCouleurBordure(BRED);
  debugUrtha.setCouleurBordure(BDEBUG);
  showPiece.setCouleurBordure(WGREEN);
  plateau.setCouleurBordure(BBLUE);
  
  menu.print(1,1,"Jeu du 1010",WRED);
  menu.print(1,2,"Appuyez sur Q pour quitter");

  score.print(1,1,"Meilleur score", WRED);
  score.print(1,2,"15245");

  showPiece.print(6,1,"Pièces disponible", WGREEN);
  
  debugUrtha.print(1,1,"DEBUG_WINDOW", WBLACK);

  Piece p1;
  Piece p2(JDOWN, JRIGHT);
  Piece p3(JRIGHT, JRIGHT, JRIGHT, JUP);
  
  ostringstream oss;
  oss << "Jeton 1 = "<< p1.learnPiece();
  DebugText = oss.str();  
  debugUrtha.print(1,2,DebugText);

  oss.str("");
  oss.clear();
  oss << "Jeton 2 = "<< p2.learnPiece();
  DebugText = oss.str();  
  debugUrtha.print(1,3,DebugText);
  
  int x=w/2,y=h/2;
  char p='X';
  Color col=WBLUE;
  plateau.print(x,y,p,col);



  p3.drawPiece(&showPiece);
  
  //END LEARNING BITCH
  
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

int main(){
  startProgramX();
  game();
  stopProgramX();
  return 0;
}
