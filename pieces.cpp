#include "pieces.h"

Piece::Piece()
{
  for(int i=0;i<4;i++){components[i]=-1;}
}
Piece::Piece(PJeton val1)
{
  components[0]=val1;
  for(int i=1;i<4;i++){components[i]=-1;}
}
Piece::Piece(PJeton val1, PJeton val2)
{
  components[0]=val1;
  components[1]=val2;
  for(int i=2;i<4;i++){components[i]=-1;}
}
Piece::Piece(PJeton val1, PJeton val2, PJeton val3)
{
  components[0]=val1;
  components[1]=val2;
  components[2]=val3;
  components[3]=-1;
}
Piece::Piece(PJeton val1, PJeton val2, PJeton val3, PJeton val4)
{
  components[0]=val1;
  components[1]=val2;
  components[2]=val3;
  components[3]=val4;
}

string Piece::learnPiece()
{
  ostringstream oss;  
  string response;

  oss<<"("<<components[0]<<","<<
    components[1]<<","<<
    components[2]<<","<<
    components[3]<<")";

  response = oss.str();

  return response;
}

void Piece::drawPiece(Window *window, int x, int y) {
  
  window->print(x,y,"X", WGREEN);
  for(int i=0; i<4; i++)
    {
      switch(components[i]){
      case -1:
	break;
      case 0:
	y++;
	window->print(x,y," ", WGREEN);
	break;
      case 1:
	y--;
	window->print(x,y," ", WGREEN);
	break;
      case 2:
	x--;
	window->print(x,y," ", WGREEN);
	break;
      case 3:
	x++;
	window->print(x,y," ", WGREEN);
	break;
      }
    }
  return;
}

int Piece::getComponent(int token){return components[token];}

void Piece::addComponent(int pos, PJeton token){
  components[pos]=token;
}
