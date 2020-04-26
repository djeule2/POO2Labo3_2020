//
// Created by Lenovo T50s on 17.04.2020.
//

#ifndef POO2LABO3_2020_CONTAINER_H
#define POO2LABO3_2020_CONTAINER_H
#include <list>
#include <string>
#include "Person.h"
using namespace std;

class Person;

class Container {
public:
    Container(const string& name);
    virtual ~ Container();

    /**
     * Returns the name of the container
     * @return
     */
    string  getName() const ;

    /**
     * Add a person to the container
     * @param person
     */
   virtual void addPerson(Person* person);

    /**
     *
     * @param nom
     * @return
     */

    Person* removePerson(const string & nom);

    /**
     * Get the number of people in the container
     * @return
     */
    int getNbrePersonne()const;

    /**
     * determines if a container is empty
     * @return
     */
    bool isEmpty()const ;

    /**
     * Search for a person in the list of people
     * @param person
     * @return
     */
    bool contains(const Person* person) const ;

    /**
     *
     * @param name
     * @return
     */
    Person* getPersonne (const string& name) const ;

    /**
     *
     * @param os
     * @param container
     * @return
     */
    friend ostream& operator <<(ostream& os, const Container& container) ;



private:
    string _mame;
    list<Person*> _person;
};


#endif //POO2LABO3_2020_CONTAINER_H
