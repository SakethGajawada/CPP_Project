#include "GameObject.hpp"

class bullet : public GameObject
{
    public:
    bullet(const char*texturesheet,SDL_Renderer* renderer,int x,int y,int vel);
    ~bullet();
};