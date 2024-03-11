#pragma once

#include "Animation.h"
#include "EntityManager.h"
#include "PowerUp.h"
#include "Strawberry.h"
#include "Apple.h"

enum MOVING {
	MUP,
	MDOWN,
	MLEFT,
	MRIGHT,
};
class Player: public Entity{

    private:
        int spawnX, spawnY;
        unsigned int health=3;
        int score=0;
        bool canMoveUp, canMoveDown, canMoveRight, canMoveLeft;
        int speed = 4;
        bool walking = false;
        vector <PowerUp> powerUpStrg;
        int tickCounter = 0;
        bool timeOut = false;
        MOVING moving;
        FACING facing = DOWN;
        ofImage up, down, left, right;
        ofImage up2, down2, left2, right2;
        Animation *walkUp;
        Animation *walkDown;
        Animation *walkLeft;
        Animation *walkRight;
        Animation *walkUp2;
        Animation *walkDown2;
        Animation *walkLeft2;
        Animation *walkRight2;
        EntityManager* em;
        string choosenPlayer;
        ofImage sprite2;

        PowerUp *power = 0;

    public:
        Player(int, int, int , int, EntityManager*);
        ~Player();
        int getHealth();
        int getScore();
        
        void setPlayer(string);

        FACING getFacing();
        void setHealth(int);
        void setScore(int);
        void setFacing(FACING facing);
        void tick();
        void render();
        void keyPressed(int);
        void keyReleased(int);
        void damage(Entity* damageSource);
        void mousePressed(int, int, int);
        void reset();
        void checkCollisions();
        void die();

        ofImage senzuSprite;
        int transparent = 255;
        int teleport;
        bool invincible = false;
        int powerOnUse;
        int strawberryPowerCounter = 0;
        int applePowerCounter = 0;
        bool cherryPower = false;
        bool strawberryPower = false;
        bool applePower = false;
        bool powerOnMap;
        vector<string> powerFood;

};