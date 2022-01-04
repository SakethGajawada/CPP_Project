#include"Game.hpp"
#include"TextureManager.hpp"
#include"GameObject.hpp"

#include<SDL2/SDL_ttf.h>

class Label {
public:
	Label(int xpos, int ypos,string font,string text,SDL_Colour& colour){
		labelText = text;
		labelFont = font;
		textcolour = colour;
		position.x = xpos;
		position.y = ypos;
	}
	~Label(){}
	void setLabelText(){
		SDL_Surface* surf = TTF_RenderText_Blended(/*get font*/);
	}
	void draw(){}

	private:
		SDL_Rect position;
		string labelText,labelFont;
		SDL_Color textcolour;
		SDL_Texture* labelTexture;
};
