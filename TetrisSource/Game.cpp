#include "Game.h"
#include <random>
using namespace std ; 
#include <iostream>
Game ::Game()
{
    grid = Grid(); 
    Blocks = Get_All_Blocks(); 
    currentBlock = Get_Rand_Block() ; 
    nextBlock = Get_Rand_Block() ;
    Gameover = false ; 
    score = 0 ; 
    InitAudioDevice();
    music = LoadMusicStream("resources/game-music-loop-19-153393.mp3");
    PlayMusicStream(music);
    rotatesound = LoadSound("resources/spring.wav");
    clearsound = LoadSound("resources/sound.wav");
    Over = LoadSound("resources/game-over-252897.mp3");
}
Game :: ~Game(){
    UnloadSound(rotatesound);
    UnloadSound(clearsound);
    UnloadMusicStream(music);
    CloseAudioDevice();
}


Bloks Game :: Get_Rand_Block() {

    if(Blocks.empty()){
        Blocks = Get_All_Blocks(); 
    }

    int randind = rand() % (int)Blocks.size(); 
    Bloks block = Blocks[randind]; 
    Blocks.erase(Blocks.begin() + randind); 
    return block ; 

}

std :: vector<Bloks> Game :: Get_All_Blocks(){
    return {LBlock() , IBlock() , OBlock() ,  TBlock() , SBlock()  , ZBlock() ,  JBlock()}; 
}

void Game:: Draw(){
    grid.Draw(); 
    currentBlock.Draw(11 , 11); 
    switch (nextBlock.id)
    {
    case 2:
        nextBlock.Draw(255 , 290);
        break;
    
    case 3:
        nextBlock.Draw(255 , 280);
        break;
    default : 
        nextBlock.Draw(270 , 270);
        break;
    }
}

void Game:: Get_Hand_Input() {
    int keypressed = GetKeyPressed() ; 
    if(Gameover && keypressed != 0){
        Gameover = false;
        Reset(); 
    }
 
    switch (keypressed)
    {
        case KEY_LEFT: 
          move_left() ; 
          break ; 
        case KEY_RIGHT:
           move_right() ; 
           break ;
        case KEY_DOWN: 
             move_down() ; 
             break ; 
        case KEY_UP:
             RotateBlock();
             break ; 

            
    }
}

void Game :: move_left(){
    if(Gameover == false ){
        currentBlock.Move(0 , -1 ); 
        if(InvalidBlock() || Blockfits() == false ){
            currentBlock.Move(0 , 1);
        }
    }

}

void Game :: move_right(){
    if(Gameover == false){
        currentBlock.Move(0 , 1); 
        if(InvalidBlock()  || Blockfits() == false){
            currentBlock.Move(0 , -1); 
        }
    }
}

void Game :: move_down(){
    if(Gameover == false ){
    
        currentBlock.Move(1 , 0 ); 
        if(InvalidBlock() || Blockfits() == false ){
            currentBlock.Move(-1 , 0); 
            LockBlock(); 
        }
    }
        
}
bool Game::InvalidBlock()
{
    std :: vector<Positions> tiles = currentBlock.Get_Cell_Position();
    for(Positions item : tiles ){
        if (grid.Invalid_Cell(item.row , item.col)){
            return true ; 
        }
    }
    return false ; 
}

void Game::RotateBlock()
{
    if (Gameover == false){

    
        currentBlock.Rotate(); 
        if(InvalidBlock() || !(Blockfits())){
            Undo_Rotate_Block(); 
        }
        else{
            PlaySound(rotatesound);
        }
    }

}

void Game::Undo_Rotate_Block()
{
    currentBlock.Undo_Rotate();
}

void Game::LockBlock()
{
    std :: vector<Positions> tiles = currentBlock.Get_Cell_Position();
    for(Positions item : tiles ){
        grid.grid[item.row][item.col] = currentBlock.id;

    }
    currentBlock = nextBlock; 
    if(Blockfits() == false ){
        Gameover = true ; 
    }
    nextBlock = Get_Rand_Block(); 
    int lines = grid.ClearFullRows();
    if (lines){
        PlaySound(clearsound);
    }
    update_score(lines , 0); 
}

bool Game::Blockfits()
{
    std :: vector<Positions> tiles = currentBlock.Get_Cell_Position();
    for(Positions item : tiles ){
        if (grid.IsEmptyCell(item.row , item.col) == false){
       
            return false ; 
        }
    }
    return true ; 

}

void Game::Reset()
{
    grid.Initialize();
    Blocks = Get_All_Blocks(); 
    currentBlock = Get_Rand_Block() ; 
    nextBlock = Get_Rand_Block(); 
    score = 0 ; 

}

void Game::update_score(int line , int moves )
{
    score += line*50;   
}