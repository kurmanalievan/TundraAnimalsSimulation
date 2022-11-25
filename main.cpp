#include <iostream>
#include "tundra.h"
#include "colony.h"

using namespace std;

#define NORMAL_MODE
#ifdef NORMAL_MODE
int main()
{

    tundra* t = new tundra("input.txt");
    t->start(t);
    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "tundra.h"

TEST_CASE("1", "input.txt")
{

    tundra* t = new tundra("input1.txt");
    CHECK(t->preys.size() == 0);
    CHECK(t->predators.size() == 0);
    tundra* t1 = new tundra("input.txt");
    //CHECK(t1->preys.size() == 3);
    //CHECK(t1->preys.size() == 3);
    CHECK_FALSE(t1->preys.size() == 0);
    CHECK_FALSE(t1->preys.size() == 0);

}

TEST_CASE("2", "input2*.txt")
{
    tundra* t = new tundra("input.txt");
    colonyLemming* l = colonyLemming::instance();
    l->attack(t->predators[0], t->preys[0]);
    CHECK_FALSE(t->predators[0]->getAnimalNum() == 0);
    CHECK_FALSE(t->preys[0]->getAnimalNum() == 0);
    CHECK_FALSE(t->isExtinct(t->preys));

}


TEST_CASE("3", "input.txt")
{
    tundra* t = new tundra("input.txt");
    colonyLemming* l = colonyLemming::instance();
    l->attack(t->predators[0], t->preys[0]);
    CHECK_FALSE(t->predators[0]->getAnimalNum() == 0);
    CHECK(t->predators[0]->getAnimalNum() == 10);
    CHECK_FALSE(t->preys[0]->getAnimalNum() == 0);
    CHECK_FALSE(t->preys[1]->getAnimalNum() == 30);
    CHECK_FALSE(t->isExtinct(t->preys));

}
TEST_CASE("4", "input3.txt")
{
    tundra* t = new tundra("input3.txt");
    colonyLemming* l = colonyLemming::instance();
    colonyLemming* h = colonyLemming::instance();
    l->attack(t->predators[0], t->preys[0]);
    h->attack(t->predators[1], t->preys[2]);
    CHECK_FALSE(t->predators[0]->getAnimalNum() == 10);
    CHECK_FALSE(t->predators[0]->getAnimalNum() == 40);
    CHECK_FALSE(t->preys[0]->getAnimalNum() == 210);
    CHECK_FALSE(t->preys[0]->getAnimalNum() == 30);
    CHECK_FALSE(t->predators[1]->getAnimalNum() == 20);
    CHECK_FALSE(t->preys[2]->getAnimalNum() == 2);
    CHECK_FALSE(t->preys[2]->getAnimalNum() == 90);


}



#endif


