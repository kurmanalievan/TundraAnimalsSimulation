#include "tundra.h"

static int a, b, init_l, init_g, init_h;
//Prey* pr;
tundra::tundra(const string &fname)
{
    _file.open(fname.c_str());
    if(_file.fail()) {
        cout << "Can not open the file!\n";
        exit(0);
    }
    _file >> a >> b;
    for (int i = 0; i < a; i++) {
        string c_name;
        string a_name;
        int a_num;
        _file >> c_name >> a_name >> a_num;
        preys.push_back(new Prey(c_name, a_name, a_num));


    }
   int k = 0;
    for (int i = 0; i < (a+b); i++) {
        if (i > a-1) {
            string c_name;
            string a_name;
            int a_num;
            _file >> c_name >> a_name >> a_num;
           predators.push_back(new Predator(c_name, a_name, a_num));
          // cout << predators[k]->getAnimalName() <<  endl;
            k++;
        }
    }

}

bool tundra::isExtinct(vector<Prey*> &_colonies)
{
       for (Prey* i: _colonies)
       {
               if (i->getAnimalNum() > 0 )
               {
                   return false;
               }
       }
       return true;
}

int tundra::getRandomIndex(int r)
{
    return rand()%r;
}

void tundra::offspring(Predator* &_col, int m)
{

    int o = _col->getAnimalNum() / 4;
    o *= m;
    _col->setAnimalNum(o);
    cout << "OFFSPRING!\n";

}
void tundra::start(tundra* &_tundra)
{
             int k = 0;
             colonyLemming* l = colonyLemming::instance();
             colonyGopher* g = colonyGopher::instance();
             colonyHare* h = colonyHare::instance();
             int l_turn = 1, g_turn = 1, h_turn = 1, o_turn = 1, f_turn = 1, w_turn = 1;
    while (!isExtinct(preys))
    {
         int rand_ind = getRandomIndex(a);
        // cout << "random " << rand_ind << endl;
         if(preys[rand_ind]->getAnimalName() == "l")
         {
            l->templateMethod(predators[k], preys[rand_ind], l_turn);
            if(l_turn == 2) { l_turn = 0;}
            l_turn++;


         }else if (preys[rand_ind]->getAnimalName() == "g")
         {
             g->templateMethod(predators[k], preys[rand_ind], g_turn);
             if(g_turn == 2) { g_turn = 0;}
             g_turn++;

         }else if (preys[rand_ind]->getAnimalName() == "h")
         {
             h->templateMethod(predators[k], preys[rand_ind], h_turn);
             if(h_turn == 2) { h_turn = 0;}
             h_turn++;
         }

            if(o_turn == 3) { offspring(predators[k], 1); o_turn = 0; }
            else if(f_turn == 8) { offspring(predators[k], 3); f_turn = 0;}
            else if(w_turn == 8) { offspring(predators[k], 2); w_turn = 0;}

         if (predators[k]->getAnimalName() == "o") { o_turn++; }
         else if (predators[k]->getAnimalName() == "f") { f_turn++; }
         else if  (predators[k]->getAnimalName() == "w") { w_turn++; }
         k++;
         if (k >= b)
         {
             k = 0;
         }

    }
    cout << "-------------------Prey colonies became extinct------------------------\n";
    for(Prey* i: preys)
    {
        cout << i->getAnimalColName() << " " << i->getAnimalName() << " " << i->getAnimalNum() << endl;
    }
}




