/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo3 - Rivières
 Fichier     : Container.cpp
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 30.04.2020

 But         : Fichier d'implémentation de la classe Container

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#include "Container.h"

using namespace std;

Container::Container(const string &name) : _mame(name) {
}

Container::~Container() {
    _person.clear();
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
