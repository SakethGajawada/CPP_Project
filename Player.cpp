#include<bits/stdc++.h>
using namespace std;
#include<SDL2/SDL.h>
#pragma once;
enum animation_types{
    IDLE,
    MOVE_RIGHT,
    MOVE_LEFT,
    MOVE_UP,
    MOVE_DOWN
}
class Player{//need to call parent class here game object
    public:
    Player();
    ~Player();
    void Update();
    void render();
    void keyboard_handler();
    void animate_run();//how am i supposed to animate for moving up and down
    private:
    int width = 350,height = 152;
}
int player_idle[5][3]
{
    {0,   100,  153},
    {98,  100,  153},
    {196, 100,  153},
    {294, 100, 153},
    {394, 100,  153}
};
int player_running[16][3] =
{
    {0, 138, 155},
    {138, 128, 146},
    {266, 119, 148},
    {385, 119, 155},
    {504, 121, 162},
    {625, 124, 157},
    {749, 133, 145},
    {882, 140, 149},
    {1022, 134, 154},
    {1156, 128, 150},
    {1284, 123, 150},
    {1407, 122, 155},
    {1529, 126, 162},
    {1655, 126, 161},
    {1781, 140, 149},
    {1921, 144, 150}
};

Player::Player(){
    //set images for jumping and running animations
    //textures
    setSrc(0,0,0,0);
    setDest(SCREEN_WIDTH/2,SCREEN_HEIGHT/2);//set height accorcingly
    setSpeed(0);
}
void keyboard_handler(){
    cont Unit8* currentKeyState = SDL_GetKeyboardState(NULL);
    if(currentKeyState[SDL_SCANCODE_LEFT]){
        last_direction = animation_type = MOVE_LEFT;
        xpos -= speed;
    }
    if(currentKeyState[SDL_SCANCODE_RIGHT]){
        last_direction = animation_type = MOVE_RIGHT;
        xpos += speed;
    }
    if(currentKeyState[SDL_SCANCODE_UP]){
        last_direction = animation_type = MOVE_UP;
        ypos += speed;
    }
    if(currentKeyState[SDL_SCANCODE_DOWN]){
        last_direction = animation_type = MOVE_DOWN;
        ypos -= speed;
    }
    if(!currentKeyState[SDL_SCANCODE_RIGHT] && !currentKeyState[SDL_SCANCODE_LEFT] && !currentKeyState[SDL_SCANCODE_UP] && !currentKeyState[SDL_SCANCODE_DOWN]){
        last_direction = animation_type = IDLE;
    }

    // we can improve motion in diagonal way add speed/root(2) to xpos and ypos
}

void Player::Update(){
    keyboard_handler();
    dest_rect.x = xpos;
    dest_rect.y = ypos;

}
void Player::animate_idle()
{
    current_frame = (SDL_GetTicks() * animation_fps / 1000) % 5;
    src_rect.x = player_idle[current_frame][0];
    src_rect.y = 0;
    dest_rect.w = src_rect.w = player_idle[current_frame][1];
    dest_rect.h = src_rect.h = player_idle[current_frame][2];
}
void Player::animate_run(){
    current_frame = (SDL_GetTicks()*animation_fps/100)%16;
    src_rect.x = player_running[current_frame][0];
    src_rect.y =0;
    dest_rect.w = src_rect.w = player_running[current_frame][1];
    dest_rect.h =src_rect.h= player_running[current_frame][2];
}
void Player::render(){
    switch(animation_type){
    case IDLE:
        switch(last_direction){
            case MOVE_RIGHT:
                SDL_RenderCopy(Game::renderer, objTexture, &src_rect, &dest_rect);
                break;
            case MOVE_LEFT:
                SDL_RenderCopyEx(Game::renderer, objTexture, &src_rect, &dest_rect, 0, NULL, SDL_FLIP_HORIZONTAL);
                break;
            case MOVE_UP:
            case MOVE_DOWN:
        }
    case MOVE_RIGHT:
        SDL_RenderCopy(Game::renderer, tex_running, &src_rect, &dest_rect);
        break;
    }
    case MOVE_LEFT:
        SDL_RenderCopyEx(Game::renderer, tex_running, &src_rect, &dest_rect, 0, NULL, SDL_FLIP_HORIZONTAL);
            break;
}
