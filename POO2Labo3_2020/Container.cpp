//
// Created by Lenovo T50s on 17.04.2020.
//

#include "Container.h"

using namespace std;
Container::Container(const string& name): _mame(name){
}

Container::~Container() {
}
string  Container::getName() const {
    return _mame;
}
 void Container::addPerson(Person* person){
   _person.push_back(person);
}
Person* Container::removePerson(const string& nom){
    Person* temp = getPersonne(nom);
    if(temp){
        _person.remove(temp);
        return temp;
    }
    throw string("personne absent");
}
int Container::getNbrePersonne()const {
    return _person.size();
}
bool Container::isEmpty()const {
    return _person.empty();
}

bool Container::contains(const Person* person) const {
    for(Person* person1: _person)
        if(person1==person)
            return true;
    return false;
}

 Person* Container::getPersonne (const string& name)const {
     cout<<name<<"okkkk"<<endl;

    for (Person* person : _person ) {
        cout<<person->getName()<<endl;
        cout<<name<<"okkkk"<<endl;
        if (person->getName()==name) {
            return person;
        }
    }
    return nullptr;
}


ostream& operator <<(ostream& os, const Container& container){
    string resultat = "";
    for (Person* person: container._person)
        resultat += person->getName() +" ";
    return os << resultat;
}
