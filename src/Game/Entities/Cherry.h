#pragma once 

#include "Entity.h"
#include "PowerUp.h"

class Cherry : public PowerUp, public Entity  {
    public:
        bool powerActivated;

        Cherry(int, int, int, int, ofImage);
        void activate() {
            powerActivated = true;
        }
};