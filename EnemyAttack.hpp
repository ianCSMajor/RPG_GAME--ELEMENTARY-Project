
#ifndef ENEMYATTACK_HPP
#define ENEMYATTACK_HPP


void enemyAttack(Entity* attacker, Entity* target, int lvl){

  cout<< attacker->getName()<< " attacks " << target->getName()<<endl;
  target->changeHP(-20);
  cout<<"   "<<target->getName()<<" HP: "<<target->getHP()<<endl;








  //fire-air
  //fire-water


  //air-earth
  //air-fire


  //earth-water
  //earth-air


  
}


#endif


//water extinguishes fire, fire consumes air, air erodes earth, and earth absorbs water.