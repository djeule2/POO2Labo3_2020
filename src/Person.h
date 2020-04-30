//
// Created by Lenovo T50s on 17.04.2020.
//

#ifndef POO2LABO3_2020_PERSON_H
#define POO2LABO3_2020_PERSON_H

#include <string>
#include <iostream>

using namespace std;

class Person {
public:
    explicit Person(const string& name, bool canDrive = false);
    ~Person();

    /**
    * specify if a person is able to drive
    * @param c
    * @return true is the Person is able to drive, false otherwise
    */
    bool canDrive() const;
    string getName()const ;

private:
    string  _name;
    bool _canDrive;

};


#endif //POO2LABO3_2020_PERSON_H
