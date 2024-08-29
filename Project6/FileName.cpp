#include <raylib.h>
#include <iostream>
#include "Bullet.h"

float pos1 = 1,
pos2 = 1;
int main(void)
{
    int height = 450;
    int width = 800;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(width, height, "raylib [core] example - basic window");
    SetWindowState(0);
    
    Texture2D Texture = LoadTexture("res\\icons8-target-30.png");

    Texture2D BulletTexture = LoadTexture("res\\icons8-target-30.png");


    SetTargetFPS(75);
    

    float posPlayerX = GetScreenWidth() / 2 - 10, posPlayerY = GetScreenHeight() - 130;
    Bullet myBullet(BulletTexture, posPlayerX,posPlayerY);

    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_D) && !IsKeyReleased(KEY_D) && posPlayerX <= GetScreenWidth() - 10 - 1) {
            posPlayerX+=2;
        }
        if (IsKeyDown(KEY_A) && !IsKeyReleased(KEY_A) && posPlayerX >= 1) {
            posPlayerX-=2;
        }
            //HideCursor();
        if (GetMouseY() <= GetScreenHeight() - 100) {
            pos1 = GetMouseX() - 15;
            pos2 = GetMouseY() - 15;
        }


        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(Texture, pos1, pos2, RAYWHITE);
        myBullet.Move(myBullet.MoveArray);
        DrawLine(GetScreenWidth(), GetScreenHeight()-100, 0, GetScreenHeight() - 100,BLACK);
        DrawLine(posPlayerX+5, posPlayerY+15, pos1+15, pos2+15, BLUE);
        DrawRectangle(posPlayerX, posPlayerY, 10, 30, RED);
        EndDrawing();
        if (IsKeyPressed(KEY_F)) {
            std::cout << GetFPS() << std::endl;
        }
        
    }
    UnloadTexture(Texture);
    UnloadTexture(BulletTexture);
    CloseWindow();

    return 0;
}
