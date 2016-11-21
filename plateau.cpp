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

int Board::checkLF(){
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
	destroyLine(i-9);
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

  if(lineDestroy>=1 && fieldDestroy >=1){
    //Bonus de points
  }

  /*LINE DESTROY >= 1******/
  else if(lineDestroy>=1){
    count=0;
    points++;
    for(int i=0;i<100;i++)
    {
      if((i)%10==0){count=0;}      
      if(cellBoard[i]==1){count++;}      
      if(count>=10){
	destroyLine(i-9);
	count=0;
      }
    }
  }
  /***********************/

  
  else if(fieldDestroy>=1){
     count=0;
     numberOfField=0;
     points++;
     while(numberOfField<10){
       for(int i=numberOfField;i<100;i+=10)
	 {
	   if(cellBoard[i]==1){count++;}
	   if(count>=10){
	     destroyField(i-90);
	     cout<<"lol"<<endl;
	     count=0;
	   }
	 }
       numberOfField++;
       count=0;
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

void Board::destroyField(int i){
  for(int x=i;x<100;x+=10)
    {
      cellBoard[x]=0;
    }
  return;
}

void Board::destroyLineField(int i, int j){

}
