#pragma once

#include "State.h"
#include "Player.h"
#include "MapBuilder.h"
#include "PauseState.h"
#include "ChoosePlayerState.h"

class GameStateMap4: public State{
    public: 
        GameStateMap4();
		~GameStateMap4();
		void reset();
		void tick();
		void render();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void keyReleased(int key);
		int getFinalScore();
		string choosenPlayer;
		void setPlayer(string name ) {
			choosenPlayer = name;
		}
		bool gamePaused = false;
	
	private:
		ofSoundPlayer music;
		ofImage mapImage;
		Map* map;
		int finalScore = 0;

};