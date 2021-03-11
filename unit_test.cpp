#include "gtest/gtest.h"
#include "Entity.hpp"
#include "Attack.hpp"
#include "GameState.hpp"
//#include "Attack.cpp"
//#include "Entity.cpp"
//#include "GameState.cpp"
//#include "Terminal.cpp"


TEST(HPandNameTest, PlayerHP){
	Entity* ent = new Player("joe", 100);
	EXPECT_EQ(ent->getHP(), 100);
	EXPECT_EQ(ent->getName(), "joe");
	delete ent;
}
TEST(HPandNameTest, GnomeHP){
        Entity* ent = new Gnome("mama", 38);
        EXPECT_EQ(ent->getHP(), 38);
        EXPECT_EQ(ent->getName(), "mama");
	delete ent;
}

TEST(HPandNameTest, DragonHP){
        Entity* ent = new Dragon("zz", 9999);
        EXPECT_EQ(ent->getHP(), 9999);
        EXPECT_EQ(ent->getName(), "zz");
	delete ent;
}

TEST(HPandNameTest, TrollHP){
        Entity* ent = new Troll("blank", 20);
        EXPECT_EQ(ent->getHP(), 20);
        EXPECT_EQ(ent->getName(), "blank");
	delete ent;
}

TEST(HPandNameTest, RobotHP){
        Entity* ent = new Robot("ian", 70);
        EXPECT_EQ(ent->getHP(), 70);
        EXPECT_EQ(ent->getName(), "ian");
	delete ent;
}

TEST(HPandNameTest, JesterHP){
        Entity* ent = new Jester("adam", 10);
        EXPECT_EQ(ent->getHP(), 10);
        EXPECT_EQ(ent->getName(), "adam");
	delete ent;
}

TEST(HPandNameTest, ShroederHP){
	Entity* ent = new Shroeder("craig", 50);
	EXPECT_EQ(ent->getHP(), 50);
	EXPECT_EQ(ent->getName(), "craig");
	delete ent;
}

TEST(ChangeHPTest, ChangePlayerHP){
	Entity* ent = new Player("joe", 100);
	ent->changeHP(10);
	EXPECT_EQ(ent->getHP(), 110); 
	delete ent;
}

TEST(ChangeHPTest, ChangeGnomeHP){
	Entity* ent = new Gnome("mama", 38);
	ent->changeHP(20);
	EXPECT_EQ(ent->getHP(), 58);
	delete ent;
}

TEST(ChangeHPTest, ChangeTrollHP){
	Entity* ent = new Troll("blank", 20);
	ent->changeHP(-10);
	EXPECT_EQ(ent->getHP(), 10);
	delete ent;
}

TEST(ChangeHPTest, ChangeDragonHP){
	Entity* ent = new Dragon("zz", 9999);
	ent->changeHP(-9998);
	EXPECT_EQ(ent->getHP(), 1);
	delete ent;
}

TEST(ChangeHPTest, ChangeRobotHP){
	Entity* ent = new Robot("ian", 70);
	ent->changeHP(30);
	EXPECT_EQ(ent->getHP(), 100);
	delete ent;
}

TEST(ChangeHPTest, ChangeJesterHP){
	Entity* ent = new Jester("adam", 10);
	ent->changeHP(50);
	EXPECT_EQ(ent->getHP(), 60);
	delete ent;
}

TEST(ChangeHPTest, ChangeSchroederHP){
	Entity* ent = new Shroeder("craig", 100);
	ent->changeHP(-30);
	EXPECT_EQ(ent->getHP(), 70);
	delete ent;
}

TEST(SwordAttackTest, SwordAttackGnomeTest){
	Entity* ent1 = new Player("p", 500);
	Attack* swordatt = new SwordAttack();
	ent1->setAttack(swordatt);
	Entity* ent2 = new Gnome("goblin", 100);
	ent1->attack(ent2);
	EXPECT_EQ(ent2->getHP(), 80); 
	delete ent1;
	delete ent2;
}

TEST(SwordAttackTest, SwordAttackDragonTest) {
	Entity* ent1 = new Player("p", 500);
	Attack* swordatt = new SwordAttack();
	ent1->setAttack(swordatt);
	Entity* ent2 = new Dragon("drag", 300);
	ent1->attack(ent2);
	EXPECT_EQ(ent2->getHP(), 280);
	delete ent1;
	delete ent2;
}

TEST(SwordAttackTest, SwordAttackTrollTest) {
        Entity* ent1 = new Player("p", 500);
        Attack* swordatt = new SwordAttack();
        ent1->setAttack(swordatt);
        Entity* ent2 = new Troll("troll", 30);
        ent1->attack(ent2);
        EXPECT_EQ(ent2->getHP(), 10);
	delete ent1;
	delete ent2;
	
}

TEST(SwordAttackTest, SwordAttackRobotTest) {
        Entity* ent1 = new Player("p", 500);
        Attack* swordatt = new SwordAttack();
        ent1->setAttack(swordatt);
        Entity* ent2 = new Robot("robo", 50);
        ent1->attack(ent2);
        EXPECT_EQ(ent2->getHP(), 30);
	delete ent1;
	delete ent2;
	
}

TEST(SwordAttackTest, SwordAttackJesterTest) {
        Entity* ent1 = new Player("p", 500);
        Attack* swordatt = new SwordAttack();
        ent1->setAttack(swordatt);
        Entity* ent2 = new Dragon("jester", 25);
        ent1->attack(ent2);
        EXPECT_EQ(ent2->getHP(), 5);
	delete ent1;
	delete ent2;
	
}

TEST(SwordAttackTest, SwordAttackSchroederTest) {
        Entity* ent1 = new Player("p", 500);
        Attack* swordatt = new SwordAttack();
        ent1->setAttack(swordatt);
        Entity* ent2 = new Shroeder("craig", 21);
	Attack* wateratt = new WaterAttack();
	ent2->setAttack(wateratt);
        ent1->attack(ent2);
        EXPECT_EQ(ent2->getHP(), 1);
	delete ent1;
	delete ent2;
}

TEST(WaterAttackTest, WaterVsFireTest){
	Entity* ent1 = new Player("p", 500);
	Attack* wateratt = new WaterAttack();
	ent1->setAttack(wateratt);
	Entity* ent2 = new Gnome("gnome", 50);
	Attack* fireatt = new FireAttack();
	ent2->setAttack(fireatt);
	ent1->attack(ent2);
	EXPECT_EQ(ent2->getHP(), 20);
	delete ent1;
	delete ent2;

}

TEST(WaterAttackTest, WaterVsEarthTest){
        Entity* ent1  = new Player("p", 500);
        Attack* wateratt = new WaterAttack();
        ent1->setAttack(wateratt);
        Entity* ent2 = new Robot("robo", 50);
        Attack* earthatt = new EarthAttack();
        ent2->setAttack(earthatt);
        ent1->attack(ent2);
        EXPECT_EQ(ent2->getHP(), 35);
        delete ent1;
        delete ent2;
}

TEST(WaterAttackTest, WaterVsAirTest){
        Entity* ent1 = new Player("p", 500);
        Attack* wateratt = new WaterAttack();
        ent1->setAttack(wateratt);
        Entity* ent2 = new Troll("troll", 60);
        Attack* airatt = new AirAttack();
        ent2->setAttack(airatt);
        ent1->attack(ent2);
        EXPECT_EQ(ent2->getHP(), 40);
        delete ent1;
        delete ent2;
}

TEST(WaterAttackTest, WaterVsWaterTest){
        Entity* ent1 = new Player("p", 500);
        Attack* wateratt = new WaterAttack();
        ent1->setAttack(wateratt);
        Entity* ent2 = new Troll("troll", 60);
        Attack* wateratt2 = new WaterAttack();
        ent2->setAttack(wateratt2);
        ent1->attack(ent2);
        EXPECT_EQ(ent2->getHP(), 40);
        delete ent1;
        delete ent2;
}

TEST(WaterAttackTest, WaterVsSwordTest){
        Entity* ent1 = new Player("p", 500);
        Attack* wateratt = new WaterAttack();
        ent1->setAttack(wateratt);
        Entity* ent2 = new Troll("troll", 60);
        Attack* swordatt = new SwordAttack();
        ent2->setAttack(swordatt);
        ent1->attack(ent2);
        EXPECT_EQ(ent2->getHP(), 40);
        delete ent1;
        delete ent2;
}


TEST(FireAttackTest, FireVsSwordTest){
        Entity* ent1 = new Player("p", 500);
        Attack* fireatt = new FireAttack();
        ent1->setAttack(fireatt);
        Entity* ent2 = new Shroeder("professor", 60);
        Attack* swordatt = new SwordAttack();
        ent2->setAttack(swordatt);
        ent1->attack(ent2);
        EXPECT_EQ(ent2->getHP(), 40);
	ent2->attack(ent1);
	EXPECT_EQ(ent1->getHP(), 480);
        delete ent1;
        delete ent2;
}

TEST(FireAttackTest, FireVsFireTest){
        Entity* ent1 = new Player("p", 500);
        Attack* fireatt = new FireAttack();
        Attack* fireatt2 = new FireAttack();
        ent1->setAttack(fireatt);
        Entity* ent2 = new Shroeder("professor", 60);
        ent2->setAttack(fireatt2);
        ent1->attack(ent2);
        EXPECT_EQ(ent2->getHP(), 40);
        ent2->attack(ent1);
        EXPECT_EQ(ent1->getHP(), 480);
        delete ent1;
        delete ent2;
}

TEST(FireAttackTest, FireVsWaterTest){
        Entity* ent1 = new Player("p", 500);
        Attack* fireatt = new FireAttack();
        ent1->setAttack(fireatt);
        Entity* ent2 = new Shroeder("professor", 60);
	Attack* wateratt = new WaterAttack();
	ent2->setAttack(wateratt);
        ent1->attack(ent2);
        EXPECT_EQ(ent2->getHP(), 45);
        ent2->attack(ent1);
        EXPECT_EQ(ent1->getHP(), 470);
        delete ent1;
        delete ent2;
}

TEST(FireAttackTest, FireVsAirTest){
        Entity* ent1 = new Player("p", 500);
        Attack* fireatt = new FireAttack();
        ent1->setAttack(fireatt);
        Entity* ent2 = new Shroeder("professor", 60);
        Attack* airatt = new AirAttack();
        ent2->setAttack(airatt);
        ent1->attack(ent2);
        EXPECT_EQ(ent2->getHP(), 30);
        ent2->attack(ent1);
        EXPECT_EQ(ent1->getHP(), 485);
        delete ent1;
        delete ent2;

}

TEST(FireAttackTest, FireVsEarthTest){
        Entity* ent1 = new Player("p", 500);
        Attack* fireatt = new FireAttack();
        ent1->setAttack(fireatt);
        Entity* ent2 = new Dragon("puff", 60);
        Attack* earthatt = new EarthAttack();
        ent2->setAttack(earthatt);
        ent1->attack(ent2);
        EXPECT_EQ(ent2->getHP(), 40);
        ent2->attack(ent1);
        EXPECT_EQ(ent1->getHP(), 480);
        delete ent1;
        delete ent2;
}

TEST(AirAttackTest, AirVsSwordTest){
        Entity* ent1 = new Player("p", 500);
        Attack* airatt = new AirAttack();
        ent1->setAttack(airatt);
        Entity* ent2 = new Troll("troll", 1000);
        Attack* swordatt = new SwordAttack();
        ent2->setAttack(swordatt);
        ent1->attack(ent2);
        EXPECT_EQ(ent2->getHP(), 980);
        ent2->attack(ent1);
        EXPECT_EQ(ent1->getHP(), 480);
        delete ent1;
        delete ent2;
}

TEST(AirAttackTest, AirVsAirTest){
        Entity* ent1 = new Player("p", 300);
        Attack* airatt = new AirAttack();
        Attack* airatt2 = new AirAttack();
        ent1->setAttack(airatt);
        Entity* ent2 = new Robot("mark", 420);
        ent2->setAttack(airatt2);
        ent1->attack(ent2);
        EXPECT_EQ(ent2->getHP(), 400);
        ent2->attack(ent1);
        EXPECT_EQ(ent1->getHP(), 280);
        delete ent1;
        delete ent2;
}

TEST(AirAttackTest, AirVsWaterTest){
        Entity* ent1 = new Player("p", 500);
        Attack* airatt = new AirAttack();
        ent1->setAttack(airatt);
        Entity* ent2 = new Gnome("not an elf", 5000);
        Attack* wateratt = new WaterAttack();
        ent2->setAttack(wateratt);
        ent1->attack(ent2);
        EXPECT_EQ(ent2->getHP(), 4980);
        ent2->attack(ent1);
        EXPECT_EQ(ent1->getHP(), 480);
        delete ent1;
        delete ent2;
}

TEST(AirAttackTest, AirVsEarthTest){
        Entity* ent1 = new Player("p", 500);
        Attack* airatt = new AirAttack();
        ent1->setAttack(airatt);
        Entity* ent2 = new Troll("troll", 1000);
        Attack* earthatt = new EarthAttack();
        ent2->setAttack(earthatt);
        ent1->attack(ent2);
        EXPECT_EQ(ent2->getHP(), 970);
        ent2->attack(ent1);
        EXPECT_EQ(ent1->getHP(), 485);
        delete ent1;
        delete ent2;
}


TEST(AirAttackTest, AirVsFireTest){
        Entity* ent1 = new Player("p", 200);
        Attack* airatt = new AirAttack();
        ent1->setAttack(airatt);
        Entity* ent2 = new Jester("clown", 100);
        Attack* fireatt = new FireAttack();
        ent2->setAttack(fireatt);
        ent1->attack(ent2);
        EXPECT_EQ(ent2->getHP(), 85);
        ent2->attack(ent1);
        EXPECT_EQ(ent1->getHP(), 170);
	delete ent1;
	delete ent2;
}

TEST(EarthAttackTest, EarthVsSwordTest){
        Entity* ent1 = new Player("p", 500);
        Attack* earthatt = new EarthAttack();
        ent1->setAttack(earthatt);
        Entity* ent2 = new Robot("robot", 1000);
        Attack* swordatt = new SwordAttack();
        ent2->setAttack(swordatt);
        ent1->attack(ent2);
        EXPECT_EQ(ent2->getHP(), 980);
        ent2->attack(ent1);
        EXPECT_EQ(ent1->getHP(), 480);
	delete ent1;
	delete ent2;
}

TEST(EarthAttackTest, EarthVsAirTest){
        Entity* ent1 = new Player("p", 500);
        Attack* earthatt = new EarthAttack();
        ent1->setAttack(earthatt);
        Entity* ent2 = new Robot("robot", 1000);
        Attack* airatt = new AirAttack();
        ent2->setAttack(airatt);
        ent1->attack(ent2);
        EXPECT_EQ(ent2->getHP(), 985);
        ent2->attack(ent1);
        EXPECT_EQ(ent1->getHP(), 470);
	delete ent1;
	delete ent2;
}

TEST(EarthAttackTest, EarthVsWaterTest){
        Entity* ent1 = new Player("p", 500);
        Attack* earthatt = new EarthAttack();
        ent1->setAttack(earthatt);
        Entity* ent2 = new Robot("robot", 1000);
        Attack* wateratt = new WaterAttack();
        ent2->setAttack(wateratt);
        ent1->attack(ent2);
        EXPECT_EQ(ent2->getHP(), 970);
        ent2->attack(ent1);
        EXPECT_EQ(ent1->getHP(), 485);
	delete ent1;
	delete ent2;
}

TEST(EarthAttackTest, EarthVsEarthTest){
        Entity* ent1 = new Player("p", 500);
        Attack* earthatt = new EarthAttack();
        Attack* earthatt2 = new EarthAttack();
        ent1->setAttack(earthatt);
        Entity* ent2 = new Robot("robot", 1000);
        ent2->setAttack(earthatt2);
        ent1->attack(ent2);
        EXPECT_EQ(ent2->getHP(), 980);
        ent2->attack(ent1);
        EXPECT_EQ(ent1->getHP(), 480);
	delete ent1;
	delete ent2;
}

TEST(EarthAttackTest, EarthVsFireTest){
        Entity* ent1 = new Player("p", 500);
        Attack* earthatt = new EarthAttack();
        ent1->setAttack(earthatt);
        Entity* ent2 = new Robot("robot", 1000);
        Attack* fireatt = new FireAttack();
        ent2->setAttack(fireatt);
        ent1->attack(ent2);
        EXPECT_EQ(ent2->getHP(), 980);
        ent2->attack(ent1);
        EXPECT_EQ(ent1->getHP(), 480);
	delete ent1;
	delete ent2;
}

TEST(DifficultyStringTest, EasyDifficulty){
	GameState* test = new GameState(29, 120, 1);
	EXPECT_EQ(test->getDifficultyString(1), "Normal");
	delete test;
}

TEST(DifficultyStringTest, NormalDifficulty){
        GameState* test = new GameState(29, 120, 0);
        EXPECT_EQ(test->getDifficultyString(0), "Easy");
	delete test;
}

TEST(DifficultyStringTest, HardDifficulty){
        GameState* test = new GameState(29, 120, 2);
        EXPECT_EQ(test->getDifficultyString(2), "Hard");
	delete test;
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
