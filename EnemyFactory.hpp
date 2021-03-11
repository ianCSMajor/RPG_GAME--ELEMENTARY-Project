#ifndef ENEMYFACTORY_HPP
#define ENEMYFACTORY_HPP
#include "Entity.hpp"

class EnemyFactory
{
  public:
    Entity* createEnemy(int lvl){
      Entity* mob = nullptr;
      switch(lvl){
        case 1:{
          mob = new Gnome("Wild Gnome", 50);
          // WaterAttack splash;
          // mob->setAttack(&splash);
          Attack* splash= new WaterAttack;
          mob->setAttack(splash);
          cout << "A " << mob->getName()<< " appears! "<<endl;
          cout<<"   "<<mob->getName()<<" makes a big splash with the "<<splash->atkName<<endl;
          break;
        }
        case 2:{
          mob = new Dragon("Real Dragon", 50);
          Attack* cliche= new FireAttack;
          mob->setAttack(cliche);
          cout << "A " << mob->getName()<< " appears! "<<endl;
          cout<<"   "<<mob->getName()<<" is burning land with the "<<cliche->atkName<<endl;
          break;
        }
        case 3:{
          mob = new Troll("Bigass Troll", 50);
          Attack* rock = new EarthAttack;
          mob->setAttack(rock);
          cout << "A " << mob->getName()<< " appears! "<<endl;
          cout<<"   "<<mob->getName()<<" is using the "<<rock->atkName<<endl;
          break;
        }
        case 4:{
          mob = new Robot("Rogue Automaton", 50);
          Attack* blow= new AirAttack;
          mob->setAttack(blow);
          cout << "A " << mob->getName()<< " appears! "<<endl;
          cout<<"   "<<mob->getName()<<" is using the "<<blow->atkName<<endl;
          break;
        }
        case 5:{
          mob = new Jester("Cosmic Jester", 50);
          // AirAttack wind;
          // mob->setAttack(&wind);
          Attack* wind= new AirAttack;
          mob->setAttack(wind);
          cout << "A " << mob->getName()<< " appears! "<<endl;
          cout<<"   "<<mob->getName()<<" is using the "<<wind->atkName<<endl;
          break;
        }
        case 6:{
     

          break;
        }
        default:{
          cout<<"invalid level"<<endl;
          return NULL;
        }
      }
    
    
    cout<<"   "<<mob->getName()<<"'s HP: "<<mob->getHP()<<endl<<endl;
    mob->ascii();
    
    return mob;
    }
    virtual ~EnemyFactory(){
    }

};

//enemies: 1 Wild Gnome, 2 Wild Troll, 3 Real Dragon, 4 Bigass Robot, 5 Cosmic Jester, 6 Shroeder



// class EnemyFactory
// {
//   public:
//     Enemy createEnemy(int lvl){
//       Enemy mob("bad guy", 20);
//       switch(lvl){
//         case 1:{
//           mob = Enemy("Wild Gnome", 20);
//           WaterAttack splash;
//           mob.setAttack(&splash);
   
//           break;
//         }
//         case 2:{
//           mob =  Enemy("Blue Troll", 20);
//           break;
//         }
//         case 3:{
//           mob =  Enemy("Wild Troll", 20);
//           break;
//         }
//         case 4:{
//           mob =  Enemy("Wild Robot", 20);

//           break;
//         }
//         case 5:{
//           mob =  Enemy("Bigass Dragon", 20);
//           break;
//         }
//         case 6:{
//           mob =  Enemy("Yorgos the Greek God", 20);
//           break;
//         }
//         default:{
//           cout<<"invalid level"<<endl;
//           //return NULL;
//         }
//       }
//     cout << "A " << mob.getName()<< " appears! "<<endl;
//     cout<<"   "<<mob.getName()<<"'s HP: "<<mob.getHP()<<endl;
  
    
//     return mob;
//     }

// };



#endif