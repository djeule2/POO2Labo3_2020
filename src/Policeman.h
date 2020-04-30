//
// Created by claudealves on 27.04.20.
//

#ifndef POO2LABO3_2020_POLICEMAN_H
#define POO2LABO3_2020_POLICEMAN_H
#include "Person.h"

class Policeman : public Person {
public:
    explicit Policeman(const string& name) : Person(name, true){}
};
#endif //POO2LABO3_2020_POLICEMAN_H
