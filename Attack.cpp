#include "Attack.hpp"
using namespace std;


Attack::Attack(string name): atkName(name) {}

void SwordAttack::doAttack(Entity* attacker, Entity* target){
  cout<< attacker->getName()<< " slashes " << target->getName()<<endl;
  target->changeHP(-20);
  cout<<"   "<<target->getName()<<" HP: "<<target->getHP()<<endl;
}

SwordAttack::SwordAttack(): Attack("A sword") {}

string Attack::getAtkName() {
  return atkName;
}



WaterAttack::WaterAttack(): Attack("Water Element") {}
void WaterAttack::doAttack(Entity* attacker, Entity* target){
  cout<<endl<<attacker->getName()<< " splashes " << target->getName()<<endl;
    if(target->getAttack()->getAtkName() == "Fire Element"){
      target->changeHP(-30);
      cout<<"  Water extinguishes fire, its SUPER EFFECTIVE!"<<endl;
    }
    else if(target->getAttack()->getAtkName() == "Earth Element"){
      target->changeHP(-15);
      cout<<"  Earth absorbs water, its UNEFFECTIVE!!"<<endl;
    }
    else{
      target->changeHP(-20);
    }
    cout<<"   "<<target->getName()<<" HP: "<<target->getHP()<<endl;
}



FireAttack::FireAttack(): Attack("Fire Element") {}
void FireAttack::doAttack(Entity* attacker, Entity* target){
  cout<<endl<<attacker->getName()<< " burns " << target->getName()<<endl;
    if(target->getAttack()->getAtkName() == "Air Element"){
      target->changeHP(-30);
      cout<<"  Fire consumes air, its SUPER EFFECTIVE!"<<endl;
    }
    else if(target->getAttack()->getAtkName() == "Water Element"){
      target->changeHP(-15);
      cout<<"  Water extinguishes fire, its UNEFFECTIVE!!"<<endl;
    }
    else{
      target->changeHP(-20);
    }
    cout<<"   "<<target->getName()<<" HP: "<<target->getHP()<<endl;

}



EarthAttack::EarthAttack(): Attack("Earth Element") {}
void EarthAttack::doAttack(Entity* attacker, Entity* target){
  cout<<endl<<attacker->getName()<< " hurls a rock at " << target->getName()<<endl;
    if(target->getAttack()->getAtkName() == "Water Element"){
      target->changeHP(-30);
      cout<<"  Earth absorbes water, its SUPER EFFECTIVE!"<<endl;
    }
    else if(target->getAttack()->getAtkName() == "Air Element"){
      target->changeHP(-15);
      cout<<"  Air erodes earth, its UNEFFECTIVE!!"<<endl;
    }
    else{
      target->changeHP(-20);
    }
    cout<<"   "<<target->getName()<<" HP: "<<target->getHP()<<endl;
}

AirAttack::AirAttack(): Attack("Air Element") {}
void AirAttack::doAttack(Entity* attacker, Entity* target){
  cout<<endl<<attacker->getName()<< " blows wind at " << target->getName()<<endl;
    if(target->getAttack()->getAtkName() == "Earth Element"){
      target->changeHP(-30);
      cout<<"  Air erodes earth, its SUPER EFFECTIVE!"<<endl;
    }
    else if(target->getAttack()->getAtkName() == "Fire Element"){
      target->changeHP(-15);
      cout<<"  Fire consumes air, its UNEFFECTIVE!!"<<endl;
    }
    else{
      target->changeHP(-20);
    }
    cout<<"   "<<target->getName()<<" HP: "<<target->getHP()<<endl;
}

//water extinguishes fire, fire consumes air, air erodes earth, and earth absorbs water.