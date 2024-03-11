#include "MapSelectState.h"

MapSelectState::MapSelectState() {
	map1Button = new Button(ofGetWidth()/2-32, ofGetHeight()/2, 64, 50, "Map 1");
	map2Button = new Button(ofGetWidth()/2-32, ofGetHeight()/2 - 40, 64, 50, "Map 2");
	map3Button = new Button(ofGetWidth()/2-32, ofGetHeight()/2 - 80, 64, 50, "Map 3");
	map4Button = new Button(ofGetWidth()/2-32, ofGetHeight()/2 - 120, 64, 50, "Map 4");
	mainMenuButton = new Button(ofGetWidth()/2-32, ofGetHeight()/2 - 160, 64, 50, "Main Menu");
	

}
void MapSelectState::tick() {
	map1Button->tick();
	map2Button->tick();
	map3Button->tick();
	map4Button->tick();
	mainMenuButton->tick();

	if(map1Button->wasPressed()){
		setNextState("Map 1");
		setFinished(true);

	}
	else if(map2Button->wasPressed()){
		setNextState("Map 2");
		setFinished(true);

	}
	else if(map3Button->wasPressed()){
		setNextState("Map 3");
		setFinished(true);

	}
	else if(map4Button->wasPressed()){
		setNextState("Map 4");
		setFinished(true);

	}
	else if(mainMenuButton->wasPressed()){
		setNextState("Menu");
		setFinished(true);

	}
}
void MapSelectState::render() {
	string title = "Select Map";
	ofDrawBitmapString(title, ofGetWidth()/2-4*title.size(), ofGetHeight()/2-300, 50);
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(256, 256, 256);
	map1Button->render();
	map2Button->render();
	map3Button->render();
	map4Button->render();
	mainMenuButton->render();
}

void MapSelectState::keyPressed(int key){
	
}

void MapSelectState::mousePressed(int x, int y, int button){
	map1Button->mousePressed(x, y);
	map2Button->mousePressed(x, y);
	map3Button->mousePressed(x, y);
	map4Button->mousePressed(x, y);
	mainMenuButton->mousePressed(x, y);
}

void MapSelectState::reset(){
	setFinished(false);
	setNextState("");
	map1Button->reset();
	map2Button->reset();
	map3Button->reset();
	map4Button->reset();
	mainMenuButton->reset();
}

MapSelectState::~MapSelectState(){
	delete map1Button;
	delete map2Button;
	delete map3Button;
	delete map4Button;
	delete mainMenuButton;
}