#include"Game.hpp";
class Label {
public:
	Label(int, int , string , SDL_Renderer*, SDL_Texture*  );
	~Label();
	void free();
	bool init();
	bool loadFromRenderedText();
	void render(SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
private:
	int mWidth, mHeight;
	SDL_Rect position;
	string labelText, labelFont;
	SDL_Color textcolour = { 255,0,0 };
	SDL_Texture* labelTexture;
	SDL_Renderer* renderer;
	TTF_Font* Font = TTF_OpenFont("game.ttf", 24);
};