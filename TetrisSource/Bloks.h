#pragma once 
#include <vector>
#include <map> 
#include "Positions.h"
#include "colors.h"

using namespace std ; 

class Bloks
{
private:
  int cellSize ; 
  int state_rotation; 
  std :: vector<Color> colors; 
  int rowMove ; 
  int colMove ; 
public:
  int id ; 
  Bloks(); 
  void Draw(int offsetx, int offsety);
  void Rotate();
  void Undo_Rotate(); 
  void Move(int row , int col); 
  std::vector<Positions> Get_Cell_Position();
  map<int , vector<Positions>> Cells; 

};
