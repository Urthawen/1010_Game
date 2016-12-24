#include "window.h"
#include "pieces.h"
#include "plateau.h"
#include "score.h"
#include "brain.h"
#include <string.h>
#include <cstdlib>
#include <ctime>

void game(int gameMode){
  
  char *username = new char[10];
  /**USERNAME**/
  if(gameMode==0){
    std::cout<<"Insérez votre Pseudo : ";
    std::cin>>username;
    std::cout<<"\033[2J\033[1;1H"; //Clear window
  }
  else{
    ifstream readFile("save.txt", ios::in);
    if(readFile){
      readFile >> username;
    }
  }
 
  
  /**VARIABLES**/
  int ch;                  //Lire le caractère claiver
  int h=10,w=10;           //Hauteur et larguer de la fenêtre Plateau
  srand(time(NULL));       //Random
  int pieceUse[3]={0,0,0}; //Lorsqu'une pièce est utilisée, l'id passe à 1
  int xPiece=4,yPiece=4;   //Position par défaut de la première pièce
  int currentCell=44;       //Cellule actuelle du joueur
  bool changePiece=true;   //Condition pour changer le pool de pièce
  int idPieceChoose=0;     //id de la pièce choisie par le joueur
  bool endGame = false;
  /*****/
  

  /**INIT_BOARD_SCORE**/
  Board boardGame;
  Score scorePlayer;
  /*****/
  
  /**INIT_WINDOW**/
  startProgramX();
  Window menu(4,30,1,0);
  Window bestScore(8,30,35,0);
  Window showPiece(19,21,1,7);
  Window plateau(h,w,28,15);
  Window scorePlayerW(5,20,41,15);
  /*****/
  
  /**CREATE_PIECES**/
  Piece* randomTable = (Piece*)std::malloc(14*sizeof(Piece));
  loadConfig(randomTable);
  Piece pieceChoose[3]={};
  /*****/

  
  initGame(&menu, &bestScore, &showPiece, &plateau, &scorePlayerW, username);
  /**INIT_GAME**/
  if(gameMode==0){
    randomChoose(randomTable, pieceChoose, &showPiece);
    pieceChoose[idPieceChoose].drawPiece(&plateau,xPiece,yPiece);
  }
  else{
    Piece s1,s2,s3;
    loadSave(&menu, &s1, &s2, &s3, pieceChoose, pieceUse, &showPiece, &boardGame, &plateau, &scorePlayer, &scorePlayerW);
  }
  /*****/
 
  
  while((ch = getch()) != 'q' && !endGame)
    {
      switch (ch) {
      case KEY_UP:
	if(AutPlayerMove(0, pieceChoose[idPieceChoose], currentCell)){
	  playerMove(0, &plateau, &currentCell, &xPiece, &yPiece, &boardGame, pieceChoose, idPieceChoose);
	}
	
	break;
      case KEY_DOWN:
	if(AutPlayerMove(1, pieceChoose[idPieceChoose], currentCell)){
	playerMove(1, &plateau, &currentCell, &xPiece, &yPiece, &boardGame, pieceChoose, idPieceChoose);
	}
	break;
      case KEY_LEFT:
	if(AutPlayerMove(2, pieceChoose[idPieceChoose], currentCell)){
	playerMove(2, &plateau, &currentCell, &xPiece, &yPiece, &boardGame, pieceChoose, idPieceChoose);
	}
	break;
      case KEY_RIGHT:
	if(AutPlayerMove(3, pieceChoose[idPieceChoose], currentCell)){
	playerMove(3, &plateau, &currentCell, &xPiece, &yPiece, &boardGame, pieceChoose, idPieceChoose);
	}
	break;
      case '\n':
	playerAction(&plateau,pieceUse,idPieceChoose,&boardGame,&scorePlayer,pieceChoose,currentCell);
        InteractionPiece(pieceUse,randomTable,pieceChoose,&currentCell,&xPiece,&yPiece,&idPieceChoose,&boardGame,&plateau,&scorePlayer,&scorePlayerW, &showPiece);
        gameContinue(boardGame, pieceChoose, pieceUse, &endGame);
	break;
      case '\t':
	rotationPiece(&plateau,&idPieceChoose,pieceChoose,&boardGame,&currentCell, &xPiece, &yPiece);
	break;

      case 's':
	saveGame(username, pieceChoose, pieceUse, boardGame, scorePlayer);
	break;
      }
    }

  stopProgramX();
  cout<<"GAME OVER"<<endl;
  cout<<"Score : "<<scorePlayer.getScore()<<endl;
  checkHighscore(scorePlayer.getScore(), username);
}


int main(int argc, char **argv){
  int choice;
  
  switch(argc){
  case 1:
    std::cout<<"\033[2J\033[1;1H"; //Clear window
    startProgramX();
    choice = menu();
    stopProgramX();
    if(choice==1){
      game(0);
      stopProgramX();
    }
    else if(choice==2){
      game(1);
      stopProgramX();
    }
    break;
  case 2:
    displayOption(argv);
    break;
  default:
    cout<<"== ERROR == Vous avez mis trop d'arguments à la suite. (--help, --version ou --authors)"<<endl;
    break;
  }  
  return 0;
}
