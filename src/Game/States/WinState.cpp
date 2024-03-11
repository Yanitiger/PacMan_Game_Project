#include "WinState.h"


WinState::WinState() {
	startButton = new Button(ofGetWidth()/2, ofGetHeight()/2, 64, 50, "Start"); // Start button to begin a new game -EAHC
	mainMenuButton = new Button(ofGetWidth()/2, ofGetHeight()/2, 64, 150, "Main Menu"); // Button that sends you to the main menu -EAHC
	quitMenuButton = new Button(ofGetWidth()/2, ofGetHeight()/2, 64, 250, "Quit to Desktop"); // Button that, when pressed, closes de program -EAHC
	victoryImg.load("images/NewVictory.jpeg"); // Victory Screen PNG for better UI added -EAHC

}

void WinState::tick() {
	startButton->tick();
	mainMenuButton->tick();
	quitMenuButton->tick();
	if(startButton->wasPressed()){
		setNextState("Game");
		setFinished(true);

	}
	else if(mainMenuButton->wasPressed()){
		setNextState("Menu");
		setFinished(true);
	}
	else if(quitMenuButton->wasPressed()){
		setFinished(true);
		exit(0);
	}
}

void WinState::render() {
	
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(256, 256, 256);
	victoryImg.draw(0,0,ofGetWidth(),ofGetHeight());
	ofDrawBitmapString("Score: " + to_string(score), ofGetWidth()/2, ofGetHeight()/2-50);
	startButton->render();
	mainMenuButton->render();
	quitMenuButton->render();
	
}

void WinState::keyPressed(int key){
}

void WinState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
	mainMenuButton->mousePressed(x, y);
	quitMenuButton->mousePressed(x, y);
}

void WinState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
	mainMenuButton->reset();
	quitMenuButton->reset();
}

void WinState::setScore(int sc){
    score = sc;
}

WinState::~WinState(){
	delete startButton;
	delete mainMenuButton;  
	delete quitMenuButton;
	delete anim;
}