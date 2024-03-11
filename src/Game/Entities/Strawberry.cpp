#include "Strawberry.h"
#include "Entity.h"


Strawberry::Strawberry(int x, int y, int width, int height, ofImage spriteSheet): Entity(x, y, width, height){
    sprite.cropFrom(spriteSheet, 507,51,16,16);
}