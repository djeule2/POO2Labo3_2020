/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo3 - Rivières
 Fichier     : Son.h
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 30.04.2020

 But         : Classe Son qui représente un fils

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#ifndef POO2LABO3_2020_SON_H
#define POO2LABO3_2020_SON_H

#include "Person.h"

class Son : public Person {
public:
    /**
     * Constructeur de Son
     * @param name
     */
    explicit Son(const string &name) : Person(name) {}
};

#endif //POO2LABO3_2020_SON_H
