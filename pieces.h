#ifndef __PIECE_H
#define __PIECE_H
#include <iostream>
#include <string>
#include <sstream>
#include "window.h"

using namespace std;

enum PJeton {
  JDOWN,   //place un jeton en bas
  JUP,     //place un jeton en haut
  JLEFT,   //place un jeton à gauche
  JRIGHT   //place un jeton à droite
};

class Piece{
 private:
  /*
    
   */
  int components[4];
  
  
 public:
  /*
    Une pièce peut être composée de plusieurs jetons:
        -piece_description possédera la position de chaque
	jetons de façon chronologique

	Exemple : pièce1 = (-1,-1,-1,-1) -> Pièce de 1 jeton
	p2 = (0,3,-1,-1) -> Pièce de 3 jetons (0,0;-1,0;-1,1)
	p3 = (0,3,1,3) -> Pièce de 5 jetons (MAX)
   */
  Piece();
  Piece(PJeton val1);
  Piece(PJeton val1, PJeton val2);
  Piece(PJeton val1, PJeton val2, PJeton val3);
  Piece(PJeton val1, PJeton val2, PJeton val3, PJeton val4);

  string learnPiece();
  void drawPiece(Window *window, int x, int y);
  
};



#endif
