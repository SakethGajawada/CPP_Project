#pragma once
#include"GameObject.hpp"

class Player : public GameObject
{
public:
    Player(SDL_Renderer* renderer, int vel);
    ~Player();
};