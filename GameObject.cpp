#include"GameObject.hpp"
#include"TextureManager.hpp"
#include"Enemy.hpp"
#include"Enemy1.hpp"
int count = 0;
GameObject::GameObject(const char* texturesheet,int x,int y)
{
    //renderer=ren;
    std::cout<<"GameObject"<<std::endl;
    objTexture=TextureManager::LoadTexture(texturesheet);
    std::cout<<"xpos ke upar"<<std::endl;
    xpos=x; ypos=y;
}

void GameObject::Update()
{
    //count++;
    //xpos=set_x_trajectory();
    //ypos=set_y_trajectory();
    xpos++;
    ypos++;
    src_rect.h=64 ,src_rect.w=64,src_rect.x=0,src_rect.y=0;
    dst_rect.x=xpos,dst_rect.y=ypos,dst_rect.h=src_rect.h*2,dst_rect.w=src_rect.w*2;
}
void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer,objTexture,&src_rect,&dst_rect);
}
