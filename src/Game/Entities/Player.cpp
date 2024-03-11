#include "Player.h"
#include "EntityManager.h"
#include "Dot.h"
#include "BigDot.h"
#include "Ghost.h"
#include "ChoosePlayerState.h"
#include "PowerUp.h"
#include "Strawberry.h"
#include "Apple.h"
#include "Cherry.h"
#include "SenzuBean.h"

Player::Player(int x, int y, int width, int height, EntityManager* em) : Entity(x, y, width, height){
    
    /* Create both player to choose between */
        spawnX = x;
        spawnY = y;

        senzuSprite.load("images/sensubean.png");
        senzuSprite.cropFrom(senzuSprite, 45,45,245,310);

        sprite.load("images/pacman.png");

        down.cropFrom(sprite, 0, 48, 16, 16);
        up.cropFrom(sprite, 0, 32, 16, 16);
        left.cropFrom(sprite, 0, 16, 16, 16);
        right.cropFrom(sprite, 0, 0, 16, 16);

        vector<ofImage> downAnimframes;
        vector<ofImage> upAnimframes;
        vector<ofImage> leftAnimframes;
        vector<ofImage> rightAnimframes;
        ofImage temp;

        for(int i=0; i<3; i++){
            temp.cropFrom(sprite, i*16, 48, 16, 16);
            downAnimframes.push_back(temp);
        }
        for(int i=0; i<3; i++){
            temp.cropFrom(sprite, i*16, 32, 16, 16);
            upAnimframes.push_back(temp);
        }
        for(int i=0; i<3; i++){
            temp.cropFrom(sprite, i*16, 16, 16, 16);
            leftAnimframes.push_back(temp);
        }
        for(int i=0; i<3; i++){
            temp.cropFrom(sprite, i*16, 0, 16, 16);
            rightAnimframes.push_back(temp);
        }


        walkDown = new Animation(1,downAnimframes);
        walkUp = new Animation(1,upAnimframes);
        walkLeft = new Animation(1,leftAnimframes);
        walkRight = new Animation(1,rightAnimframes);


        sprite2.load("images/Arceus2.png");

        down2.cropFrom(sprite2, 146, 87, 49, 70);
        up2.cropFrom(sprite2, 146, 296, 49, 70);
        left2.cropFrom(sprite2, 145, 166, 58, 62);
        right2.cropFrom(sprite2, 145, 230, 58, 62);

        vector<ofImage> downAnimframes2;
        vector<ofImage> upAnimframes2;
        vector<ofImage> leftAnimframes2;
        vector<ofImage> rightAnimframes2;
        ofImage temp2;

        for(int i=0; i<3; i++){
            temp2.cropFrom(sprite2, 146 * 1.5, 87, 49, 70);
            downAnimframes2.push_back(temp2);
        }
        for(int i=0; i<3; i++){
            temp2.cropFrom(sprite2, 146 * 1.5, 296, 49, 70);
            upAnimframes2.push_back(temp2);
        }
        for(int i=0; i<3; i++){
            temp2.cropFrom(sprite2, 145 * 1.5, 166, 58, 62);
            leftAnimframes2.push_back(temp2);
        }
        for(int i=0; i<3; i++){
            temp2.cropFrom(sprite2, 145 * 1.5, 230, 58, 62);
            rightAnimframes2.push_back(temp2);
        }

        walkDown2 = new Animation(1,downAnimframes2);
        walkUp2 = new Animation(1,upAnimframes2);
        walkLeft2 = new Animation(1,leftAnimframes2);
        walkRight2 = new Animation(1,rightAnimframes2);


    
    this->em = em;

    moving = MLEFT;
    
    
    
}
void Player::tick(){

    checkCollisions();

    if (moving == MUP && canMoveUp) 
        facing = UP;
    else if (moving == MDOWN && canMoveDown) 
        facing = DOWN;
    else if (moving == MLEFT && canMoveLeft) 
        facing = LEFT;
    else if (moving == MRIGHT && canMoveRight)
        facing = RIGHT;

    if(choosenPlayer == "pacman") {
        if(facing == UP && canMoveUp){
            y-= speed;
            walkUp->tick();
        }else if(facing == DOWN && canMoveDown){
            y+=speed;
            walkDown->tick();
        }else if(facing == LEFT && canMoveLeft){
            x-=speed;
            walkLeft->tick();
        }else if(facing == RIGHT && canMoveRight){
            x+=speed;
            walkRight->tick();
        }  
    }else if(choosenPlayer == "arceus") {
        if(facing == UP && canMoveUp){
            y-= speed;
            walkUp2->tick();
        }else if(facing == DOWN && canMoveDown){
            y+=speed;
            walkDown2->tick();
        }else if(facing == LEFT && canMoveLeft){
            x-=speed;
            walkLeft2->tick();
        }else if(facing == RIGHT && canMoveRight){
            x+=speed;
            walkRight2->tick();
        }
    }
    /* Once 10 seconds pass, the player will loose its invincibility and transparrancy */
    if(strawberryPower){
        strawberryPowerCounter--;
        if (strawberryPowerCounter == 0){
            transparent = 255;
            invincible = false; // When counter reaches 0, player is no longer invincible
            strawberryPower = false;    
        }
    } /* Once 10 seconds pass, the player speed will be set back to normal */
    if(applePower){ // EAHC
        applePowerCounter--;
        if (applePowerCounter == 0){
            speed = 4; // When counter reaches 0, speed goes back to normal -EAHC  
            applePower = false;
        }
    }
    
}

void Player::render(){
    
    ofSetColor(256,256,256, transparent);
    
    if(facing == UP && choosenPlayer == "pacman")
        walkUp->getCurrentFrame().draw(x, y, width, height);
    else if(facing == DOWN && choosenPlayer == "pacman")
        walkDown->getCurrentFrame().draw(x, y, width, height);
    else if(facing == LEFT && choosenPlayer == "pacman")
        walkLeft->getCurrentFrame().draw(x, y, width, height);
    else if(facing == RIGHT && choosenPlayer == "pacman")
        walkRight->getCurrentFrame().draw(x, y, width, height);

    if(facing == UP && choosenPlayer == "arceus")
        walkUp2->getCurrentFrame().draw(x, y, width, height);
    else if(facing == DOWN && choosenPlayer == "arceus")
        walkDown2->getCurrentFrame().draw(x, y, width, height);
    else if(facing == LEFT && choosenPlayer == "arceus")
        walkLeft2->getCurrentFrame().draw(x, y, width, height);
    else if(facing == RIGHT && choosenPlayer == "arceus")
        walkRight2->getCurrentFrame().draw(x, y, width, height);


    //  sprite.draw(0,0,ofGetWidth(),ofGetHeight());
    
    ofSetColor(256, 0, 0);
    ofDrawBitmapString("Health: ", ofGetWidth()/2 + 100, 50);

    for(unsigned int i=0; i<health; i++){
        ofDrawCircle(ofGetWidth()/2 + 25*i +200, 50, 10);
    }

    ofDrawBitmapString("Score:"  + to_string(score), ofGetWidth()/2-200, 50);

    if(!powerFood.empty()){
        ofDrawBitmapString("Powers in Order: " + ofToString(powerFood) ,400, 30);
    
    }else {
        ofDrawBitmapString("Pick a PowerUp to activate",400, 30);
    
    } 
    
}

void Player::keyPressed(int key){

    /* Made Pacman or Arceus also move with arrow keys */

    if (key == 'w' ||key == 'W' ||key == OF_KEY_UP) {
        moving = MUP;
    }

    if (key == 's' ||key == 'S' ||key == OF_KEY_DOWN) {
        moving = MDOWN;
    }

    if (key == 'a' ||key == 'A' ||key == OF_KEY_LEFT) {
        moving = MLEFT;
    }

    if (key == 'd' ||key == 'D' ||key == OF_KEY_RIGHT) {
        moving = MRIGHT;
    }
    /* If the player is not invicible it will die */
    if (key == 'n' || key == 'N') {
        if(!invincible) {
           die(); 
        }
        
    }
    /* Add another life only if the lifes are less than 3 */
    if(key == 'm' || key == 'M' ) {
        if(health < 3) {
                health++;
        }
    }

    if(key == ' ' ) {
        
        if(power != nullptr) {
            power->activate();
            power = 0;
        }
    /* If powerFood vector is not empty check which is the first powerUp available */
        if(!powerFood.empty()) {
            /* Instantly teleport player to a random position inside the vectors sizes */
            if(powerFood[0] == "CherryPower") {
            teleport = ofRandom(0,em->entities.size() - 1);
            x = em->entities[teleport]->getX();
            y = em->entities[teleport]->getY();
               
            }
            /* Double the speed of the player */
            if(powerFood[0] == "ApplePower") {
            speed = 8; // when apple is activated, speed is increased to 8 -EAHC
            applePowerCounter=10*ofGetFrameRate(); // the counter value is stablished when apple is activated and will last for only 300 ticks -EAHC
            applePower = true;
            }

            /* Make the player invincible (not able to die) & make him transparent */
            if(powerFood[0] == "StrawberryPower") {
            
            invincible = true;
            strawberryPowerCounter=10*ofGetFrameRate();// the counter value is stablished when strawberry is activated and will last for only 300 ticks -EAHC
            transparent = 128;
            strawberryPower = true;
            
            }
            /* Erase the first element inside the vector */
            powerFood.erase(powerFood.begin());
        }
        
    }
    
}

void Player::keyReleased(int key){
    if(key == 'w' || key =='s' || key == 'a' || key == 'd'){
        walking = false;
    }
}
void Player::mousePressed(int x, int y, int button){

}

int Player::getHealth(){ return health; }
int Player::getScore(){ return score; }


FACING Player::getFacing(){ return facing; }
void Player::setHealth(int h){ health = h; }
void Player::setFacing(FACING facing){ this->facing = facing; }
void Player::setScore(int h){ score = h; }

void Player::setPlayer(string name)  { choosenPlayer = name ;}

void Player::checkCollisions(){
    canMoveUp = true;
    canMoveDown = true;
    canMoveLeft = true;
    canMoveRight = true;

    for(BoundBlock* boundBlock: em->boundBlocks){
        if(this->getBounds(x, y-speed).intersects(boundBlock->getBounds()))
            canMoveUp = false;
        if(this->getBounds(x, y+speed).intersects(boundBlock->getBounds()))
            canMoveDown = false;
        if(this->getBounds(x-speed, y).intersects(boundBlock->getBounds()))
            canMoveLeft = false;
        if(this->getBounds(x+speed, y).intersects(boundBlock->getBounds()))
            canMoveRight = false;
    }
    for(Entity* entity:em->entities){
        if(collides(entity)){
            if(dynamic_cast<Dot*>(entity) || dynamic_cast<BigDot*>(entity)){
                entity->remove = true;
                score += 10;
            }
            if(dynamic_cast<BigDot*>(entity)){
                score +=20;
                em->setKillable(true);
            }

        /* If the player collides with the senzuBean it will only consume it if its health is below 3 */
            if(dynamic_cast<SenzuBean*>(entity)) {
                if(health < 3) {
                    entity->remove = true;
                    health++;
                }
            }

/* If the player collides with one of the following fruits it will only consume it if the player has less than 3 powers*/
            /* if the player alreadys has 3 powers, the fruits will not be consume until he uses one*/
            if(dynamic_cast<Cherry*>(entity)) {
                if(powerFood.size() < 3) {
                    score +=500; // when player collides with cherry, he gets 500 points like in the original game -EAHC
                    entity->remove = true;
                    powerFood.push_back("CherryPower"); 
                } 

            }

            if(dynamic_cast<Strawberry*>(entity)) {  
                if(powerFood.size() < 3) {
                    powerFood.push_back("StrawberryPower"); // The strawberry get added to the vector containing all the powerups the player collides with -EAHC
                    score +=200;// when player collides with strawberry, he gets 200 points like in the original game -EAHC
                    entity->remove = true;
                } 

            }
            if(dynamic_cast<Apple*>(entity)) { 
                if(powerFood.size() < 3) {
                    powerFood.push_back("ApplePower"); // The strawberry get added to the vector containing all the powerups the player collides with -EAHC
                    score +=700; // when player collides with apple, he gets 700 points like in the original game -EAHC
                    entity->remove = true;
                }

            }
        }
    }
    for(Entity* entity:em->ghosts){
        if(collides(entity)){
            Ghost* ghost = dynamic_cast<Ghost*>(entity);
            if(ghost->getKillable())
                ghost->remove = true;
            else {
                if(!invincible) {
                    die(); 
                }
            }
               
        }
    } 
    

    
}

void Player::die(){
    health--;
    x = spawnX;
    y = spawnY;

}

Player::~Player(){
    delete walkUp;
    delete walkDown;
    delete walkLeft;
    delete walkRight;
    delete walkUp2;
    delete walkDown2;
    delete walkLeft2;
    delete walkRight2;
}