#include <raylib.h>
#include <iostream>

int main(void)
{
    int height = 450;
    int width = 800;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(width, height, "raylib [core] example - basic window");
    SetWindowState(0);
    
    Texture2D Texture = LoadTexture("C:\\Users\\dismooont\\Pictures\\icons8-target-30.png");

    SetTargetFPS(75);
    
    int pos1=0, pos2=0;
    int posPlayerX = GetScreenWidth() / 2 - 10, posPlayerY = GetScreenHeight() - 130;

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
        DrawLine(GetScreenWidth(), GetScreenHeight()-100, 0, GetScreenHeight() - 100,BLACK);
        DrawLine(posPlayerX+5, posPlayerY+15, pos1+15, pos2+15, BLUE);
        DrawRectangle(posPlayerX, posPlayerY, 10, 30, RED);
        EndDrawing();
        if (IsKeyPressed(KEY_F)) {
            std::cout << GetFPS() << std::endl;
        }
        
    }

    CloseWindow();

    return 0;
}