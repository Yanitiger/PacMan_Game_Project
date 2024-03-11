#pragma once

#include "State.h"
#include "Button.h"
#include "Animation.h"
class WinState : public State {
private:
	ofImage victoryImg;
	Button *startButton;
	Button *mainMenuButton; // Added Main Menu button for quality of life -EAHC
	Button *quitMenuButton; // Added quit button asked by project instructions -EAHC
	Animation* anim;
	int score = 0;
	
public:
	WinState();
	~WinState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
	void setScore(int);
};
