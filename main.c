#include "raylib.h"
#include <math.h>
#include <stdio.h>

void manyCircles(int x, int y , int radius, int depth){
    if (depth == 0)
    {
        return;
    }



    DrawCircle(x, y, radius, RED);

    int newRadius = radius /2 ;
    manyCircles(x + radius, y, newRadius, depth - 1);
    manyCircles(x - radius, y, newRadius, depth - 1);
    
     manyCircles(x , y + radius, newRadius, depth - 1);
    manyCircles(x , y - radius, newRadius, depth - 1);

    
    
}

int main()
{
    InitWindow(800, 600, "circle-recur");
    SetTargetFPS(60);

 

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(BLACK);

        manyCircles(400, 300, 100, 5);


        EndDrawing();
    }
    CloseWindow();
    return 0;
}