#include"Player.hpp"

Player::Player(const char* texturesheet,int x,int y):GameObject(texturesheet,x,y)
{}
Player::~Player()
{}
Player::keyboard_handler(int* dist)
{
    const Uint8* keyboardstate=SDL_GetKeyboardState(nullptr);
    if(keyboardstate[SDL_SCANCODE_LEFT])
    {
        xpos-=speed;
        if(*dist>0)
        {
            *dist-=5;
        }
        //animation
    }
    if(keyboardstate[SDL_SCANCODE_RIGHT])
    {
        xpos+=speed;
        *dist+=5
        //animation
    }
    if(keyboardstate[SDL_SCANCODE_UP])
    {
        ypos+=speed;
        
        //animation
    }
    if(keyboardstate[SDL_SCANCODE_DOWN])
    {
        ypos-=speed;
        //animation
    }
    if(keyboardstate[SDL_SCANCODE_SPACE])
    {
        //call shoot function
        //animation
    }
}
Player:: Update(int* dist)
{
    dst_rect.x=xpos,dst_rect.y=ypos;
    xpos=set_x_trajectory();
    ypos=set_y_trajectory();
    for(int i=0;i<bullets.size();i++)
    {
        if(bullets[i]->dest.x >=SCREEN_WIDTH || bullets[i]->dest.x<=0)
        {
            bullets.erase(std::remove(bullets.begin(),bullets.end(),bullets[i]),bullets.end());
        }
    }
}

