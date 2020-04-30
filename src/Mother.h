/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo3 - Rivières
 Fichier     : Mother.h
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 30.04.2020

 But         : Classe Mother qui représente une mère

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#ifndef POO2LABO3_2020_MOTHER_H
#define POO2LABO3_2020_MOTHER_H

#include "Person.h"

class Mother : public Person {
public:
    /**
     * Constructeur de Mother
     * @param name
     */
    explicit Mother(const string &name) : Person(name, true) {}
};

#endif //POO2LABO3_2020_MOTHER_H
