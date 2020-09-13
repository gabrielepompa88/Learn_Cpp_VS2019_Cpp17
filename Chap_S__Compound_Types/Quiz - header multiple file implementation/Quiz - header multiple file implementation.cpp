#include "Race.h"
#include "Monster.h"
#include "IO_functions.h"

#include <string>
#include <iostream>

int main() {

	Monster ogre{ Race::OGRE, "Arturo", 145 };
	Monster slime{ Race::SLIME, "Blurp", 23 };

	printMonster(ogre);
	printMonster(slime);

}