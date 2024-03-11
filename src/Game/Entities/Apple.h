#pragma once
#include "PowerUp.h"
#include "Entity.h"

class Apple: public PowerUp , public Entity{
    public:
        bool powerActivated;
        Apple(int, int, int, int, ofImage);
        void activate(){
            powerActivated = true;
        }
};