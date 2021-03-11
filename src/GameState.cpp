#include "../header/GameState.hpp"
#include <iostream>
#include <sstream>

GameState::GameState(int h, int w, int d): term(h, w), difficulty(d), curLevel(1) {}

std::string GameState::getDifficultyString(int difficulty) const {
	switch (difficulty) {
		case 0: return "Easy";
		case 1: return "Normal";
		case 2: return "Hard";
		default: return " ";
	}
}

std::string GameState::toLower(std::string& arg) const {
	std::string ret = arg;
	for (int i = 0; i < arg.size(); i++) {
		if (arg.at(i) >= 'A' && arg.at(i) <= 'Z') {
			arg[i] += 'a' - 'A';
		}
	}
	return ret;
}

void GameState::runStartScreen() {
	int decision = 0;
	std::string diffToPrint = "Difficulty: " + getDifficultyString(difficulty);
	std::string temp = "";
	std::string input;
	
	while (decision != 2) {
		term.clear();
		term.write("####          ####", -1, 11);
		term.write("##              ##", -1, 12);
		term.write("#   MAGICQUEST   #", -1, 13);
		term.write("##              ##", -1, 14);
		term.write("####          ####", -1, 15);
		term.write(diffToPrint, -1, 17);
		term.write("d - Select Difficulty", -1, 19);
		term.write("s - Start Game", -1, 20);
		term.write(temp, -1, 22);
		term.display();
		
		getline(std::cin, input);
		input = toLower(input);
		if (input == "d") {
			// temp = "select diff";
			decision = 1;
		} else if (input == "s") {
			// temp = "starting game";
			decision = 2;
		} else {
			temp = "Bad input: \"" + input + "\"";
		}
		
		if (decision == 1) {
			runSelectDiffScreen();
		} else if (decision == 2) {
			startGame();
		}
	}
}
	
void GameState::runSelectDiffScreen() {
	std::string temp = "";
	std::string input;
	std::string diff1 = difficulty == 0 ? "Easy <--" : "e: Easy";
	std::string diff2 = difficulty == 1 ? "Normal <--" : "n: Normal";
	std::string diff3 = difficulty == 2 ? "Hard <--" : "h: Hard";

	bool done = false;

	while (!done) {
		term.clear();
		term.write("Select Difficulty:", -1, 11);

		term.write(diff1, -1, 13);
		term.write(diff2, -1, 14);
		term.write(diff3, -1, 15);
		term.write(temp, -1, 17);
		term.display();
		
		getline(std::cin, input);
		input = toLower(input);
		if (difficulty != 0 && input == "e") {
			difficulty = 0;
			done = true;
		} else if (difficulty != 1 && input == "n") {
			difficulty = 1;
			done = true;
		} else if (difficulty != 2 && input == "h") {
			difficulty = 2;
			done = true;
		} else {
			temp = "Bad input: \"" + input + "\"";
		}
	}
}
	
void GameState::startGame() {
	std::string input;
	std::stringstream ss;
	
	while (curLevel <= 10) {
		term.clear();
		ss << "Level " << curLevel;
		term.write(ss.str(), -1, -1);
		ss.str("");
		term.display();
		getline(std::cin, input);
		curLevel++;
	}

	runEndScreen();
}

void GameState::runEndScreen() {
	std::string input;
	
	term.clear();
	term.write("End screen", -1, -1);
	term.display();
	getline(std::cin, input);

}
void GameState::runVictoryScreen() {
	std::string input;
	
	term.clear();
	term.write("You win, congratulations", -1, -1);
	term.display();
	getline(std::cin, input);
}
