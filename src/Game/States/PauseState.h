//-------------------------------------------- Phase 2 -> PauseState ----------------------------------------------------
#pragma once

#include "State.h"
#include "GameOverState.h"
#include "GameState.h"
#include "GameStateMap1.h"
#include "GameStateMap2.h"
#include "GameStateMap3.h"
#include "GameStateMap4.h"
#include "MenuState.h"

class PauseState : public State {
    private:
    ofImage pauseIMG;
    Button *resumeButton, quitButton;

    public:
    PauseState();
    ~PauseState();
    // void update();
    void tick();
	void render();
    void reset();
    void draw();
    void keyPressed(int key);
    void mousePressed(int x, int y, int button); 


};