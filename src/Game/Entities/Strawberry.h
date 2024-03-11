#pragma once
#include "PowerUp.h"
#include "Entity.h"

class Strawberry: public PowerUp , public Entity {
    public:
        bool powerActivated;
        Strawberry(int, int, int, int, ofImage);
        void activate(){
            powerActivated = true;
        }
};