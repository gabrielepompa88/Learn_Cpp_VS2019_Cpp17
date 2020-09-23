#include <ctime> // for time()
#include <cstdlib> // for rand() and srand()
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

class Monster {

public:
	enum class Type {
		DRAGON,
		GOBLIN,
		OGRE,
		ORC,
		SKELETON,
		TROLL,
		VAMPIRE,
		ZOMBIE,
		MAX_MONSTER_TYPES
	};

private:
	Type m_type;
	std::string name;
	std::string roar;
	int hitPoints;

public:

	Monster(Monster::Type monType, const std::string& monName, const std::string& monRoar, int monHitPoints) :
		m_type{ monType }, name{ monName }, roar{ monRoar }, hitPoints{ monHitPoints }
	{
	}

	std::string_view getTypeString() const {

		switch (m_type) {
		case Type::DRAGON:
			return "Dragon";
		case Type::GOBLIN:
			return "Goblin";
		case Type::OGRE:
			return "Ogre";
		case Type::ORC:
			return "Orc";
		case Type::SKELETON:
			return "Skeleton";
		case Type::TROLL:
			return "Troll";
		case Type::VAMPIRE:
			return "Vampire";
		case Type::ZOMBIE:
			return "Zombie";
		}
	}

	void print() const {
		std::cout << name << " the " << getTypeString() << " has " << hitPoints << " hit points and says " << roar << "\n";
	}
};


class MonsterGenerator {

	static const std::vector<std::string> s_names;	
	static const std::vector<std::string> s_roars;

public:

	static const Monster generateMonster() {

		Monster::Type randomType = static_cast<Monster::Type>(MonsterGenerator::getRandomNumber(0, static_cast<int>(Monster::Type::MAX_MONSTER_TYPES) - 1));
		int randomHitPoints = MonsterGenerator::getRandomNumber(1, 100);

		return Monster(randomType, s_names[getRandomNumber(0, 5)], s_roars[getRandomNumber(0, 5)], randomHitPoints);
	}

	// Generate a random number between min and max (inclusive)
	// Assumes srand() has already been called
	static int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
		// evenly distribute the random number across our range
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}

};

const std::vector<std::string> MonsterGenerator::s_names{ "name1", "name2" , "name3" , "name4" , "name5" , "name6" };
const std::vector<std::string> MonsterGenerator::s_roars{ "roar1", "roar2" , "roar3" , "roar4" , "roar5" , "roar6" };

int main()
{
	Monster skele(Monster::Type::SKELETON, "Bones", "*rattle*", 4);
	skele.print();

	std::srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	std::rand(); // If using Visual Studio, discard first random value

	Monster m = MonsterGenerator::generateMonster();
	m.print();
	
	return 0;
}