#include "GameState.h"
#include "Entity.h"

GameState::GameState() {
	music.load("music/pacman_chomp.wav");
	mapImage.load("images/map2.png"); // Changed the default map to Map2
	map = MapBuilder().createMap(mapImage);

}
void GameState::tick() {
/* If the game is Paused then change to the PauseState and ignore everything else, otherwise countinue normally*/
	if(gamePaused == true) {
		setNextState("PauseState");
		gamePaused = false;

	} else {

		if(choosenPlayer == "pacman") {
			map->getPlayer()->setPlayer("pacman");
		}

		if(choosenPlayer == "arceus") {
			map->getPlayer()->setPlayer("arceus");
		}

		if(!music.isPlaying()){
			music.play();
		}

		setNextState("");

		
		map->tick();
		if(map->getPlayer()->getHealth() == 0){
			setFinished(true);
			setNextState("over");
			map->getPlayer()->setHealth(3);
			finalScore = map->getPlayer()->getScore();
			map->getPlayer()->setScore(0);
		}
		if(map->getEntityManager()->entities.size() == 0){ // when the entity vector is empty, changes state to winstate -EAHC
			setFinished(true);
			setNextState("Win");
			map->getPlayer()->setHealth(3);
			finalScore = map->getPlayer()->getScore();
			map->getPlayer()->setScore(0);
		}
	}
}
void GameState::render() {
	map->render();
}

void GameState::keyPressed(int key){
	map->keyPressed(key);
	
//----------------------------------------------
	if(key == 'p' || key == 'P') {
		gamePaused = !gamePaused;
	}
	if(key == 'y' || key == 'Y'){
		map->getEntityManager()->entities.clear();
	// when lowercase or uppercase 'y' is pressed, the entity vector gets cleared which causes the player to be sent to the victory screen. -EAHC
		
	}
}

void GameState::mousePressed(int x, int y, int button){
	map->mousePressed(x, y, button);
}

void GameState::keyReleased(int key){
	map->keyReleased(key);
}

void GameState::reset(){
	setFinished(false);
	setNextState("");
}

int GameState::getFinalScore(){
	return finalScore;
}

GameState::~GameState(){
	delete map;
}