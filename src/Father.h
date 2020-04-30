/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo3 - Rivières
 Fichier     : Father.h
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 30.04.2020

 But         : Classe Father qui représente un père

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#ifndef POO2LABO3_2020_FATHER_H
#define POO2LABO3_2020_FATHER_H

#include "Person.h"

class Father : public Person {
public:
    /**
     * Constructeur de Father
     * @param name
     */
    explicit Father(const string &name) : Person(name, true) {}
};

#endif //POO2LABO3_2020_FATHER_H
