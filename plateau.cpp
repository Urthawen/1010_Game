#include "plateau.h"

Board::Board(){
  for(int i=0;i<100;i++){
    cellBoard[i] = 0;
  }
}

void Board::readBoard(){
  for(int i=0;i<100;i++){cout<<cellBoard[i];}
  return;
}

void Board::insertPiece(Piece piece, int cellId, int currentPiece, int *pieceUse){

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
	pieceUse[currentPiece]=1;
	
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

int Board::checkLF(Piece piece, int currentCell){
  int lineDestroy=0;
  int fieldDestroy=0;
  int points=0;

  int numberOfField=0;
  int count=0;
  
  for(int i=0;i<100;i++)
    {
      if((i)%10==0){count=0;}      
      if(cellBoard[i]==1){count++;}      
      if(count>=10){
	lineDestroy++;
	count=0;
      }
    }
  
  count=0;
  
  while(numberOfField<10){
    for(int i=numberOfField;i<100;i+=10)
      {
	if(cellBoard[i]==1){count++;}
	if(count>=10){
	  fieldDestroy++;
	  count=0;
	}
      }
    numberOfField++;
    count=0;
  }
  /***************/
  if(lineDestroy>=1 && fieldDestroy >=1){
    /*****POINTS_SYSTEM******/
    switch(lineDestroy){
    case 0:
      break;
    case 1:
      points+=10;
      break;
    case 2:
      points+=25;
      break;
    case 3:
      points+=45;
      break;
    case 4:
      points+=60;
      break;
    case 5:
      points+=75;
      break;
    case 6:
      points+=90;
      break;
    }
    switch(fieldDestroy){
      case 0:
      break;
    case 1:
      points+=10;
      break;
    case 2:
      points+=25;
      break;
    case 3:
      points+=45;
      break;
    case 4:
      points+=60;
      break;
    case 5:
      points+=75;
      break;
    case 6:
      points+=90;
      break;
    }

    points*=2;

    /************************/
    int exception[5]={-1,-1,-1,-1,-1};
    exception[0]=currentCell;
    for(int i=0; i<4; i++)
    {
      switch(piece.getComponent(i)){
      case -1:
	break;
      case 0:
	currentCell+=10;
        exception[i+1]=currentCell;
	break;
      case 1:
        currentCell-=10;
        exception[i+1]=currentCell;
	break;
      case 2:
        currentCell--;
        exception[i+1]=currentCell;
	break;
      case 3:
        currentCell++;
        exception[i+1]=currentCell;
	break;
      }
    }
    ////////EXECPETION FINISH
    
    count=0;
    for(int i=0;i<100;i++)
    {
      if((i)%10==0){count=0;}      
      if(cellBoard[i]==1){count++;}      
      if(count>=10){
	destroyLine(i-9, exception);
	count=0;
      }
    }

    count=0;
     numberOfField=0;
     while(numberOfField<10){
       for(int i=numberOfField;i<100;i+=10)
	 {
	   if(cellBoard[i]==1){count++;}
	   if(count>=10){
	     destroyField(i-90);
	     count=0;
	   }
	 }
       numberOfField++;
       count=0;
     }
    
  }
  /************************/
  /*LINE DESTROY >= 1******/
  else if(lineDestroy>=1){
    count=0;
    for(int i=0;i<100;i++)
    {
      if((i)%10==0){count=0;}      
      if(cellBoard[i]==1){count++;}      
      if(count>=10){
	destroyLine(i-9);
	count=0;
      }
    }
    switch(lineDestroy){
    case 0:
      break;
    case 1:
      points+=10;
      break;
    case 2:
      points+=25;
      break;
    case 3:
      points+=45;
      break;
    case 4:
      points+=60;
      break;
    case 5:
      points+=75;
      break;
    case 6:
      points+=90;
      break;
    }
  }
  /***********************/

  
  else if(fieldDestroy>=1){
     count=0;
     numberOfField=0;
     while(numberOfField<10){
       for(int i=numberOfField;i<100;i+=10)
	 {
	   if(cellBoard[i]==1){count++;}
	   if(count>=10){
	     destroyField(i-90);
	     count=0;
	   }
	 }
       numberOfField++;
       count=0;
     }
     switch(fieldDestroy){
    case 0:
      break;
    case 1:
      points+=10;
      break;
    case 2:
      points+=25;
      break;
    case 3:
      points+=45;
      break;
    case 4:
      points+=60;
      break;
    case 5:
      points+=75;
      break;
    case 6:
      points+=90;
      break;
    }
  }
  
  return points;
}

void Board::destroyLine(int i){
  for(int x=i;x<i+10;x++){
    cellBoard[x]=0;
  }
  return;
}

void Board::destroyLine(int i, int *exception){
  bool canDestroy = true;
  for(int x=i;x<i+10;x++){
    for(int j=0;j<5;j++)
      {
	if(x==exception[j]){canDestroy = false;} 
      }
    if(canDestroy==true){
      cellBoard[x]=0;
    }
    else{canDestroy=true;}
  }
}

void Board::destroyField(int i){
  for(int x=i;x<100;x+=10)
    {
      cellBoard[x]=0;
    }
  return;
}

void Board::destroyLineField(int i, int j){

}

int Board::readCell(int cell){
  return cellBoard[cell];
}

void Board::installSave(int cell, int data){
  cellBoard[cell]=data;
}
