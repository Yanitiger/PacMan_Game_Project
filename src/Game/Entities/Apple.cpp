#include "Apple.h"
#include "Entity.h"
Apple::Apple(int x, int y, int width, int height, ofImage spriteSheet): Entity(x, y, width, height){
    sprite.cropFrom(spriteSheet, 539,50,16,16);
    
}