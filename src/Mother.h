//
// Created by claudealves on 27.04.20.
//

#ifndef POO2LABO3_2020_MOTHER_H
#define POO2LABO3_2020_MOTHER_H
#include "Person.h"

class Mother : public Person {
public:
    Mother(const string& name) : Person(name, true){}
};
#endif //POO2LABO3_2020_MOTHER_H
