//
// Created by claudealves on 27.04.20.
//

#ifndef POO2LABO3_2020_FATHER_H
#define POO2LABO3_2020_FATHER_H
#include "Person.h"

class Father : public Person {
public:
    explicit Father(const string& name) : Person(name, true){}
};
#endif //POO2LABO3_2020_FATHER_H
