#include "Bloks.h"

Bloks :: Bloks(){
    cellSize = 30 ; 
    state_rotation = 0 ; 
    colors = Get_Cell_Color(); 
    rowMove = 0 ; 
    colMove = 0 ; 


}

void Bloks :: Draw(int offsetx , int offsety){
    std :: vector<Positions> tiles = Get_Cell_Position(); 
    for(Positions item : tiles){
        DrawRectangle(item.col * cellSize+ offsetx , item.row * cellSize+offsety , cellSize-1 , cellSize-1 , colors[id] ); 
        
    }
}
void Bloks::Rotate()
{
    state_rotation++; 
    if (state_rotation == 4){
        state_rotation = 0 ; 
    }
}

void Bloks::Undo_Rotate()
{
    state_rotation--;
    if(state_rotation == -1){
        state_rotation = 0 ; 
    }

}

void Bloks :: Move(int row , int col){
    rowMove += row ; 
    colMove += col ; 
}

std :: vector<Positions> Bloks :: Get_Cell_Position(){
    std :: vector<Positions> tiles = Cells[state_rotation]; 
    std :: vector<Positions> Moved_tiles ; 
    for(Positions item : tiles){
        Positions NewPos = Positions(item.row + rowMove , item.col + colMove); 
        Moved_tiles.push_back(NewPos); 
    }
    return Moved_tiles ; 
}