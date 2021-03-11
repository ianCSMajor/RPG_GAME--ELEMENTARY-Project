#ifndef ATTACK_HPP
#define ATTACK_HPP
#include "Entity.hpp"
using namespace std;


class Entity; 

class Attack
{
  public:
    Attack(string n);
    string atkName;
    string getAtkName();
    virtual void doAttack(Entity* attacker, Entity* target) = 0;
    virtual ~Attack() {}
    //virtual void getAtkName() = 0;
};


class SwordAttack : public Attack
{
  private:
    string atkName= "A Sword";

  public:
    //string atkName= "A Sword";
    SwordAttack();
    virtual void doAttack(Entity* attacker, Entity* target);
    virtual ~SwordAttack() {}
};


class WaterAttack : public Attack
{
 private:
  string atkName= "Water Element";
 public:
    //string atkName= "Water Element";
    WaterAttack();
    virtual void doAttack(Entity* attacker, Entity* target);
    virtual ~WaterAttack() {}
};

class FireAttack : public Attack
{
  private:
    string atkName= "Fire Element";
  public:
    // string atkName= "Fire Element";
    FireAttack();
    virtual void doAttack(Entity* attacker, Entity* target);
    virtual ~FireAttack() {}

};

class EarthAttack : public Attack
{
  private:
    string atkName= "Earth Element";
  public:
    // string atkName= "Earth Element";
    EarthAttack();
    virtual void doAttack(Entity* attacker, Entity* target);
    virtual ~EarthAttack() {}
};

class AirAttack : public Attack
{
  private:
    string atkName= "Air Element";
  public:
    // string atkName= "Air Element";
    AirAttack();
    virtual void doAttack(Entity* attacker, Entity* target);
    virtual ~AirAttack() {}
};

#endif