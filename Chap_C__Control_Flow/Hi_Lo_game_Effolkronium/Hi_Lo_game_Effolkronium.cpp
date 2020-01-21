#include <iostream>
#include "random.hpp"

/*Using Effolkronium random library: https://github.com/effolkronium/random */

void playHiLo(const int right_answer) {

	const int max_tries{ 7 };
	int try_counter{ 1 };
	int guess{};

	std::cout << "Let's play a game.  I'm thinking of a number.  You have " << max_tries << " tries to guess what it is.\n";

	while (try_counter <= max_tries) {

		std::cout << "Guess #" << try_counter << ": ";
		std::cin >> guess;

		if (guess == right_answer) {
			std::cout << "Correct! You win!\n";
			break;
		}
		else {
			if (guess < right_answer) {
				std::cout << "too low...\n";
			}
			else {
				std::cout << "too high...\n";
			}
		}

		++try_counter;
	}

	if (guess != right_answer) {
		std::cout << "You lose... the correct answer was: " << right_answer << "\n";
	}
}

int main() {

	char userWantsToPlay{ 'y' };

	// get base random alias which is auto seeded and has static API and internal state
	using Random = effolkronium::random_static;

	while (userWantsToPlay == 'y') {
		const int answer{ Random::get(1, 100) };
		playHiLo(answer);
		std::cout << "Play again? ('y' or 'n') \n";
		std::cin >> userWantsToPlay;
	}

}