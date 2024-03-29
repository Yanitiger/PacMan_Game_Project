#pragma once

#include "ofMain.h" 
#include "Map.h"
#include "Dot.h"
#include "BigDot.h"
#include "Ghost.h"

class MapBuilder {
    public:
        MapBuilder();
	    Map* createMap(ofImage);
        
	private:
        vector<ofImage> bound;
        int pixelMultiplier;
        
        ofColor boundBoundBlock;
        ofColor pacman;
        ofColor arceus; 
        ofColor ghostC;
	    ofColor dotC;
	    ofColor bigDotC;
        ofColor senzu;
        ofImage senzuSheet;
        ofImage pacmanSpriteSheet;
        ofImage tempBound;
        ofImage getSprite(ofImage, int, int);
        EntityManager* entityManager;
};