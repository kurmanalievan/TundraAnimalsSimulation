#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>

using namespace std;


class animal
{
    protected:
        string _nameOfCol;
        string _nameOfAnimal;
        int _numOfanimal;
    public:
        animal(const string c_n, const string n, int num) : _nameOfCol(c_n), _nameOfAnimal(n), _numOfanimal(num) {};
        string getAnimalName() { return _nameOfAnimal; }
        string getAnimalColName() { return _nameOfCol; }
        void setAnimalName(const string n_name) { _nameOfAnimal = n_name; }
        void setAnimalNum (int _a) { _numOfanimal = _a; }
        int getAnimalNum() { return _numOfanimal; }
        virtual bool isPredator() const { return false; }

};


class Prey : public animal
{
   public:
   //  void attackedByPredator(colony* &_pred,colony* &_hare);
     Prey(const string c_n, const string n, int num) : animal(c_n,n,num) {}

};

class Predator : public animal
{
   public:
      bool isPredator() const override { return true; }
  // protected:
      Predator(const string c_n, const string n, int num) : animal(c_n,n,num) {}
};

class Lemming : public Prey
{
 public:
    //static Lemming* instance();
    //void colony
 private:
     Lemming() : Prey ("", "l", 0) {}
   // static Lemming* _instance;
};

class Hare : public Prey
{
 public:
   // static Hare* instance();
 private:
     Hare() : Prey ("", "h", 0) {}
   // static Hare* _instance;
};

class Gopher : public Prey
{
 public:
   // static Gopher* instance();
 private:
    Gopher() : Prey("","g", 0) {}
    //static Gopher* _instance;
};

class Owl : public Predator
{
 public:
  //  static Owl* instance();
 private:
     Owl() : Predator("","o", 0) {}
   // static Owl* _instance;
};

class Fox : public Predator
{
 public:
    //static Fox* instance();
 private:
    Fox() : Predator("","f", 0) {}
    //static Fox* _instance;
};

class Wolf : public Predator
{
 public:
   // static Wolf* instance();
 private:
     Wolf(): Predator("","w", 0) {}
   // static Wolf* _instance;
};
#endif // ANIMAL_H
