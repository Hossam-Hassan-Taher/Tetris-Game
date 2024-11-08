#pragma once
#include <vector>
#include <raylib.h>
using namespace std ;
class Grid{
public:
   Grid(); 
   void Initialize();
   void Print();
   void Draw(); 
   bool Invalid_Cell(int row , int col ); 
   bool IsEmptyCell(int row , int col); 
   int ClearFullRows();
   int grid[20][10]; 

private:
   int numRows ; 
   int numColms ; 
   int cellSize ;  
   vector < Color > colors;
   bool IsRowFull(int row);
   void ClearRow(int row);
   void MoveRow(int row , int NumRows ) ;
};