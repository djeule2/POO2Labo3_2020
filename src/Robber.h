/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo3 - Rivières
 Fichier     : Robber.h
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 30.04.2020

 But         : Classe Robber qui représente un voleur

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#ifndef POO2LABO3_2020_ROBBER_H
#define POO2LABO3_2020_ROBBER_H

#include "Person.h"

class Robber : public Person {
public:
    /**
     * Constructeur de Robber
     * @param name
     */
    explicit Robber(const string &name) : Person(name) {}
};

#endif //POO2LABO3_2020_ROBBER_H
