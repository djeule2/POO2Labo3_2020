/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo3 - Rivières
 Fichier     : Daughter.h
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 30.04.2020

 But         : Classe Daughter qui représente une fille

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#ifndef POO2LABO3_2020_DAUGHTER_H
#define POO2LABO3_2020_DAUGHTER_H

#include "Person.h"

class Daughter : public Person {
public:
    /**
     * Constructeur de Daughter
     * @param name
     */
    explicit Daughter(const string &name) : Person(name) {}
};

#endif //POO2LABO3_2020_DAUGHTER_H
