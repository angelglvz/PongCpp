#include <iostream>
#include <raylib.h>
using namespace std;

class Ball{
    public:
    float x, y;
    int speed_x, speed_y;
    int radius;

    void Draw(){
        DrawCircle(x, y, radius, WHITE);
    }

    void Update(){
        x += speed_x;
        y += speed_y;
        if(y + radius >= GetScreenHeight() || y - radius <= 0)
        {
            speed_y *= -1;
        }
        if(x + radius >= GetScreenWidth() || x - radius <= 0)
        {
            speed_x *= -1;
        }
    }
};

Ball ball;

int main()
{
    cout << "Starteing the game" << endl;

    //writing the values of the drawn parts in px
    const int screen_width = 1280;
    const int screen_height = 800;
    const int ball_radius = 20;
    const int paddle_width = 25;
    const int paddle_heigth = 125;
    const int lateral_separation = 10;
    const int ball_speed_x = 7;
    const int ball_speed_y = 7;

    InitWindow(screen_width, screen_height, "My Pong Game!");
    SetTargetFPS(60);

    //setting the variables for the ball
    ball.x = screen_width/2;
    ball.y = screen_height/2;
    ball.radius = ball_radius;
    ball.speed_x = ball_speed_x;
    ball.speed_y = ball_speed_y;

    
    while(WindowShouldClose() == false){
        BeginDrawing();

        //moving the ball;
        ball.Update();

        //cleaning background
        ClearBackground(BLACK);

        //drawing ball
        ball.Draw();

        //drawing center line
        DrawLine(screen_width/2, 0, screen_width/2, screen_height, WHITE);

        //drawing paddles
        DrawRectangle(lateral_separation, screen_height/2 - (paddle_heigth/2), paddle_width, paddle_heigth, WHITE);
        DrawRectangle(screen_width - (lateral_separation + paddle_width), screen_height/2 - (paddle_heigth/2), paddle_width, paddle_heigth, WHITE);

        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}