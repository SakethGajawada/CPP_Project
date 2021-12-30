#include"Game.hpp"
#include"TextureManager.hpp"
#include"Player.hpp"
#include"Enemy.hpp"
#include"Enemy1.hpp"
#include"Enemy2.hpp"
#include"Enemy3.hpp"
#include"bullet.hpp"
#include<vector>

SDL_Event Game::event;
int score=0;
Player* player;
Enemy1* enemy1;
Enemy2* enemy2;
Enemy3* enemy3;
bullet* bullets;

//list of enemies
vector<Enemy*> enemy;


//constructor-destructor
Game::Game(int w,int l):screenWidth(w),screenLength(l){}
Game::~Game(){};

//main functions
bool Game::running(){return isRunning;}

void Game::init(const char* title,int x_coord,int y_coord,int width,int height,bool fullscreen)
{
    int flag = 0;
	if (fullscreen) { flag = SDL_WINDOW_FULLSCREEN; }

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "Initialized" << endl;
		window = SDL_CreateWindow("Dragon", x_coord, y_coord, width, height, flag);
		if (window)
		{cout << "Window Created" << endl;}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) 
		{ 
			SDL_SetRenderDrawColor(renderer, 255, 255 , 255, 255);
			cout << "Renderer Created" << endl; 
		}

		isRunning = true;
	}	
	else
	{
		isRunning = false;
	}
	
	//background image
	backgroundTex = TextureManager::LoadTexture("background.png", renderer);
	cout<<"background texture loaded"<< endl;

	//Creating player
	player=new Player(renderer,5);
	cout<<"player created"<<endl;

	//Creating enemies
	enemy1=new Enemy1("enemy_standing.png",renderer,screenLength-200,screenWidth-200,2);
	enemy2 = new Enemy2("enemy2.png", renderer, screenLength + 500, screenWidth + 500, 2);
	enemy3 = new Enemy3("enemy3.png", renderer, screenLength + 500, screenWidth + 500, 2);
	enemy.push_back(enemy1);
	enemy.push_back(enemy2);
	enemy.push_back(enemy3);

	//Creating bullets
	bullets=new bullet("bullet.png",renderer,screenWidth+500,screenWidth+500,bulletSpeed);

    //Flags
	bulletFlag = 0; //if bullet flag is 1, it is in action stage
	powerFlag = 0; //if powerup is enabled, powerFlag=1
	enemyFlag = 0; //if enemy is present, enemyFlag=1;
}

void Game::events()
{

	//Keyboard inputs
	SDL_PollEvent(&event);
	switch(event.type)
	{
		case SDL_QUIT:
			isRunning=false;
			break;
		case SDL_KEYDOWN:
			switch(Game::event.key.keysym.sym)
			{
				case SDLK_q:
					isRunning=false;
					break;
				case SDLK_RIGHT:
					if(player->get_xpos()<screenLength-400)
					{
						player->MoveObj(player->get_velocity(),0);
						player->animate("goku_movingright.png",renderer);
						break;
					}
					else
					{
						player->animate("goku_standing.png",renderer);
						break;
					}
				case SDLK_LEFT:
					if(player->get_xpos()>0)
					{
						player->MoveObj(-(player->get_velocity()),0);
						player->animate("goku_movingleft.png",renderer);
						break;
					}
					else
					{
						player->animate("goku_standing.png",renderer);
						break;
					}
				case SDLK_UP:
					if(player->get_ypos()>0)
					{
						player->MoveObj(0,-(player->get_velocity()));
						player->animate("goku_movingup.png",renderer);
						break;
					}
					else
					{
						player->animate("goku_standing.png",renderer);
						break;
					}
				case SDLK_DOWN:
					if(player->get_ypos()<screenWidth-100)
					{
						player->MoveObj(0,player->get_velocity());
						player->animate("goku_movingdown.png",renderer);
						break;
					}
					else
					{
						player->animate("goku_standing.png",renderer);
						break;
					}

				//shooting bullets
				case SDLK_SPACE:
				if(bulletFlag==0)
				{
					//bullets=new bullet("bullet.png",renderer,screenWidth+500,screenWidth+500,bulletSpeed);
					player->animate("goku_shooting.png",renderer);
					bullets->set_xpos(player->get_xpos()+50);
					bullets->set_ypos(player->get_ypos()+25);
					bulletFlag=1;
				}
				break;

				//PowerUp
				case SDLK_p:
					if (powerFlag == 0)
					{
						player->animate("goku_power.png", renderer);
						player->set_velocity(playerSpeed * 3);
						powerFlag = 1;
						break;
					}
					else if (powerFlag == 1)
					{
						player->animate("goku_standing.png", renderer);
						player->set_velocity(playerSpeed);
						powerFlag = 0;
					}

				//Restart Screen
				case SDLK_r:
					if (enemyFlag == 2)
					{
						enemyFlag = 0;
						actEnemy = 0;
						score = 0;
						player->set_xpos(50);
						player->set_ypos(screenWidth/2);
						backgroundTex = TextureManager::LoadTexture("background.png", renderer);
					}
			}
			break;
		case SDL_KEYUP:
			if(powerFlag==1)
			{
				player->animate("goku_power.png",renderer);
				break;
			}
			player->animate("goku_standing.png",renderer);
			break;
	}

	//moving the bullets
	if(bulletFlag==1&&bullets)
	{
		bullets->MoveObj(bulletSpeed,0);
		if(bullets->get_xpos()>=screenLength)//if bullet reaches end of screen
		{
			bulletFlag=0;
			bullets->set_xpos(screenLength+500);
		}
	}

	//spawning enemies
	if(enemyFlag==0)
	{
		enemy[actEnemy]->set_xpos(700);
		enemy[actEnemy]->set_ypos(100+rand()%400);
		enemyFlag=1;
	}

	//enemy movement
	if(enemyFlag==1)
	{
		enemy[actEnemy]->movement();
		enemy[actEnemy]->animation();
	}
	
	//collision between enemy and bullet
	if ((abs(bullets->get_xpos() - enemy[actEnemy]->get_xpos()) <= 10 && abs(bullets->get_ypos() - enemy[actEnemy]->get_ypos()-40) <= 40))
		{
			score+=10;
			
			//Selecting enemy type
			if (score >= 10 && score<20) 
			{ 
					actEnemy = 1;
					enemy[0]->set_xpos(screenLength + 500);
					enemy[0]->set_ypos(screenWidth + 500);
			}

			else if (score >= 20 && score <=50)
			{
				actEnemy = 2;
				enemy[1]->set_xpos(screenLength + 500);
				enemy[1]->set_ypos(screenWidth + 500);
			}

			else 
				{ 
					actEnemy = 0;
					enemy[2]->set_xpos(screenLength + 500);
					enemy[2]->set_ypos(screenWidth + 500);
				}
			cout<<"Score="<<score<<endl;

			enemy[actEnemy]->set_ypos(screenWidth + 500);
			enemy[actEnemy]->set_xpos(screenLength + 500);
			bulletFlag = 0;
			bullets->set_xpos(screenLength + 500);
			enemyFlag = 0;
		}

	//enemy player collision && enemy reaching end of screen
	if(enemy[actEnemy]->get_xpos()<=10 || (abs(player->get_xpos()-enemy[actEnemy]->get_xpos())<=40 && abs(player->get_ypos()-enemy[actEnemy]->get_ypos())<=40))
	{
		cout<<"you lost"<<endl;
		enemy[actEnemy]->set_xpos(screenLength+500);
		enemy[actEnemy]->set_ypos(screenWidth+500);
		player->set_xpos(screenLength+500);
		player->set_ypos(screenLength+500);
		bulletFlag=0; //remove bullet from screen
		enemyFlag=2; 
		backgroundTex=TextureManager::LoadTexture("game_over.jpg",renderer);
	}
}

void Game::update()
{
	player->Update(110,76);
	enemy1->Update(106,66);
	enemy2->Update(120,98);
	enemy3->Update(125, 118);
	if(bullets)
		bullets->Update(30,32);
}

void Game::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, backgroundTex, NULL, NULL);
	player->Render();
	enemy1->Render();
	enemy2->Render();
	enemy3->Render();
	if(bullets) bullets->Render();
	SDL_RenderPresent(renderer);

}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout<<"Cleaned"<<endl;
}