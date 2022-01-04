#include"GameObject.hpp"
#include"TextureManager.hpp"


GameObject::GameObject(const char*texturesheet,SDL_Renderer* ren,int x,int y,int vel)
{
    SDL_Surface* tempSurface = IMG_Load(texturesheet);
	objTexture=SDL_CreateTextureFromSurface(ren, tempSurface);
    //objTexture=TextureManager::LoadTexture(texturesheet,ren);
    this->xpos=x;
    this->ypos=y;
    this->vel=vel;
    renderer=ren;
}

void GameObject:: MoveObj(int x_vel,int y_vel)
{
    xpos+=x_vel;
    ypos+=y_vel;
}
void GameObject::animate(const char*texSheet,SDL_Renderer* ren)
{
    if(objTexture!=NULL)
    {
        SDL_DestroyTexture(objTexture);
    }
    // objTexture=TextureManager::LoadTexture(texSheet,ren);
    SDL_Surface* tempSurface = IMG_Load(texSheet);
	objTexture=SDL_CreateTextureFromSurface(ren, tempSurface);
    SDL_FreeSurface(tempSurface);
}

void GameObject::Update(int srch,int srcw)
{
    src_rect->h=srch;
    src_rect->w=srcw;
    src_rect->x=0;
    src_rect->y=0;

    dst_rect->x=xpos;
    dst_rect->y=ypos;
    dst_rect->w=src_rect->w;
    dst_rect->h=src_rect->h;
}

void GameObject::Render()
{
    SDL_RenderCopy(renderer,objTexture,src_rect,dst_rect);
    //SDL_DestroyTexture(objTexture);
}
GameObject::~GameObject()
{
    cout<<"gameobject destroyed"<<endl;
    //SDL_DestroyTexture(objTexture);
}