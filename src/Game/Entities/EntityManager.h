#pragma once

#include "BoundBlock.h"

class EntityManager {

public:
	~EntityManager();
	std::vector<Entity*> entities;
	std::vector<BoundBlock*> boundBlocks;
	std::vector<Entity*> ghosts;
	
	void tick();
	void render();
	void setKillable(bool);

private:
	bool killable = false; //For fruit phase 3
	int killableCounter;
};