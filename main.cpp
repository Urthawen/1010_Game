#include "window.h"
#include "pieces.h"

void game(){
  int ch;
  string DebugText;
  int h=10,w=10;
  Window menu(3,30,1,0);
  Window debugUrtha(5,70,1,6);
  Window plateau(h,w,1,14);
  menu.setCouleurBordure(BRED);
  debugUrtha.setCouleurBordure(BDEBUG);
  plateau.setCouleurBordure(BBLUE);
  
  menu.print(1,1,"Tapez q pour quitter !!!",WRED);
  debugUrtha.print(1,1,"DEBUG_WINDOW", WBLACK);

  Piece p1;
  Piece p2(JDOWN, JRIGHT);
  Piece p3(JRIGHT, JRIGHT, JRIGHT, JUP);
  
  ostringstream oss;
  oss << "Jeton 1 = "<< p1.learnPiece();
  DebugText = oss.str();  
  debugUrtha.print(1,2,DebugText,WBLACK);

  oss.str("");
  oss.clear();
  oss << "Jeton 2 = "<< p2.learnPiece();
  DebugText = oss.str();  
  debugUrtha.print(1,3,DebugText,WBLACK);
  
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
