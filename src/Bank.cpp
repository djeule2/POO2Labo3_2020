//
// Created by Lenovo T50s on 17.04.2020.
//

#include <iomanip>
#include "Bank.h"
using namespace std;

Bank::Bank(const string& name): Container(name){}

ostream& operator << (ostream& os, const Bank& bank) {
    os << setfill('-') << setw(bank.SIZE_BANK) << "\n"
        <<bank.getName()<<" : "<< (Container)bank<<"\n"
        << setfill('-')<< setw(bank.SIZE_BANK)<< "\n";

    return os;
}

void Bank::addPersons(list< Person*> listPerson){
    for (Person* person: listPerson){
        addPerson(person);
    }

}

