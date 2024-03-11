#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	ofSetWindowTitle("C++ Game Box");
	//States
	menuState = new MenuState();
	gameState = new GameState();
	gameStateMap1 = new GameStateMap1();
	gameStateMap2 = new GameStateMap2();
	gameStateMap3 = new GameStateMap3();
	gameStateMap4 = new GameStateMap4();
	gameOverState = new GameOverState();
	pauseState = new PauseState();
	winState = new 	WinState();
	choosePlayerState = new ChoosePlayerState();
	
	mapSelectState = new MapSelectState();
	// Initial State
	currentState = menuState;

}

//--------------------------------------------------------------
void ofApp::update(){

	if (currentState != nullptr){
		currentState->tick();
		if(currentState->hasFinished()){
			if(currentState->getNextState() == "Menu"){
				currentState = menuState;

			}else if(currentState->getNextState() == "MapSelect"){
				currentState = mapSelectState;

			}else if(currentState->getNextState() == "Map 1"){ // new gameState for map select screen with map 1 -EAHC
				gameStateMap1 = new GameStateMap1(); 
				choosenPlayer = choosePlayerState->getPlayer();
				gameStateMap1->setPlayer(choosenPlayer);
				currentState = gameStateMap1;

			}else if(currentState->getNextState() == "Map 2"){ // new gameState for map select screen with map 2 -EAHC
				gameStateMap2 = new GameStateMap2(); 
				choosenPlayer = choosePlayerState->getPlayer();
				gameStateMap2->setPlayer(choosenPlayer);
				currentState = gameStateMap2;

			}else if(currentState->getNextState() == "Map 3"){ // new gameState for map select screen with map 3 -EAHC
				gameStateMap3 = new GameStateMap3(); 
				choosenPlayer = choosePlayerState->getPlayer();
				gameStateMap3->setPlayer(choosenPlayer);
				currentState = gameStateMap3;

			}else if(currentState->getNextState() == "Map 4"){ // new gameState for map select screen with map 4(Bonus Map) -EAHC
				gameStateMap4 = new GameStateMap4();
				choosenPlayer = choosePlayerState->getPlayer();
				gameStateMap4->setPlayer(choosenPlayer);
				currentState = gameStateMap4;
//-------------------------------------------- Phase 2 -> ChoosePlayerState ----------------------------------------------------
					/* It will Also check what player has been choosen and send it to the gameState*/
			}else if(currentState->getNextState() == "Game"){
				gameState = new GameState(); // creates a new gameState when you loose instead of resusing the old same one -EAHC
				choosenPlayer = choosePlayerState->getPlayer();
				gameState->setPlayer(choosenPlayer);
				currentState = gameState;

			}else if (currentState->getNextState() == "ChoosePlayerState") {
				currentState = choosePlayerState;

			}else if(currentState->getNextState() == "over"){
				gameOverState->setScore(gameState->getFinalScore());
				currentState = gameOverState;
				
			}else if(currentState->getNextState() == "Win"){
				score = gameState->getFinalScore();
				winState->setScore(score);
				currentState = winState;
			}
			currentState->reset();
		}
	}
//-------------------------------------------- Phase 2 -> PauseState ----------------------------------------------------
	if (currentState->getNextState() == "PauseState") {
		pauseState->reset();
		currentState = pauseState;
	} else if (currentState == pauseState && currentState->getNextState() == "GameState") {
		gameState->reset();
        currentState = gameState;
    } else if (currentState == pauseState && currentState->getNextState() == "GameStateMap1") {
		gameStateMap1->reset();
        currentState = gameStateMap1;
    }else if (currentState == pauseState && currentState->getNextState() == "GameStateMap2") {
		gameStateMap2->reset();
        currentState = gameStateMap2;
    }else if (currentState == pauseState && currentState->getNextState() == "GameStateMap3") {
		gameStateMap3->reset();
        currentState = gameStateMap3;
    }else if (currentState == pauseState && currentState->getNextState() == "GameStateMap4") {
		gameStateMap4->reset();
        currentState = gameStateMap4;
    }else if (currentState == pauseState && currentState->getNextState() == "Menu") {
		menuState->reset();
        currentState = menuState;
    } else if (currentState == pauseState && currentState->getNextState() == "Over") {
		gameOverState->reset();
        currentState = gameOverState;
    }

	if(currentState == choosePlayerState && currentState->getNextState() == "GameState") {
		gameState->reset();
		currentState = gameState;
	}

	currentState->reset();
		
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (currentState != nullptr)
		currentState->render();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (currentState != nullptr){
		currentState->keyPressed(key);
	}
	//Turn Volume Down (Mute)	
	if( key == '-' ){
		ofSoundSetVolume(0);
	}
	
	//Turn Volume Back Up
	if( key == '=' ){
		ofSoundSetVolume(1);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (currentState != nullptr)
			currentState->keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	if (currentState != nullptr)
		currentState->mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
	if (currentState != nullptr)
			currentState->mouseEntered(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
	if (currentState != nullptr)
		currentState->mouseExited(x, y);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	if (currentState != nullptr)
			currentState->windowResized(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
	if (currentState != nullptr)
		currentState->gotMessage(msg);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
	if (currentState != nullptr)
		currentState->dragEvent(dragInfo);
}
