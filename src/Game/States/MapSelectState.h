#pragma once

#include "State.h"
#include "Button.h"
#include "Animation.h" 

class MapSelectState : public State {
private:
	ofImage img1;
	Button *map1Button;
	Button *map2Button;
	Button *map3Button;
	Button *map4Button;
	Button *mainMenuButton;
	

public:
	MapSelectState();
	~MapSelectState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
};
