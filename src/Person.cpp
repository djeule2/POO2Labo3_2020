//
// Created by Lenovo T50s on 17.04.2020.
//

#include "Person.h"

Person::Person(const string &name, bool canDrive) : _name(name), _canDrive(canDrive) {


}

Person::~Person() {}


bool Person::canDrive() const {
    return _canDrive;

}

string Person::getName() const {
    return _name;

}
