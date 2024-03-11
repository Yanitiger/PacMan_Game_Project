#include "GameStateMap3.h"
#include "Entity.h"

GameStateMap3::GameStateMap3() {
	music.load("music/pacman_chomp.wav");
	mapImage.load("images/map3.png"); // When this gamestate is chosen, the map loaded will be Map 3 -EAHC
	map = MapBuilder().createMap(mapImage);

}
void GameStateMap3::tick() {
/* If the game is Paused then change to the PauseState and ignore everything else, otherwise countinue normally*/
	if(gamePaused == true) {
		setNextState("PauseState");
		gamePaused = false;

	} else {
			map->getPlayer()->setPlayer("pacman");

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
		if(map->getEntityManager()->entities.size() == 0){ 
			setFinished(true);
			setNextState("Win");
			map->getPlayer()->setHealth(3);
			finalScore = map->getPlayer()->getScore();
			map->getPlayer()->setScore(0);
		}
	}
}
void GameStateMap3::render() {
	map->render();
}

void GameStateMap3::keyPressed(int key){
	map->keyPressed(key);
	
//----------------------------------------------
	if(key == 'p' || key == 'P') {
		gamePaused = !gamePaused;
	}
	if(key == 'y' || key == 'Y'){
		map->getEntityManager()->entities.clear();
	// when lowercase or uppercase 'y' is pressed, you will automatically be sent to the victory screen. -EAHC

	}
}

void GameStateMap3::mousePressed(int x, int y, int button){
	map->mousePressed(x, y, button);
}

void GameStateMap3::keyReleased(int key){
	map->keyReleased(key);
}

void GameStateMap3::reset(){
	setFinished(false);
	setNextState("");
}

int GameStateMap3::getFinalScore(){
	return finalScore;
}

GameStateMap3::~GameStateMap3(){
	delete map;
}