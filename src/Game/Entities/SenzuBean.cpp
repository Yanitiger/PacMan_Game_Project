//-------------------------------------------- Bono Añadido ----------------------------------------------------
#include "SenzuBean.h"

SenzuBean::SenzuBean(int x, int y, int width, int height, ofImage senzuBean): Entity(x, y, width, height){
    senzuBean.load("images/senzubean.png");
    sprite.cropFrom(senzuBean, 45,45,245,310);
}
