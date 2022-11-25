#include "colony.h"

using namespace std;


colonyLemming* colonyLemming::_instance = nullptr;
colonyLemming* colonyLemming::instance()
{
    if (_instance == nullptr)
    {
        _instance = new colonyLemming();
    }else
    {
        return _instance;
    }
}

void colonyLemming::attack(Predator *_pred, Prey *_lem)
{
      int res = _pred->getAnimalNum() * 4;
      int rep = _lem->getAnimalNum() - res;
      _lem->setAnimalNum(rep);
      if(rep < 0)
      {
          int perish = _pred->getAnimalNum() - (abs(rep) / 4);
          _pred->setAnimalNum(perish);
          cout << "Some number of predators was perished!\n" << endl;

      }
      if(_lem->getAnimalNum() > 200)
      {
           cout << "!colony decreased, since it was over 200!\n";
          _lem->setAnimalNum(30);
      }
}
 void colonyLemming::preyPopulIncreasing(Prey *_col, int turn)
 {
     if(turn == 2){
     int l = _col->getAnimalNum() * 4;
    _col->setAnimalNum(l);
     }
     if(_col->getAnimalNum() > 200)
     {
         _col->setAnimalNum(30);
         cout << "Population of lemming was decreased!\n";
     }
     if (_col->getAnimalNum() < 0)
     {
         _col->setAnimalNum(0);
     }
 }

void colonyLemming::templateMethod(Predator *pr, Prey *p, int turn)
{
    cout << "********************** Predators attacked lemmings ****************************\n" ;
    cout << "                       Initial conditions                                     \n";
    printCondition(pr, p);
    attack(pr, p);
    preyPopulIncreasing(p, turn);
    cout << "                        After attack                                            \n";
    printCondition(pr, p);

}



colonyHare* colonyHare::_instance = nullptr;
colonyHare* colonyHare::instance()
{
    if (_instance == nullptr)
    {
        _instance = new colonyHare();
    }else
    {
        return _instance;
    }
}
void colonyHare::attack(Predator *_pred, Prey *_lem)
{
      int res = _pred->getAnimalNum() * 2;
      int rep = _lem->getAnimalNum() - res;
      _lem->setAnimalNum(rep);
      if(rep < 0)
      {
          int perish = _pred->getAnimalNum() - (abs(rep) / 4);
          _pred->setAnimalNum(perish);
          cout << "Some number of predators was perished!\n" << endl;
      }
      if(_lem->getAnimalNum() > 100)
      {
           cout << "!colony decreased, since it was over 200!\n";
          _lem->setAnimalNum(20);
      }

}
void colonyHare::preyPopulIncreasing(Prey *_col, int turn)
{
    if (turn == 2){
     int l = _col->getAnimalNum() * 2;
    _col->setAnimalNum(l);
    }
    if(_col->getAnimalNum() > 100)
     {

         _col->setAnimalNum(20);
         cout << "Population of hare was decreased!\n";
     }
     if (_col->getAnimalNum() < 0)
     {
         _col->setAnimalNum(0);
     }
}
void colonyHare::templateMethod(Predator *pr, Prey *p, int turn)
{
    cout << "********************** Predators attacked Hare ****************************\n" ;
    cout << "                       Initial conditions                                     \n";
    printCondition(pr, p);
    attack(pr, p);
    preyPopulIncreasing(p, turn);
    cout << "                        After attack                                            \n";
    printCondition(pr, p);

}


colonyGopher* colonyGopher::_instance = nullptr;
colonyGopher* colonyGopher::instance()
{
    if (_instance == nullptr)
    {
        _instance = new colonyGopher();
    }else
    {
        return _instance;
    }
}


void colonyGopher::attack(Predator *_pred, Prey *_lem)
{
      int res = _pred->getAnimalNum() * 2;
      int rep = _lem->getAnimalNum() - res;
      _lem->setAnimalNum(rep);
      if(rep < 0)
      {
          int perish = _pred->getAnimalNum() - (abs(rep) / 4);
          _pred->setAnimalNum(perish);
          cout << "Some number of predators was perished!\n" << endl;

      }
      if(_lem->getAnimalNum() > 200)
      {
           cout << "!colony decreased, since it was over 200!\n";
          _lem->setAnimalNum(40);
      }
}
void colonyGopher::preyPopulIncreasing(Prey *_col, int turn)
{
    if (turn == 4){
     int l = _col->getAnimalNum() * 4;
    _col->setAnimalNum(l);
    }
    if(_col->getAnimalNum() > 200)
     {
         _col->setAnimalNum(4);
         cout << "Population of gopher was decreased!\n";
     }
     if (_col->getAnimalNum() < 0)
     {
         _col->setAnimalNum(0);
     }
}

void colonyGopher::templateMethod(Predator *pr, Prey *p, int turn)
{
    cout << "********************** Predators attacked Gopher ****************************\n" ;
    cout << "                       Initial conditions                                     \n";
    printCondition(pr, p);
    attack(pr, p);
    preyPopulIncreasing(p, turn);
    cout << "                        After attack                                            \n";
    printCondition(pr, p);

}



