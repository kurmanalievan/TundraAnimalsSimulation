#ifndef TUNDRA_H
#define TUNDRA_H
#include <time.h>
#include <fstream>
#include <sstream>
#include "colony.h"
#include "animal.h"

class colony;
class animal;
class Predator;
class Prey;

class tundra
{
    private:
        std::ifstream _file;
    public:
        bool isExtinct(vector<Prey*> &_colonies);
        tundra(const string &fname);
        vector<Predator*> predators;
        vector<Prey*> preys;
        int getRandomIndex(int r);
        void start(tundra* &_tundra);
        void offspring(Predator* &_col, int m);
        void predatorsOffspring(colony* _col);

};

#endif // TUNDRA_H
