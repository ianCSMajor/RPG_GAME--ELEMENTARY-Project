#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "Entity.hpp"
#include "Attack.hpp"
#include "Terminal.hpp"
#include "EnemyFactory.hpp"
//#include "EnemyAttack.hpp"

class GameState {
private:
	Terminal term;
	int difficulty;
	int curLevel;


	std::string toLower(std::string& arg) const;

public:
	GameState(int h, int w, int d);
  ~GameState();
  std::string getDifficultyString(int difficulty) const;
	void runStartScreen();
  void attackScreen();
  void levelWin();
	void runSelectDiffScreen();
	void startGame();
	void runEndScreen();
  void runVictoryScreen();
  void gameOverScreen();
  void title();
};

#endif