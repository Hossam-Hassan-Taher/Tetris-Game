#pragma once
#include "grid.h"
#include "shapes.cpp"


class Game
{
private:
   std :: vector<Bloks> Blocks ; 
   Bloks currentBlock ; 
   Bloks nextBlock ; 
   bool InvalidBlock() ; 
   void RotateBlock();
   void Undo_Rotate_Block();
   void LockBlock();
   bool Blockfits();
   void Reset(); 
   void update_score(int line , int moves); 
   Sound rotatesound ; 
   Sound clearsound ; 
   Sound Over ; 
public:
   Game() ;
   ~Game();
   Bloks Get_Rand_Block();
   void Get_Hand_Input() ;
   void move_left();
   void move_right();
   void move_down();
   int score ; 
   bool Gameover; 
   std :: vector<Bloks> Get_All_Blocks() ;
   void Draw();
   Grid grid ; 
   Music music;

};

