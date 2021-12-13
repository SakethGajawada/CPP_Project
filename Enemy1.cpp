#include"Enemy1.hpp"
#include<iostream>

int Enemy1:: set_y_trajectory(){
        int num = rand() % 516 +64;
        y=num;
        std::cout<<"rand number :"<<num<<std::endl;
        return y;
    }
Enemy1 :: Enemy1(const char* texturesheet,int x,int y) : Enemy(texturesheet,x,y)
{//std::cout<<"constructor called"<<std::endl;
}
// Enemy1::~Enemy1()
// {}
