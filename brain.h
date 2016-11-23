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

#endif
