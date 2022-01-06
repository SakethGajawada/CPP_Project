#include"../include/Game.hpp"

Game* game = nullptr;

int main(int argc, char* argv[])
{
	const int fps = 60;
	int screenLength = 800;
	int screenWidth = 600;
	string nam;

	const int frameDelay = 1000 / fps;
	Uint32 frameStart;
	int frameTime;

	game = new Game(screenWidth, screenLength);

	//creating scoreboard file if it doesnt exist
	fstream scoreboard;
	scoreboard.open("../Scoreboard.txt", ios::app);
	if (!scoreboard) { cout << "ERROR opening file" << endl; }
	else { scoreboard.close(); }

	//Entering player name
	cout << "Enter Player Name" << endl;
	cin >> nam;
	game->set_playerName(nam); //game will not start unless playerName is not set

	game->init("Dragon", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenLength, screenWidth, false);
	while (game->running())
	{
		frameStart = SDL_GetTicks();

		game->events();
		game->update();
		game->render();

		//Capping framerate to 60fps
		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();
	return 0;
}