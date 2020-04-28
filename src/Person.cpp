//
// Created by Lenovo T50s on 17.04.2020.
//

#include "Person.h"
Person::Person(const string& name, bool canDrive): _name(name), _canDrive(canDrive){


}
Person::~Person(){}


 bool Person::canDrive() {
     return _canDrive;

}


 //bool Person::move (Container* from, Container*to)const {}


// bool Person::canLeaveContainer(Container* c)const {}

 //bool Person::canJoinContainer(Container* c) const {}

string Person::getName()const {
    return _name;

}
