#include "GameStateMap4.h"
#include "Entity.h"

GameStateMap4::GameStateMap4() {
	music.load("music/Mario64StarTheme.wav"); // Added new song as a bonus -EAHC
	mapImage.load("images/map4.png"); // When this gamestate is chosen, the map loaded will be Map 4 -EAHC
	// Map 4 is also a Bonus -EAHC
	map = MapBuilder().createMap(mapImage);

}
void GameStateMap4::tick() {
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
			music.stop();
		}
		if(map->getEntityManager()->entities.size() == 0){ 
			setFinished(true);
			setNextState("Win");
			map->getPlayer()->setHealth(3);
			finalScore = map->getPlayer()->getScore();
			map->getPlayer()->setScore(0);
			music.stop();
		}
	}
}
void GameStateMap4::render() {
	map->render();
}

void GameStateMap4::keyPressed(int key){
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

void GameStateMap4::mousePressed(int x, int y, int button){
	map->mousePressed(x, y, button);
}

void GameStateMap4::keyReleased(int key){
	map->keyReleased(key);
}

void GameStateMap4::reset(){
	setFinished(false);
	setNextState("");
}

int GameStateMap4::getFinalScore(){
	return finalScore;
}

GameStateMap4::~GameStateMap4(){
	delete map;
}