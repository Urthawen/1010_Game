#include "brain.h"

void initGame(Window *menu, Window *bScore, Window *showP, Window *board, Window *scoreP, char *username){
  initMenu(menu, username);
  initBScore(bScore);
  initShowP(showP);
  initBoard(board);
  initScoreP(scoreP);
}

void initMenu(Window *window, char *username){
  window->setCouleurBordure(BRED);
  window->print(1,1,username,WRED);
  window->print(1,2,"Push 'Q' for quit");
  window->print(1,3,"Push 'S' for save");
  return;
}
void initBScore(Window *window){
  window->setCouleurBordure(BRED);
  window->print(1,1,"Bests Score", WRED);
  
  string data[10];
  int read=0;
  
  ifstream file("highscore.txt", ios::in);  // on ouvre le fichier en lecture 
        if(file)
        {
	  file >> data[0] >> data[1] >> data[2] >> data[3] >> data[4] >> data[5] >> data[6] >> data[7] >> data[8] >> data[9];
	  for(int i=2;i<7;i++){
	    window->print(2,i,data[read]);
	    read++;
	    window->print(12,i,data[read]);
	    read++;
	  }
	  file.close();  // on ferme le fichier
        }
        else{
	  cout << "Impossible d'ouvrir le fichier !" << endl;
	}
  //window->print(1,6," 9574\t Spitalas");
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
	*currentCell=44;
	*xPiece=4;
	*yPiece=4;
	if(*idPieceChoose==2){*idPieceChoose=0;}
	else{*idPieceChoose+=1;}	
	boardGame->refresh(plateau);
	pieceChoose[*idPieceChoose].drawPiece(plateau,*xPiece,*yPiece);
	scorePlayer->refresh(scorePlayerW, scorePlayer->getScore());
  
  return;
}


void rotationPiece(Window *plateau,int *idPieceChoose,Piece *pieceChoose,Board *boardGame,int *currentCell, int *xPiece, int *yPiece){

  plateau->clear();
  if(*idPieceChoose==2){*idPieceChoose=0;}
  else{*idPieceChoose+=1;}
  *currentCell = 44;
  *yPiece = 4;
  *xPiece = 4;
  boardGame->refresh(plateau);
  pieceChoose[*idPieceChoose].drawPiece(plateau,*xPiece,*yPiece);
  return;
}

void displayOption(char **argv){
  if(strcmp(argv[1],"--authors")==0){
    cout<<"****Authors****"<<endl;
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


bool AutPlayerMove(int mode, Piece piece, int currentCell){
  bool canMove=true;
  
  if(mode==0){
    if(currentCell<=9){
      return false;
    }
    int i=0;
    while(i<4 && canMove==true){
      switch(piece.getComponent(i)){
      case -1:
	break;
      case 0:
	currentCell+=10;
	if(currentCell<=9){
	  canMove=false;
	}
	break;
      case 1:
	currentCell-=10;
	if(currentCell<=9){
	  canMove=false;
	}
	break;
      case 2:
	currentCell--;
	if(currentCell<=9){
	  canMove=false;
	}
	break;
      case 3:
	currentCell++;
	if(currentCell<=9){
	  canMove=false;
	}
	break;
      }
      i++;
    }
  }
    else if(mode==1){
      if(currentCell>=90)
	{
	  return false;
	}
      int i=0;
    while(i<4 && canMove==true){
      switch(piece.getComponent(i)){
      case -1:
	break;
      case 0:
	currentCell+=10;
	if(currentCell>=90){
	  canMove=false;
	}
	break;
      case 1:
	currentCell-=10;
	if(currentCell>=90){
	  canMove=false;
	}
	break;
      case 2:
	currentCell--;
	if(currentCell>=90){
	  canMove=false;
	}
	break;
      case 3:
	currentCell++;
	if(currentCell>=90){
	  canMove=false;
	}
	break;
      }
      i++;
    }
    }
  
    else if(mode==2){
      if(currentCell%10==0)
	{
	  return false;
	}
      int i=0;
    while(i<4 && canMove==true){
      switch(piece.getComponent(i)){
      case -1:
	break;
      case 0:
	currentCell+=10;
	if(currentCell%10==0){
	  canMove=false;
	}
	break;
      case 1:
	currentCell-=10;
	if(currentCell%10==0){
	  canMove=false;
	}
	break;
      case 2:
	currentCell--;
	if(currentCell%10==0){
	  canMove=false;
	}
	break;
      case 3:
	currentCell++;
	if(currentCell%10==0){
	  canMove=false;
	}
	break;
      }
      i++;
    }
    }
    else if(mode==3){
      if((currentCell+1)%10==0)
	{
	  return false;
	}
      int i=0;
    while(i<4 && canMove==true){
      switch(piece.getComponent(i)){
      case -1:
	break;
      case 0:
	currentCell+=10;
	if((currentCell+1)%10==0){
	  canMove=false;
	}
	break;
      case 1:
	currentCell-=10;
	if((currentCell+1)%10==0){
	  canMove=false;
	}
	break;
      case 2:
	currentCell--;
	if((currentCell+1)%10==0){
	  canMove=false;
	}
	break;
      case 3:
	currentCell++;
	if((currentCell+1)%10==0){
	  canMove=false;
	}
	break;
      }
      i++;
    }
    }

  return canMove;
}


void gameContinue(Board boardGame, Piece *pieceChoose, int *pieceUse, bool *endGame){

  int cellTested;
  bool canPlace=true;
  int data;
  
  for(int i=0;i<3;i++){
    if(pieceUse[i]==0){
      for(int j=0;j<100;j++){
	if(boardGame.readCell(j)==0){
	  cellTested = j;
	  canPlace=true;
	  data=0;
	  while(data<4 && canPlace){
	    switch(pieceChoose[i].getComponent(data)){
	    case -1:
	      break;
	    case 0:
	      cellTested+=10;
	      if(cellTested<=99){
		 if(boardGame.readCell(cellTested)==1){canPlace = false;}
	      }
	      else{canPlace=false;}
	      break;
	    case 1:
	      cellTested-=10;
	      if(cellTested>=0){
		 if(boardGame.readCell(cellTested)==1){canPlace = false;}
	      }
	      else{canPlace=false;}
	      break;
	    case 2:
	      if(cellTested%10!=0){
		 cellTested--;
		 if(boardGame.readCell(cellTested)==1){canPlace = false;}
	      }	     
	      else{canPlace=false;}
	      break;
	    case 3:
	      if((cellTested+1)%10!=0){
		 cellTested++;
		 if(boardGame.readCell(cellTested)==1){canPlace = false;}
	      }	     
	      else{canPlace=false;}
	      break;
	    }//end_Switch
	    data++;
	  }//end_while
	  if(canPlace){return;}
	}//end_if	
      }//end_for (100)
    }//end_if
  }//end_for (3)

  *endGame=true;
  
  return;
}

int menu(){
   char ch;
   Window menu(10,30,1,0);
   menu.setCouleurBordure(BRED);
   menu.print(10,1,"1010 GAME", WRED);
   menu.print(2,3,"New game \t==> N");
   menu.print(2,4,"Load game \t==> P");
   menu.print(2,6,"Leave game \t==> Q");
   
   while((ch = getch()) != 'q')
    {
      switch(ch){
      case 'n':
	menu.deleteWindow();
	return 1;
	break;
      case 'p':
	menu.deleteWindow();
	return 2;
	break;
      default:
	break;
      }
    }

   return 0;
}


void checkHighscore(int score, char *username){
  int data[5];
  string usernameDt[5];

  ifstream readFile("highscore.txt", ios::in);
  if(readFile){
    readFile >> data[0] >> usernameDt[0] >> data[1] >> usernameDt[1] >> data[2] >> usernameDt[2] >> data[3] >> usernameDt[3] >> data[4] >> usernameDt[4];
    readFile.close();
  }
  
  fstream file("highscore.txt", ios::out | ios::trunc);
        if(file)
        {
	   if(score>data[0]){
	     data[4]=data[3];
	     usernameDt[4]=usernameDt[3];
	     
	     data[3]=data[2];
	     usernameDt[3]=usernameDt[2];
	     
	     data[2]=data[1];
	     usernameDt[2]=usernameDt[1];
	     
	     data[1]=data[0];
	     usernameDt[1]=usernameDt[0];
	     
	      data[0]=score;
	      usernameDt[0]=username;
	    }
	   else if(score>data[1]){
	      data[4]=data[3];
	     usernameDt[4]=usernameDt[3];
	     
	     data[3]=data[2];
	     usernameDt[3]=usernameDt[2];
	     
	     data[2]=data[1];
	     usernameDt[2]=usernameDt[1];
	     
	      data[1]=score;
	      usernameDt[1]=username;
	   }
	   else if(score>data[2]){
	      data[4]=data[3];
	     usernameDt[4]=usernameDt[3];
	     
	     data[3]=data[2];
	     usernameDt[3]=usernameDt[2];
	     
	      data[2]=score;
	      usernameDt[2]=username;
	   }
	   else if(score>data[3]){
	     data[4]=data[3];
	     usernameDt[4]=usernameDt[3];
	     
	      data[3]=score;
	      usernameDt[3]=username;
	   }
	   else if(score>data[4]){
	      data[4]=score;
	      usernameDt[4]=username;
	   }

	   for(int i=0;i<5;i++){
	    file << data[i] << " " << usernameDt[i]<< endl;
	   }
	  
	  file.close();  // on ferme le fichier
        }
        else{
	 cout << "Impossible d'ouvrir le fichier !" << endl;
	}
}


void saveGame(char *username, Piece *pieceChoose, int *pieceUse, Board boardGame, Score scorePlayer){  
   fstream file("save.txt", ios::out | ios::trunc);
   if(file){
     //save username
     file << username << endl;
     //save pieceChoose
     for(int i=0;i<3;i++){
       for(int j=0;j<3;j++){
	 file << pieceChoose[i].getComponent(j)<<",";
       }
       file << pieceChoose[i].getComponent(3)<<endl;
     }
     //save pieceUse
     for(int i=0;i<2;i++){
       file<<pieceUse[i]<<",";
     }
     file<<pieceUse[2]<<endl;
     //save boardGame
     for(int i=0;i<99;i++){
       file << boardGame.readCell(i) << ",";
     }
     file << boardGame.readCell(99)<<endl;
     //save score
     file << scorePlayer.getScore() <<endl;
   }
   else{
    cout << "error" << endl;
   }
  return;
}


void loadSave(Window *menu,Piece s1,Piece s2,Piece s3,Piece *pieceChoose,int *pieceUse,Window *showPiece,Board *boardGame,Window *plateau,Score *scorePlayer,Window *scorePlayerW){
  
  ifstream readFile("save.txt", ios::in);
  return;
}
