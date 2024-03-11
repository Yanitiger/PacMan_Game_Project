#pragma once

#include "ofMain.h"
#include "MenuState.h"
#include "GameState.h"
#include "GameOverState.h"
#include "PauseState.h"
#include "WinState.h"
#include "ChoosePlayerState.h"
#include "MapSelectState.h"
#include "GameStateMap1.h"
#include "GameStateMap2.h"
#include "GameStateMap3.h"
#include "GameStateMap4.h"


class ofApp : public ofBaseApp {

private:
	State *currentState;
	MenuState *menuState;
	GameState *gameState;
	GameOverState *gameOverState;
	PauseState *pauseState;
	WinState *winState;
	ChoosePlayerState *choosePlayerState;
	MapSelectState *mapSelectState;
	GameStateMap1 *gameStateMap1;
	GameStateMap2 *gameStateMap2;
	GameStateMap3 *gameStateMap3;
	GameStateMap4 *gameStateMap4;


public:

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		string choosenPlayer;
		int score;

};
