#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <iostream>
#include <string>
#include "Attack.hpp"
//#include "Attack.cpp"
using namespace std;

class Attack; //forward decleration
// class WaterAttack;

class Entity          
{              
  protected:        
    Attack* _atkType;     
  public:
    //Attack* _atkType;

    //Constructor         
    Entity(): _atkType(nullptr) {};

    //Destructor
    virtual ~Entity();// delete _atkType; }
    //getters
    virtual int getHP() = 0;
    virtual string getName() = 0;
    //virtual void entityInfo() = 0;
    //setter
    virtual void changeHP(int hp) = 0;
          

    // virtual void setAttack(Attack *atk) = 0;
    // virtual void attack(Entity *_target) = 0;
    void setAttack(Attack* atk);
    Attack* getAttack();
    void attack(Entity *_target);

    virtual void ascii() = 0;
    virtual void entityInfo() = 0;
  
};



class Player: public Entity
{
  private:
    string name;
    int hp;

  public:
    Player(string name, int hp) : name(name), hp(hp) {}
    virtual ~Player() {}
    virtual void changeHP(int deltaHP) override {this->hp += deltaHP;} 
    virtual int getHP()override {return this->hp;} 
    virtual  string getName() override { return this->name;}
    virtual void ascii() override;
    virtual void entityInfo() override;



};

class Gnome: public Entity
{
  private:
    string name;
    int hp;

  public:
    Gnome(string name, int hp) : name(name), hp(hp){}
    virtual ~Gnome(){}
    virtual void changeHP(int deltaHP) override {this->hp += deltaHP;}
    virtual int getHP() override {return this->hp;}
    virtual string getName() override { return this->name;}
    virtual void ascii() override;
    virtual void entityInfo() override;

};



class Dragon: public Entity
{
  private:
    string name;
    int hp;
         
  public:
    Dragon(string name, int hp) : name(name), hp(hp){}
    virtual ~Dragon(){}
    virtual void changeHP(int deltaHP) override {this->hp += deltaHP;}      
    virtual int getHP() override {return this->hp;}
    virtual string getName() override { return this->name;}
    virtual void ascii() override;
    virtual void entityInfo() override;
      
};

class Troll: public Entity
{
  private:
    string name;
    int hp;
          
  public:
    Troll(string name, int hp) : name(name), hp(hp){}
    virtual ~Troll(){}
    virtual void changeHP(int deltaHP) override {this->hp += deltaHP;}  
    virtual int getHP() override {return this->hp;}
    virtual string getName() override { return this->name;}
    virtual void ascii() override;
    virtual void entityInfo() override;
          
};



class Robot: public Entity
{
  private:
    string name;
    int hp;
          
  public:
    Robot(string name, int hp) : name(name), hp(hp){}
    virtual ~Robot(){}
    virtual void changeHP(int deltaHP) override {this->hp += deltaHP;}
    virtual int getHP() override {return this->hp;}
    virtual string getName() override { return this->name;}
    virtual void ascii() override;
    virtual void entityInfo() override;
};

class Jester: public Entity
{
  private:
    string name;
    int hp;
          
  public:
    Jester(string name, int hp) : name(name), hp(hp){}
    virtual ~Jester(){}
    virtual void changeHP(int deltaHP) override {this->hp += deltaHP;}
    virtual int getHP() override {return this->hp;}
    virtual string getName() override { return this->name;}
    virtual void ascii() override;
    virtual void entityInfo() override;
};

class Shroeder: public Entity
{
 private:
   string name;
   int hp;
          
 public:
   Shroeder(string name, int hp) : name(name), hp(hp){}
   virtual ~Shroeder(){}
   virtual void changeHP(int deltaHP) override {this->hp += deltaHP;}
   virtual int getHP() override {return this->hp;}
   virtual string getName() override { return this->name;}
   virtual void ascii() override;
       virtual void entityInfo() override;
};

#endif
