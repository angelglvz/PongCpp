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

class Paddle
{
public:
    float x, y;
    float width, heigth;
    int speed;

    void Draw() 
    {
        DrawRectangle(x, y, width, heigth, WHITE);
    }

    void Update()
    {
        if(IsKeyDown(KEY_UP))
        {
            y = y - speed;
        }
        if(IsKeyDown(KEY_DOWN))
        {
            y = y + speed;
        }
        if( y <= 0 )
        {
            y = 0;
        }
        if( y + heigth >= GetScreenHeight())
        {
            y = GetScreenHeight() - heigth;
        }
    }
};

Ball ball;
Paddle player;
Paddle computer;

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
    const int paddle_speed = 6;

    InitWindow(screen_width, screen_height, "My Pong Game!");
    SetTargetFPS(60);

    //initializing ball
    ball.x = screen_width/2;
    ball.y = screen_height/2;
    ball.radius = ball_radius;
    ball.speed_x = ball_speed_x;
    ball.speed_y = ball_speed_y;

    //initializing player
    player.x = lateral_separation;
    player.y = screen_height/2 - (paddle_heigth/2);
    player.heigth = paddle_heigth;
    player.width = paddle_width;
    player.speed = paddle_speed;
    
    while(WindowShouldClose() == false){
        BeginDrawing();

        //moving the parts;
        ball.Update();
        player.Update();
        computer.Update();

        //cleaning background
        ClearBackground(BLACK);

        //drawing ball
        ball.Draw();

        //drawing center line
        DrawLine(screen_width/2, 0, screen_width/2, screen_height, WHITE);

        //Draw Player
        player.Draw();
        DrawRectangle(screen_width - (lateral_separation + paddle_width), screen_height/2 - (paddle_heigth/2), paddle_width, paddle_heigth, WHITE);

        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}