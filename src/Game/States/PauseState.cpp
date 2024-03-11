//-------------------------------------------- Phase 2 -> PauseState ----------------------------------------------------
#include "PauseState.h"
#include "Player.h"

PauseState::PauseState() {
    // resumeButton = new Button()
    pauseIMG.load("images/PauseIMG.jpg");
}

//--------------------------------------------------------------
void PauseState::tick() {


}

//--------------------------------------------------------------
void PauseState::render() {
    pauseIMG.draw(0,0,ofGetWidth(),ofGetHeight());
    string text2 = " Press the leter P to resume or Q to quit game";
    ofSetColor(256, 256, 256);
    ofDrawBitmapString(text2, ofGetWidth()/2-8*text2.length()/2, 65);
    ofDrawBitmapString("Exit Game", 290, 340);
    ofDrawBitmapString("Resume", 480, 340);
    ofDrawBitmapString("Restart", 665, 340);
}

//--------------------------------------------------------------
void PauseState::draw() {

}

//--------------------------------------------------------------
void PauseState::keyPressed(int key) {
    /* If p is Pressed change to gameState */
    if(key == 'p' || key == 'P' || key == OF_KEY_RETURN) {
        this->setNextState("GameState");
    }
    if (key == 'q' || key == 'Q') {
        OF_EXIT_APP(0); 
    }
}   

//--------------------------------------------------------------
void PauseState::mousePressed(int x, int y, int button) {
/* These lines of code will check if the mouse has been preesed on the screen inside the given parameters 
                            and change depending on its nextState given                               */
    
    if (x > min(225, 380) && x < max(225, 380) && y > min(360,550) && y < max(360,550)) {
        OF_EXIT_APP(0); 
    } else if (x > min(425, 580) && x < max(425, 580) && y > min(360,550) && y < max(360,550)) {
        this->setNextState("GameState");
    } else if (x > min(625, 780) && x < max(625, 780) && y > min(360,550) && y < max(360,550)) {
        this->setNextState("Menu");
    }  
}

//--------------------------------------------------------------
void PauseState::reset() {
    setFinished(false);
    setNextState("");
}

//--------------------------------------------------------------
PauseState::~PauseState() {
    
}