#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "Terminal.hpp"

class GameState {
private:
	Terminal term;
	int difficulty;
	int curLevel;

	std::string getDifficultyString(int difficulty) const;
	std::string toLower(std::string& arg) const;

public:
	GameState(int h, int w, int d);

	void runStartScreen();
	void runSelectDiffScreen();
	void startGame();
	void runEndScreen();
	void runVictoryScreen();
};

#endif
