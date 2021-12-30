#include"bullet.hpp"
bullet::bullet(const char* texturesheet, SDL_Renderer* renderer, int x, int y, int vel) :GameObject::GameObject(texturesheet, renderer, x, y, vel)
{}
bullet::~bullet()
{
    cout << "hehe" << endl;

}