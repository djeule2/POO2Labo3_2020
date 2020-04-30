/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo3 - Rivières
 Fichier     : Bank.cpp
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 30.04.2020

 But         : Fichier d'implémentation de la classe Bank

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
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

