#include "GameState.hpp"
#include <iostream>
#include <sstream>
//#include "EnemyAttack.hpp"
using namespace std;

//void attack2(Entity*, Entity*);

/*fields:
    Terminal term;
	  int difficulty;
	  int curLevel;
*/

//constructor creates terminal and sets difficulty
GameState::GameState(int h, int w, int d): term(h, w), difficulty(d), curLevel(1) {}



std::string GameState::getDifficultyString(int difficulty) const {
	switch (difficulty) {
		case 0: return "Easy";
		case 1: return "Normal";
		case 2: return "Hard";
		default: return " ";
	}
}

//converts user input to lowercase
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
	//std::string diffToPrint = "Difficulty: " + getDifficultyString(difficulty);
	string temp = "";
	std::string input;
  //char difficulty;
	title();
	while (decision != 2) {
    
		//term.clear();
 
		//term.write(diffToPrint, -1, 17);
		term.write("d - Select Difficulty", -1, 19);
		term.write("s - Start Game", -1, 20);
		term.write(temp, -1, 28);
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
  char diff;
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
      diff = 'e';
			done = true;
		} else if (difficulty != 1 && input == "n") {
			difficulty = 1;
      diff = 'n';
			done = true;
		} else if (difficulty != 2 && input == "h") {
			difficulty = 2;
      diff = 'h';
			done = true;
		} else {
			temp = "Bad input: \"" + input + "\"";
		}
	}
}

void GameState::startGame() {
	std::string input;
	std::stringstream ss;
  string name;
  int chooseAtk;
  int numAttacks = 5;
  // create player and set player's attack
  cout<<"Enter Player Name: "<<endl;
  getline(cin, name);
  //Player player1(name, 100);
std::string conflict;
 conflict = getDifficultyString(difficulty);
 Entity* player1;
  if(conflict == "Easy"){
    player1 = new Player(name, 1500);
    }
  else if(conflict == "Normal"){
     player1 = new Player(name, 1000);
  }
   else if(conflict == "Hard"){
     player1 = new Player(name, 50);
  }


  
  // Player player1(name, 1000);
  //player1->ascii();
  //player1->entityInfo();
  player1->setAttack(new SwordAttack());

  //create enemy factory
  EnemyFactory* factory= new EnemyFactory();


//===============================GAME LOOP============================//
  
	
	while (curLevel <= 5) {
    player1->ascii();
    player1->entityInfo();
    cout << "\n\nPRESS START\n\n";
    getline(cin, input);
    //cout << "Level " << curLevel << endl;
    term.clear();
		ss << "Level " << curLevel;
		term.write(ss.str(), -1, -1);
		ss.str("");
		term.display();
    getline(std::cin, input);


    
    //create enemy
    Entity* curEnemy = factory->createEnemy(curLevel);
    curEnemy->entityInfo();
    
    while(curEnemy->getHP()>0){

      bool properInput = false;
      while (!properInput) {
        cout << endl;
        cout <<player1->getName()<<" declares and attack with "<< player1->getAttack()->getAtkName() << endl;

        // for (int i = 0; i < numAttacks; i++) {
        //   cout << (i + 1) << ": " << attacks[i]->getAtkName() << "  ";
        // }
        attackScreen();
        cout << endl;

        getline(cin, input);
        if (input.size() != 1) {
          cout << "Invalid input!" << endl;
          continue;
        }
        char inpc = input.at(0);

        if (inpc >= '1' && inpc < '1' + numAttacks) {
          switch (inpc) {
            case '1': player1->setAttack(new SwordAttack()); break;
            case '2': player1->setAttack(new WaterAttack()); break;
            case '3': player1->setAttack(new FireAttack()); break;
            case '4': player1->setAttack(new EarthAttack()); break;
            case '5': player1->setAttack(new AirAttack()); break;
          }
          properInput = true;
        } else {
          cout << "Invalid input!" << endl;
          continue;
        }
        
      }
      player1->attack(curEnemy);
      // cout << "\n\nEnemy is making its move! PRESS ENTER\n";
      // getline(cin ,input);
      curEnemy->attack(player1);
      //enemyAttack(curEnemy, player1, curLevel);
      if(player1->getHP() <= 0)
      {
        break;
      }
    }
      if(player1->getHP() <= 0)
      {
        gameOverScreen();
        delete factory;
        delete player1;
        delete curEnemy;
        break;
      }
      delete curEnemy;
      levelWin();
      if(curLevel == 5){
        delete factory;
        delete player1;

      }
      getline(cin, input);
      curLevel++;
  }
    
    
    //delete curEnemy;
 
 
	runEndScreen();
}


void GameState::title() {
	std::string input;
	term.clear();
		cout<<"\n\n\n\n\n\n\n\n\n\n                 ___           ___       ___           ___           ___           ___           ___           ___           ___           ___"<<endl;
		cout<<"                /\\  \\         /\\__\\     /\\  \\         /\\__\\         /\\  \\         /\\__\\         /\\  \\         /\\  \\         /\\  \\         |\\__\\"<<endl;
		cout<<"               /::\\  \\       /:/  /    /::\\  \\       /::|  |       /::\\  \\       /::|  |        \\:\\  \\       /::\\  \\       /::\\  \\        |:|  |"<<endl;
		cout<<"              /:/\\:\\  \\     /:/  /    /:/\\:\\  \\     /:|:|  |      /:/\\:\\  \\     /:|:|  |         \\:\\  \\     /:/\\:\\  \\     /:/\\:\\  \\       |:|  |"<<endl;
		cout<<"             /::\\~\\:\\  \\   /:/  /    /::\\~\\:\\  \\   /:/|:|__|__   /::\\~\\:\\  \\   /:/|:|  |__       /::\\  \\   /::\\~\\:\\  \\   /::\\~\\:\\  \\      |:|__|__"<<endl;
    cout<<"            /:/\\:\\ \\:\\__\\ /:/__/    /:/\\:\\ \\:\\__\\ /:/ |::::\\__\\ /:/\\:\\ \\:\\__\\ /:/ |:| /\\__\\     /:/\\:\\__\\ /:/\\:\\ \\:\\__\\ /:/\\:\\ \\:\\__\\     /::::\\\\__\\\\"<<endl;
    cout<<"            \\:\\~\\:\\ \\/__/ \\:\\  \\    \\:\\:\\ \\  /__/ \\/__/~~/:/  / \\:\\~\\:\\ \\/__/ \\/__|:|/:/  /    /:/  \\/__/ \\/__\\:\\/:/  / \\/_|::\\/:/  /    /:/~~/~"<<endl;
    cout<<"             \\:\\ \\:\\__\\    \\:\\  \\    \\:\\ \\:\\__\\         /:/  /   \\:\\ \\:\\__\\       |:/:/  /    /:/  /           \\::/  /     |:|::/  /    /:/  / "<<endl;
    cout<<"              \\:\\ \\/__/     \\:\\  \\    \\:\\ \\/__/        /:/  /     \\:\\ \\/__/       |::/  /     \\/__/            /:/  /      |:|\\/__/     \\/__/"<<endl;
    cout<<"               \\:\\__\\        \\:\\__\\    \\:\\__\\         /:/  /       \\:\\__\\         /:/  /                      /:/  /       |:|  |"<<endl;
    cout<<"                \\/__/         \\/__/     \\/__/         \\/__/         \\/__/         \\/__/                       \\/__/         \\|__|"<<endl<<endl<<endl<<endl;
    cout << "                                                            PRESS ENTER KEY TO START";
	getline(std::cin, input);
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
void GameState::gameOverScreen() {
	std::string input;
	term.clear();
	term.write("GAME OVER", -1, 11);
	term.display();
	getline(std::cin, input);
}

void GameState::levelWin(){
  	term.clear();
term.write("  _                   _    ____ _                 _  ", -1, 11);
 term.write("| |    _____   _____| |  / ___| | ___  __ _ _ __| | ", -1, 12);
 term.write("| |   / _ \\ \\ / / _ \\ | | |   | |/ _ \\/ _` | '__| | ", -1, 13);
 term.write("| |__|  __/\\ V /  __/ | | |___| |  __/ (_| | |  |_| ", -1, 14);
 term.write("|_____\\___| \\_/ \\___|_|  \\____|_|\\___|\\__,_|_|  (_) ", -1, 15);

		term.display();
    //term.clear();

}
void GameState::attackScreen(){
cout << "_______________________________________\n";
cout << "|------------ATTACK MOVES-------------|\n";
cout << "_______________________________________\n";
cout << "| SWORD = 1  |  WATER = 2 |  FIRE = 3 |\n";
cout << "_______________________________________\n";
cout << "|     EARTH = 4      |     AIR = 5    |\n";
cout << "_______________________________________";

cout << "\n\nTYPE ATTACK: \n";

}

 GameState::~GameState(){
 }
