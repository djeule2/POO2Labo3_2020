/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo3 - Rivières
 Fichier     : Person.cpp
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 30.04.2020

 But         : Fichier d'implémentation de la clsse Person

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#include "Person.h"

Person::Person(const string &name, bool canDrive) : _name(name), _canDrive(canDrive) {}

Person::~Person() {}

bool Person::canDrive() const {
    return _canDrive;
}

string Person::getName() const {
    return _name;
}
