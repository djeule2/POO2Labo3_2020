/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo3 - Rivières
 Fichier     : Bank.h
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 30.04.2020

 But         : Classe représentant une rive

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#ifndef POO2LABO3_2020_BANK_H
#define POO2LABO3_2020_BANK_H


#include "Container.h"
using namespace std;

class Bank : public Container{
public:
    /**
     * Constructeur de Bank
     * @param name
     */
    Bank(const string& name);
    /**
     * Opérateur de flux sortant pour l'affichage
     * @param os
     * @param bank
     * @return
     */
    friend ostream& operator <<(ostream& os, const Bank& bank);
    /**
     * Fonction qui permet l'ajout d'une liste de person
     * @param listPersons personnes à ajouter à notre Bank
     */
    void addPersons(list< Person*> listPersons);

private:
    const int SIZE_BANK =60; // paramètre d'affichage



};


#endif //POO2LABO3_2020_BANK_H
