//-------------------------------------------- Bono Añadido ----------------------------------------------------
#pragma once 

#include "Entity.h"
#include "PowerUp.h"

class SenzuBean : public PowerUp, public Entity  {
    public:
        bool powerActivated;

        SenzuBean(int, int, int, int, ofImage);
        void activate() {
            powerActivated = true;
        }
};