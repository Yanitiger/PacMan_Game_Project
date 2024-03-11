//-------------------------------------------- Phase 2 -> ChoosePlayerState ----------------------------------------------------
#include "ChoosePlayerState.h"
#include "Player.h"



ChoosePlayerState::ChoosePlayerState() {
    chooseIMG.load("images/NewChooseYourCharacter.jpeg");
}

//--------------------------------------------------------------
void ChoosePlayerState::tick() {
    if(switchState == true) {
        setNextState("Game");
        setFinished(true);
        switchState = false;
    }
}

//--------------------------------------------------------------
void ChoosePlayerState::render() {
    chooseIMG.draw(0,0,ofGetWidth(),ofGetHeight());
    ofSetColor(256, 256, 256);
}

//--------------------------------------------------------------
void ChoosePlayerState::keyPressed(int key) { 

}

//--------------------------------------------------------------
void ChoosePlayerState::mousePressed(int x, int y, int button) {
    if (x > min(100, 400) && x < max(100, 400) && y > min(250,500) && y < max(250,500)) {
        setPlayer("pacman");
        switchState = true;

    } else if (x > min(600, 870) && x < max(600, 870) && y > min(205,560) && y < max(205,560)) {
        setPlayer("arceus");
        switchState = true;

    }
}

void ChoosePlayerState::setPlayer(string name) {
    playerChoosen = name;
}
string ChoosePlayerState::getPlayer() {
    return playerChoosen;
}

//--------------------------------------------------------------
void ChoosePlayerState::reset() {
    setFinished(false);
	setNextState("");
}

//--------------------------------------------------------------
ChoosePlayerState::~ChoosePlayerState() {

}