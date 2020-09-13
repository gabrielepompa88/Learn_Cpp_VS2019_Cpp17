#include "Race.h"
#include "Monster.h"
#include "IO_functions.h"

#include <string>
#include <iostream>

int main() {

	extern struct Monster ogre;
	extern struct Monster slime;

	printMonster(ogre);
	printMonster(slime);

}