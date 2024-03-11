//-------------------------------------------- Phase 2 -> Choose Player State ----------------------------------------------------
#pragma once

#include "State.h"
#include "GameOverState.h"
#include "GameState.h"
#include "MenuState.h"
#include "PauseState.h"
#include "Player.h"
#include "MapBuilder.h"

class ChoosePlayerState : public State {
    private:
    ofImage chooseIMG;
    string playerChoosen;
      
    public:
    

    ChoosePlayerState();
    ~ChoosePlayerState();

    void tick();
	  void render();
    void reset();
    void draw();
    void keyPressed(int key);
    void mousePressed(int x, int y, int button); 
    void setPlayer(string name);
    string getPlayer();
    bool switchState = false;


};