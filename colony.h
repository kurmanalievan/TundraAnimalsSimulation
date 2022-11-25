#ifndef COLONY_H
#define COLONY_H
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "animal.h"
using namespace std;

class Lemming;
class Hare;
class Gopher;
class Owl;
class Fox;
class Wolf;
class animal;
class Prey;
class Predator;

class colony   //abstract class
{
    public:
         virtual void attack(Predator *a,Prey *p) = 0;
         virtual void preyPopulIncreasing(Prey *p, int turn) = 0;
         void printCondition(Predator *pr, Prey *p)
         {
             cout << pr->getAnimalColName() << " " << pr->getAnimalName() << " " << pr->getAnimalNum() << endl;
             cout << p->getAnimalColName() << " " << p->getAnimalName() << " " << p->getAnimalNum() << endl;
         };
         virtual void templateMethod(Predator *pr, Prey *p, int turn) {}
         virtual ~colony() {}
};

class colonyLemming : public colony
{
   public:
   static colonyLemming* _instance;
   static colonyLemming* instance();
   void attack(Predator *_pred, Prey *_lem) override;
   void  preyPopulIncreasing(Prey *p, int turn) override;
   void templateMethod(Predator *pr, Prey *p, int turn) override;
   protected:
    colonyLemming() {}


};

class colonyHare : public colony
{
    public:
    static colonyHare* _instance;
    static colonyHare* instance();
    void attack(Predator *a, Prey *p) override;
    void preyPopulIncreasing(Prey *p, int turn) override;
    void templateMethod(Predator *pr, Prey *p, int turn) override;
     protected:
     colonyHare() {}
};

class colonyGopher: public colony
{
    public:
    static colonyGopher* _instance;
    static colonyGopher* instance();
    void attack(Predator *a,Prey *p) override;
    void preyPopulIncreasing(Prey *p, int turn) override;
    void templateMethod(Predator *pr, Prey *p, int turn) override;
     protected:
     colonyGopher() {}
};



#endif // COLONY_H
