/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo3 - Rivières
 Fichier     : Container.h
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 30.04.2020

 But         : Classe représentant un objet qui contient des personnes

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#ifndef POO2LABO3_2020_CONTAINER_H
#define POO2LABO3_2020_CONTAINER_H

#include <list>
#include <string>
#include "Person.h"

using namespace std;

class Person;

class Container {
public:
    /**
     * Constructeur de conteneur
     * @param name
     */
    explicit Container(const string &name);

    /**
     * Destructeur de conteneur
     */
    virtual ~ Container();

    /**
     * Getter de nom
     * @return
     */
    string getName() const;

    /**
     * Méthode d'ajout de person
     * @param person* personne à ajouter
     */
    virtual void addPerson(Person *person);

    /**
     * Méthode qui permet d'enlever d'un personne du conteneneur
     * @param Person* personne à enlever
     * @return
     */

    Person *removePerson(Person *person);

    /**
     * Méthode qui permet d'avoir le nombre de personne que contient le conteneur
     * @return int nombre de personnes
     */
    int getNumberOfPersons() const;

    /**
     * Méthode qui permet de savoir si un conteneur est vide
     * @return true si le conteneur est vide false sinon
     */
    bool isEmpty() const;

    /**
     * Méthode qui permet de savoir si une personne est dans le conteneur
     * @param person a chercher
     * @return true si la personne est présente false sinon
     */
    bool contains(const Person *person) const;
    /**
     * Méthode qui permet de vider le conteneur
     */
    void emtpy();
    /**
     * Méthode qui permet d'avoir la liste des personne qui sont dans le conteneur
     * @return
     */
    list<Person *> getPersons();
    /**
     * Méthode qui permet de savoir si notre conteneur est plein de base un conteneur ne peux pas être plein
     * on le redéfinit dans chaque sous classe.
     * @return
     */
    virtual bool isFull();

    /**
     * Opérateur de flux pour l'affichage
     * @param os
     * @param container
     * @return
     */
    friend ostream &operator<<(ostream &os, const Container &container);


protected:
    string _mame;
    list<Person *> _person;
};


#endif //POO2LABO3_2020_CONTAINER_H
