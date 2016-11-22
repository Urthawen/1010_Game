#ifndef __PLATEAU_H
#define __PLATEAU_H
#include <iostream>
#include "window.h"
#include "pieces.h"

using namespace std;

class Board{

 private:

  short int cellBoard[100];
  
 public:
  Board();
  void readBoard();
  void refresh(Window *window);
  void insertPiece(Piece piece, int cellId, int currentPiece, int *pieceUse);
  int checkLF(Piece piece, int currentCell);
  void destroyLine(int i);
  void destroyLine(int i, int *exception);
  void destroyField(int i);
  void destroyLineField(int i, int j);
  
};

#endif
