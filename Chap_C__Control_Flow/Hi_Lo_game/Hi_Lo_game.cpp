#include <iostream>
#include <random> // for std::mt19937
#include <ctime> // for std::time

void playHiLo(const int right_answer) {

	const int max_tries{ 7 };
	int try_counter{ 1 };
	int guess{};

	std::cout << "Let's play a game.  I'm thinking of a number.  You have "<< max_tries <<" tries to guess what it is.\n";
	
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

	// Initialize our mersenne twister with a random seed based on the clock (once at system startup)
	std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

	// Create a reusable random number generator that generates uniform numbers between 1 and 6
	std::uniform_int_distribution<> die{ 1, 100 };

	while (userWantsToPlay == 'y'){
		const int answer{ die(mersenne) };
		playHiLo(answer);
		std::cout << "Play again? ('y' or 'n') \n";
		std::cin >> userWantsToPlay;
	} 
	 
}