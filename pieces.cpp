#include "pieces.h"

Piece::Piece()
{
  for(int i=0;i<4;i++){components[i]=-1;}
}
Piece::Piece(PJeton val1)
{
  components[0]=val1;
  for(int i=1;i<4;i++){components[i]=-1;}
}
Piece::Piece(PJeton val1, PJeton val2)
{
  components[0]=val1;
  components[1]=val2;
  for(int i=2;i<4;i++){components[i]=-1;}
}
Piece::Piece(PJeton val1, PJeton val2, PJeton val3)
{
  components[0]=val1;
  components[1]=val2;
  components[2]=val3;
  components[3]=-1;
}
Piece::Piece(PJeton val1, PJeton val2, PJeton val3, PJeton val4)
{
  components[0]=val1;
  components[1]=val2;
  components[2]=val3;
  components[3]=val4;
}

string Piece::learnPiece()
{
  ostringstream oss;  
  string response;

  oss<<"("<<components[0]<<","<<
    components[1]<<","<<
    components[2]<<","<<
    components[3]<<")";

  response = oss.str();

  return response;
}

