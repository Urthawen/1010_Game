#include "plateau.h"


Board::Board(){
  for(int i=0;i<100;i++){cellBoard[i]=0;}
}

void Board::readBoard(){
  for(int i=0;i<100;i++){cout<<cellBoard[i];}
  return;
}

void Board::insertPiece(Piece piece, int cellId){
  cellBoard[cellId]=1;
  cout<<cellId<<endl;
  return;
}

void Board::refresh(Window *window){
  int x,y;

  x=0;
  y=0;
  
  for(int i=0;i<100;i++)
    {
      if(cellBoard[i]==1)
	{
	  window->print(y,x," ", BDEBUG);
	}
      if(y==9){y=0;x++;}
      else{y++;}
    }
  return;
}
