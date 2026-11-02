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
protected:
    void LimitMovement()
    {
        if( y <= 0 )
        {
            y = 0;
        }
        if( y + height >= GetScreenHeight())
        {
            y = GetScreenHeight() - height;
        }
    }

public:
    float x, y;
    float width, height;
    int speed;

    void Draw() 
    {
        DrawRectangle(x, y, width, height, WHITE);
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
        LimitMovement();
    }
};

class Computer: public Paddle 
{
public:
    void Update(int ball_y)
    {
        if( y + height/2 > ball_y)
        {
            y = y - speed;
        }
        if( y + height/2 < ball_y)
        {
            y = y + speed;
        }
        LimitMovement();
    }
};

Ball ball;
Paddle player;
Computer computer;

int main()
{
    cout << "Starteing the game" << endl;

    //writing the values of the drawn parts in px
    const int screen_width = 1280;
    const int screen_height = 800;
    const int ball_radius = 20;
    const int paddle_width = 25;
    const int paddle_height = 125;
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
    player.y = screen_height/2 - (paddle_height/2);
    player.height = paddle_height;
    player.width = paddle_width;
    player.speed = paddle_speed;

    //initializing computer
    computer.x = screen_width - (lateral_separation + paddle_width);
    computer.y = screen_height/2 - (paddle_height/2);
    computer.height = paddle_height;
    computer.width = paddle_width;
    computer.speed = paddle_speed;
    
    while(WindowShouldClose() == false){
        BeginDrawing();

        //moving the parts;
        ball.Update();
        player.Update();
        computer.Update(ball.y);

        //cleaning background
        ClearBackground(BLACK);

        //drawing ball
        ball.Draw();

        //drawing center line
        DrawLine(screen_width/2, 0, screen_width/2, screen_height, WHITE);

        //Draw Paddles
        player.Draw();
        computer.Draw();
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}