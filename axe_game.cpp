#include<cstdio>
#include<iostream>
#include "raylib.h"
using namespace std;
int main(){
    // Window Dimensions  
    int width{800};
    int height{450};
    InitWindow(width,height,"Axe Game By TjBarbossa");
    // Circle properties
    int x_coord_circle = 200;
    int y_coord_circle = 200; 
    int radius = 25;

    //circle edges
    int circle_left_x{x_coord_circle - radius};
    int circle_right_x{x_coord_circle + radius};
    int circle_upper_y{y_coord_circle - radius};
    int cicle_bottom_y{y_coord_circle + radius};

    //AXE Properties
    int posX = 300;
    int posY = 0;
    int AxeWidth = 50;
    int AxeHeight = 50;

    //Axe edges
    int AxeLeft_x = posX;
    int AxeRight_x= posX + AxeWidth;
    int AxeUpper_y= posY;
    int AxeBottom_y= posY + AxeHeight;


    int direction = 10;
    SetTargetFPS(60);

    bool collision_with_axe = (AxeBottom_y >= circle_upper_y) && 
                              (AxeRight_x >= circle_left_x) && 
                              (AxeUpper_y <= cicle_bottom_y) && 
                              (AxeLeft_x <= circle_right_x);

    while (WindowShouldClose() == false ){
        BeginDrawing();
        ClearBackground(WHITE);
       //DrawText("FPS =",705,420,20,DARKGREEN);
        DrawText("The Axe Game",540,100,30,GREEN);
        DrawText("(Although the axe is square)",540,130,15,GREEN);
        DrawFPS(770,420);
        //game logic begins
        if (collision_with_axe == true){
            DrawText("Game Over!",400,200,20,RED);
        }
        else{
           //update edges
           circle_left_x = x_coord_circle - radius;           
           circle_right_x = x_coord_circle + radius;
           circle_upper_y = y_coord_circle - radius;
           cicle_bottom_y = y_coord_circle + radius;
           AxeLeft_x = posX;
           AxeRight_x= posX + AxeWidth;
           AxeUpper_y= posY;
           AxeBottom_y= posY + AxeHeight;

           //update collision with axe
            collision_with_axe = (AxeBottom_y >= circle_upper_y) && 
                              (AxeRight_x >= circle_left_x) && 
                              (AxeUpper_y <= cicle_bottom_y) && 
                              (AxeLeft_x <= circle_right_x);

            DrawCircle(x_coord_circle,y_coord_circle,radius,BLUE);
            DrawRectangle(posX,posY,AxeWidth,AxeHeight,RED);

            //Move the  Axe
            posY += direction;
            if (posY<0 || posY > height)
                { direction = -direction;}
            if (IsKeyDown(KEY_D) && x_coord_circle < width ){
                x_coord_circle += 10;
            }
            if (IsKeyDown(KEY_A) && x_coord_circle > 0 ){
                x_coord_circle -= 10;
            }
            if (AxeBottom_y >= circle_upper_y && AxeRight_x >= circle_left_x && AxeUpper_y <= cicle_bottom_y && AxeLeft_x <= circle_right_x ){

                collision_with_axe = true;
            }
            }
            //game logic ends
        
        EndDrawing();
        }
    return 0;
}