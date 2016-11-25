#include "brain.h"

void initGame(Window *menu, Window *bScore, Window *showP, Window *board, Window *scoreP){
  initMenu(menu);
  initBScore(bScore);
  initShowP(showP);
  initBoard(board);
  initScoreP(scoreP);
}

void initMenu(Window *window){
  window->setCouleurBordure(BRED);
  window->print(1,1,"Urthawen",WRED);
  window->print(1,2,"Push 'Q' for quit");
  window->print(1,3,"Push 'S' for save");
  return;
}
void initBScore(Window *window){
  window->setCouleurBordure(BRED);
  window->print(1,1,"Bests Score", WRED);
  window->print(1,2," 15245\t Urthawen");
  window->print(1,3," 13215\t FreeLP");
  window->print(1,4," 11124\t Brouken");
  window->print(1,5," 9758\t Rozsas");
  window->print(1,6," 9574\t Spitalas");
  return;
}
void initShowP(Window *window){
  window->setCouleurBordure(WGREEN);
  window->print(2,1,"Pieces Availables", WGREEN);
  return;
}
void initBoard(Window *window){
  window->setCouleurBordure(BBLUE);
  return;
}
void initScoreP(Window *window){
  window->setCouleurBordure(WGREEN);
  window->print(1,1,"Score", WGREEN);
  window->print(1,2,"0");
  return;
}

void randomChoose(Piece *randomTable, Piece *pieceChoose, Window *window){  
  srand(time(NULL));
  int randomNumber =0;
  int chooseId=0;
  int pieceBan[14]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  
  while(chooseId<3)
    {
      randomNumber=rand()%14;
      if(pieceBan[randomNumber]==0)
	{
	  pieceBan[randomNumber]=1;
	  pieceChoose[chooseId]=randomTable[randomNumber];
	  chooseId++;
	}
    }

  pieceChoose[0].drawPiece(window,4,6);
  pieceChoose[1].drawPiece(window,14,6);
  pieceChoose[2].drawPiece(window,10,11);
}


void playerMove(int mod, Window *plateau,int *currentCell,int *xPiece,int *yPiece,Board *boardGame,Piece *pieceChoose,int idPieceChoose){
  switch(mod){
  case 0:
    plateau->clear();
    *currentCell-=10;
    *yPiece-=1;
    boardGame->refresh(plateau);    
    pieceChoose[idPieceChoose].drawPiece(plateau,*xPiece,*yPiece);
    break;
  case 1:
    plateau->clear();
    *currentCell+=10;
    *yPiece+=1;
    boardGame->refresh(plateau);
    pieceChoose[idPieceChoose].drawPiece(plateau,*xPiece,*yPiece);
    break;
  case 2:
    plateau->clear();
    *currentCell-=1;
    *xPiece-=1;
    boardGame->refresh(plateau);
    pieceChoose[idPieceChoose].drawPiece(plateau,*xPiece,*yPiece);
    break;
  case 3:
    plateau->clear();
    *currentCell+=1;
    *xPiece+=1;
    boardGame->refresh(plateau);
    pieceChoose[idPieceChoose].drawPiece(plateau,*xPiece,*yPiece);
    break;
  }
}


void playerAction(Window *plateau,int *pieceUse,int idPieceChoose,Board *boardGame,Score *scorePlayer,Piece *pieceChoose,int currentCell){

  
	plateau->clear();
	if(pieceUse[idPieceChoose]==0){
	  boardGame->insertPiece(pieceChoose[idPieceChoose], currentCell, idPieceChoose, pieceUse);
	  scorePlayer->setScore(boardGame->checkLF(pieceChoose[idPieceChoose], currentCell));
	}
  
  
  return;
}


void InteractionPiece(int *pieceUse,Piece *randomTable,Piece *pieceChoose,int *currentCell,int *xPiece,int *yPiece,int *idPieceChoose,Board *boardGame,Window *plateau,Score *scorePlayer,Window *scorePlayerW, Window *showPiece){
  int chooseId=0;
  int randomNumber=0;
  bool changePiece=true;
  int pieceBan[14]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};

  for(int i=0;i<3;i++)
	  {
	    if (pieceUse[i]==0){changePiece=false;}
	  }
	if(changePiece){
	  chooseId=0;
	  while(chooseId<3)
	    {
	      randomNumber=rand()%14;
	      if(pieceBan[randomNumber]==0)
		{
		  pieceBan[randomNumber]=1;
		  pieceChoose[chooseId]=randomTable[randomNumber];
		  chooseId++;
		}
	    }
	  
	  showPiece->clear();
	  pieceChoose[0].drawPiece(showPiece,4,6);
	  pieceChoose[1].drawPiece(showPiece,14,6);
	  pieceChoose[2].drawPiece(showPiece,10,11);

	  for(int i=0;i<3;i++){pieceUse[i]=0;}
	  for(int i=0;i<14;i++){pieceBan[i]=0;}
	}
	*currentCell=0;
	*xPiece=0;
	*yPiece=0;
	if(*idPieceChoose==2){*idPieceChoose=0;}
	else{*idPieceChoose+=1;}
	pieceChoose[*idPieceChoose].drawPiece(plateau,*xPiece,*yPiece);
	
	boardGame->refresh(plateau);
	scorePlayer->refresh(scorePlayerW, scorePlayer->getScore());
  
  return;
}


void rotationPiece(Window *plateau,int *idPieceChoose,Piece *pieceChoose,Board *boardGame,int xPiece,int yPiece){

  plateau->clear();
  if(*idPieceChoose==2){*idPieceChoose=0;}
  else{*idPieceChoose+=1;}
  pieceChoose[*idPieceChoose].drawPiece(plateau,xPiece,yPiece);
  boardGame->refresh(plateau);
  return;
}

void displayOption(char **argv){
  if(strcmp(argv[1],"--authors")==0){
    cout<<"***Authors****"<<endl;
    cout<<"=== Bouffard-Vercelli Florian"<<endl;
    cout<<"=== Husson Alexi"<<endl;
    cout<<"=== Capron Yvan"<<endl;
    cout<<"=== Lemaître Thomas"<<endl;
    }
  else if(strcmp(argv[1],"--help")==0){
    cout<<"A COMPLETER"<<endl;
  }
  else if(strcmp(argv[1],"--version")==0){
    cout<<"Jeu du 1010 - Version 1.9"<<endl;
  }
  else{
      cout<<"Commande non reconnue. Commandes disponible : (--help, --version et --authors)"<<endl;
    }
  
  return;
}

