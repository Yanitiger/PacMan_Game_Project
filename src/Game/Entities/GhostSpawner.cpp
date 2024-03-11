#include "GhostSpawner.h"
#include "Ghost.h"

GhostSpawner::GhostSpawner(int x, int y, int width, int height, EntityManager* em, ofImage sprite) : Entity(x, y, width, height){
    this->em = em;
    this->sprite = sprite;
    spawnGhost("red");
    spawnGhost("pink");
    spawnGhost("cyan");
    spawnGhost("orange");

}

void GhostSpawner::tick(){

    if(em->ghosts.size()<4){
        if(spawnCounter == 0){
            spawnGhost(colors[ofRandom(4)]);
            spawnCounter = 30*5;
        }else{
            spawnCounter--;
        }
    }
}
void GhostSpawner::spawnGhost(string color){
    Ghost* g = new Ghost(x,y,width-2,height-2,sprite,em, color);
    em->ghosts.push_back(g);
}

void GhostSpawner::keyPressed(int key){

 /*If g is Pressed and there are less than 8 ghost, it will make a new ghost
  and chose a random color inside the color vector*/
//---------------------------------------------------------------------------
    if(key == 'g' || key == 'G'){
        if(em->ghosts.size() < 8) {
            spawnGhost(colors[ofRandom(4)]);
        }
    }
}