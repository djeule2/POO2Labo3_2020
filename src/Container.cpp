//
// Created by Lenovo T50s on 17.04.2020.
//

#include "Container.h"

using namespace std;

Container::Container(const string &name) : _mame(name) {
}

Container::~Container() {
}

string Container::getName() const {
    return _mame;
}

void Container::addPerson(Person *person) {
    _person.push_back(person);
}

Person *Container::removePerson(Person *person) {
    _person.remove(person);
}

int Container::getNumberOfPersons() const {
    return _person.size();
}

bool Container::isEmpty() const {
    return _person.empty();
}

bool Container::contains(const Person *person) const {
    for (Person *person1: _person)
        if (person1 == person)
            return true;
    return false;
}

Person *Container::getPerson(const string &name) const {
    for (Person *person : _person) {
        cout << person->getName() << endl;
        if (person->getName() == name) {
            return person;
        }
    }
    return nullptr;
}


ostream &operator<<(ostream &os, const Container &container) {
    string result;
    for (Person *person: container._person)
        result += person->getName() + " ";
    return os << result;
}

list<Person *> Container::getPersons() {
    return _person;
}

bool Container::isFull() {
    return false;
}

void Container::emtpy() {
    _person.clear();
}
