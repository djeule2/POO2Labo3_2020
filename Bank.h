//
// Created by Lenovo T50s on 17.04.2020.
//

#ifndef POO2LABO3_2020_BANK_H
#define POO2LABO3_2020_BANK_H


#include "Container.h"
using namespace std;

class Bank : public Container{
public:
    Bank(const string& name);
    friend ostream& operator <<(ostream& os, const Bank& bank);
    void addPersons(list< Person*> person1);

private:
    const int SIZE_BANK =60;



};


#endif //POO2LABO3_2020_BANK_H
