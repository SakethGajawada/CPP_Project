#pragma once
#include "Enemy.hpp"
#include<bits/stdc++.h>
class Enemy1 : public Enemy
{
    public:
    int set_y_trajectory();
    Enemy1(const char* texturesheet,int x,int y);
    //~Enemy1();
};