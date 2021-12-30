#include"Enemy.hpp"

Enemy::Enemy(const char* texturesheet, SDL_Renderer* renderer, int x, int y, int vel) :GameObject::GameObject(texturesheet, renderer, x, y, vel)
{}
