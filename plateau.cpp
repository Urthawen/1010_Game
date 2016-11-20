#include "plateau.h"

Board::Board(){
  for(int i=0;i<100;i++){cellBoard[i]=0;}
}

void Board::readBoard(){
  for(int i=0;i<100;i++){cout<<cellBoard[i];}
  return;
}

void Board::insertPiece(Piece piece, int cellId){

  if(cellBoard[cellId]==0){
    int cell=cellId;
    int i=0;
    bool canInsert = true;

    while(i<4 && canInsert==true)
      {
	switch(piece.getComponent(i)){
      case -1:
	break;
      case 0:
	cell+=10;
        if(cellBoard[cell]==1){canInsert=false;}
	break;
      case 1:
	cell-=10;
        if(cellBoard[cell]==1){canInsert=false;}
	break;
      case 2:
	cell--;
        if(cellBoard[cell]==1){canInsert=false;}
	break;
      case 3:
	cell++;
        if(cellBoard[cell]==1){canInsert=false;}
	break;
      }
	i++;
      }

    if(canInsert==true)
      {
	cell=cellId;
	cellBoard[cell]=1;
	i=0;
	
	while(i<4 && piece.getComponent(i)!=-1){
    switch(piece.getComponent(i)){
      case -1:
	break;
      case 0:
        cell+=10;
	cellBoard[cell]=1;
	break;
      case 1:
        cell-=10;
	cellBoard[cell]=1;
	break;
      case 2:
        cell--;
	cellBoard[cell]=1;
	break;
      case 3:
        cell++;
	cellBoard[cell]=1;
	break;
          }
         i++;
	}
      }
  
  }
  
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

int Board::checkLine(){
  int lineNeedDestroy=0;
  int count=0;
  
  for(int i=0;i<100;i++)
    {
      if((i)%10==0){count=0;}      
      if(cellBoard[i]==1){count++;}      
      if(count>=10){
	destroyLine(i-9);
	lineNeedDestroy++;
	count=0;
      }
    }
  return lineNeedDestroy;
}

int Board::checkField(){

}

void Board::destroyLine(int i){
  for(int x=i;x<i+10;x++){
    cellBoard[x]=0;
  }
  return;
}

void Board::destroyField(){

}
