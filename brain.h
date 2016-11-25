#ifndef __BRAIN_H
#define __BRAIN_H
#include "window.h"
#include "plateau.h"
#include "score.h"
#include "pieces.h"
#include <cstdlib>
#include <ctime>

void initGame(Window *menu,
	      Window *bScore,
	      Window *showP,
	      Window *board,
	      Window *scoreP);

void initMenu(Window *window);
void initBScore(Window *window);
void initShowP(Window *window);
void initBoard(Window *window);
void initScoreP(Window *window);

void randomChoose(Piece *randomTable,
		  Piece *pieceChoose,
		  Window *showPiece);

/**
MOD   0 => MOVE_UP
      1 => MOVE_DOWN
      2 => MOVE_LEFT
      3 => MOVE_RIGHT

 **/
void playerMove(int mod,
		Window *plateau,
		int *currentCell,
		int *xPiece,
		int *yPiece,
		Board *boardGame,
		Piece *pieceChoose,
		int idPieceChoose);

void playerAction(Window *plateau,
		  int *pieceUse,
		  int idPieceChoose,
		  Board *boardGame,
		  Score *scorePlayer,
		  Piece *pieceChoose,
		  int currentCell);

void InteractionPiece(int *pieceUse,
		 Piece *randomTable,
		 Piece *pieceChoose,
		 int *currentCell,
		 int *xPiece,
		 int *yPiece,
		 int *idPieceChoose,
		 Board *boardGame,
		 Window *plateau,
		 Score *scorePlayer,
		 Window *scorePlayerW,
		 Window *showPiece);

void rotationPiece(Window *plateau,
		   int *idPieceChoose,
		   Piece *pieceChoose,
		   Board *boardGame,
		   int xPiece,
		   int yPiece);

#endif