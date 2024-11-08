#include "grid.h"
#include <iostream>
#include "colors.h"

using namespace std ; 
Grid::Grid()
{
    numRows = 20 ; 
    numColms = 10 ; 
    cellSize = 30 ; 
    Initialize(); 
    colors = Get_Cell_Color(); 
};

void Grid::Initialize(){
    for(int Row = 0 ; Row < numRows ; Row++){
        for(int Col = 0 ; Col < numColms ; Col++){
            grid[Row][Col] = 0 ; 
        }
    }
};

void Grid::Print(){
     for(int Row = 0 ; Row < numRows ; Row++){
        for(int Col = 0 ; Col < numColms ; Col++){
            cout << grid[Row][Col] << " " ; 
        }
        cout << endl ; 
    }
};



void Grid::Draw(){
   for(int Row = 0 ; Row < numRows ; Row++){
        for(int Col = 0 ; Col < numColms ; Col++){
            int val = grid[Row][Col]; 
            DrawRectangle(Col*cellSize+11 , Row*cellSize+11 , cellSize-1 , cellSize-1 , colors[val]); 
        }
        
    }
}
bool Grid::Invalid_Cell(int row, int col)
{
    if (row >= 0 && row < numRows && col >= 0 && col < numColms ){
        return false ; 
    }
    return true ; 
}
bool Grid::IsEmptyCell(int row , int col )
{
    if(grid[row][col] == 0){
        return true ;
    }
    return false;
}
int Grid::ClearFullRows()
{
    int NumRows = 0;
    for(int row = numRows - 1 ; row >= 0 ; row--){
        if(IsRowFull(row)){
            ClearRow(row);
            NumRows++; 
        }
        else if (NumRows > 0){
            MoveRow(row , NumRows); 
        }
        
    }
    return NumRows;
}
bool Grid::IsRowFull(int row)
{
    for(int col = 0 ; col < numColms ; col++){
        if (grid[row][col] == 0){
            return false ; 
        }
    }
    return true ; 
}
void Grid::ClearRow(int row) {
    for(int col = 0 ; col < numColms ; col++){
        grid[row][col] = 0 ; 
    }

}
void Grid::MoveRow(int row, int NumRows) {
    for(int col = 0 ; col < numColms ; col++){
        grid[row + NumRows][col] = grid[row][col]; 
    }
    ClearRow(row); 
};