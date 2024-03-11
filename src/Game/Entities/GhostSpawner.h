#pragma once

#include "EntityManager.h"

class GhostSpawner: public Entity{
    public:

        GhostSpawner(int, int, int , int, EntityManager*, ofImage);
        void spawnGhost(string);
        void keyPressed(int);
        void tick();

    	/*-------------- Added Functions/Methods ---------------*/
        std::vector<string> colors {"red", "pink", "cyan" ,"orange"};
        
    private:
        EntityManager* em;
        int spawnCounter = 30*5;
};