//
// Created by Lenovo T50s on 17.04.2020.
//

#include "Boat.h"

Boat::Boat(const string& name,  Bank* bank) : Container(name), _currentBank(bank){

}
 Boat::~Boat(){}

 ostream& operator<< (ostream& os, const Boat& boat){
    os << boat.getName() << " : < "<<(Container) boat<< ">\n";
    return os;
}

void Boat::setBank(Bank* bank){
    _currentBank=bank;
}

Bank* Boat::getBank() const {
    return _currentBank;
}
void Boat::addPersons(Person* person){
    if(getNbrePersonne() < _MAX_PASSAGER){
        this->addPerson(person);
    } else{
        cout <<"bateau plein";
    }
}