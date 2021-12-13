#include"Enemy.hpp"
#include"GameObject.hpp"
#include"TextureManager.hpp"
#include <bits/stdc++.h>
int Enemy:: set_x_trajectory()
    {
        x -= speed;
        std::cout<<"bsjfcbs"<<std::endl;
        return x;
    }
Enemy :: Enemy(const char* texturesheet,int x,int y) : GameObject(texturesheet,x,y){
    //std::cout<<"Enemy constructor"<<std::endl;
    // objTexture=TextureManager::LoadTexture(texturesheet);
    // xpos=x; ypos=y;
}
// Enemy::~Enemy()
// {}

