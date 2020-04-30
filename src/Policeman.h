/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo3 - Rivières
 Fichier     : Policeman.h
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 30.04.2020

 But         : Classe Policeman qui représente un policier

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#ifndef POO2LABO3_2020_POLICEMAN_H
#define POO2LABO3_2020_POLICEMAN_H

#include "Person.h"

class Policeman : public Person {
public:
    /**
     * Constructeur de Policeman
     * @param name
     */
    explicit Policeman(const string &name) : Person(name, true) {}
};

#endif //POO2LABO3_2020_POLICEMAN_H
