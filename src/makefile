CC = g++

CFLAGS = -Wall -g -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer  

DEPS = Game.hpp GameObject.hpp Enemy.hpp Enemy1.hpp bullet.hpp Enemy2.hpp Enemy3.hpp Score.hpp Music.hpp

OBJ =  Game.cpp GameObject.cpp main.cpp Player.cpp Enemy.cpp Enemy1.cpp bullet.cpp Enemy2.cpp Enemy3.cpp Score.cpp Music.cpp

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
window: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	
clean:
	rm -rf *o window
