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
  return;
}

void Board::refresh(Window *window){
  return;
}
