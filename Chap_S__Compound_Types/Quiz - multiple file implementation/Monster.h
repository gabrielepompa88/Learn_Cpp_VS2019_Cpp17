#ifndef MONSTER_H
#define MONSTER_H

#include "Race.h"

#include <string>

struct Monster {
	Race race;
	std::string name;
	int health;
};

// forward declarations: ogre and slime are defined in Monster.cpp and available whenever
// the "Monster.h" header file is #included
extern struct Monster ogre;  
extern struct Monster slime;

#endif