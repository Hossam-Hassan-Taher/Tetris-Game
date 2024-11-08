#include <iostream>
#include <raylib.h>
#include "Game.h"
#include "colors.h"
double lastUpdate = 0 ; 
double last = 0 ; 
bool Triggerd(double interval){
    double current_time = GetTime(); 
    if (current_time - lastUpdate >= interval){
        lastUpdate = current_time ; 
        return true ; 
    }
    return false ;
}

bool draw_color(double ti){
    double current_time = GetTime(); 
    if (current_time - last >= ti){
        last = current_time ; 
        return true ; 
    }
    return false ;
}
using namespace std;

int main () {
    

    Color background = {44 , 44 , 127 , 255};
    InitWindow(500 , 620 , "Tetris");
    SetTargetFPS(60); 
    Game game ;
    Font font = LoadFont("Fonts/Mono.otf");
    int ind = 3 ; 
    int indColer = 0 ; 
    double speed = 0.3;
    while (WindowShouldClose() == false)
    {
        UpdateMusicStream(game.music);
        game.Get_Hand_Input();
        if(Triggerd(speed)){
            game.move_down();
        }
        BeginDrawing();
        ClearBackground(background);
   
        float fontSize = 30.0f;
        DrawTextEx(font, "Next", {358, 175}, fontSize, 2, WHITE);
        DrawTextEx(font, "Score", {350, 15}, fontSize, 2, WHITE);

        if (game.Gameover ) 
        {
        
            vector<Color> gameover = Get_Cell_Color();
            if(draw_color(0.2)){
                
               ind = rand() % 8 ; 

            }

            Color cur  = gameover[ind];

            DrawTextEx(font, "GAME OVER", {335, 500}, fontSize-10 , 2, cur);
        }
        DrawRectangleRounded({320 , 55 , 170 , 60} , 0.3 , 6 , Box );

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 30, 2);
        if (game.score < 300){
            indColer = 0 ; 
            speed = 0.3;

        }
        else if (game.score < 800 )
        {
            indColer = 1 ;
            speed = 0.2;
            
        }
        else if (game.score < 5000)
        {
            indColer = 2 ;
            speed = 0.1;
        }
        else 
        {
            indColer = 3 ; 
            speed = 0.09;
    
        }
        
        vector<Color> levels = Get_score_color();
        Color score_color = levels[indColer];
        DrawText(scoreText, 320 + (170-textSize.x)/2, 65, 38, score_color);
        DrawRectangleRounded({320 , 215 , 170 , 180} , 0.3 , 6 , Box );

        game.Draw();
        EndDrawing();
    }
    
    CloseWindow(); 
}