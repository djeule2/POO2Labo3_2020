/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo3 - Rivières
 Fichier     : Person.h
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 30.04.2020

 But         : Classe Person qui représente une personne

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#ifndef POO2LABO3_2020_PERSON_H
#define POO2LABO3_2020_PERSON_H

#include <string>
#include <iostream>

using namespace std;

class Person {
public:
    /**
     * Constructeur de Person
     * @param name nom de la personne
     * @param canDrive paramètre de conduite
     */
    explicit Person(const string &name, bool canDrive = false);

    /**
     * Destructeur de Person
     */
    ~Person();

    /**
    * Méthode qui nous permet de savoir si la personne peut conduire
    * @return
    */
    bool canDrive() const;
    /**
     * Méthode qui rend le nom de la personne
     * @return le nom
     */
    string getName() const;

private:
    string _name;
    bool _canDrive;

};


#endif //POO2LABO3_2020_PERSON_H
