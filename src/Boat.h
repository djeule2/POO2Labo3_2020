/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo3 - Rivières
 Fichier     : Boat.h
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 30.04.2020

 But         : Classe représentant un bâteau

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#ifndef POO2LABO3_2020_BOAT_H
#define POO2LABO3_2020_BOAT_H


#include "Container.h"
#include "Bank.h"

class Boat : public Container {
public:
    /**
     * Constructeur de bâteau
     * @param name
     * @param bank
     */
    Boat(const string &name, Bank *bank);

    /**
     * Destructeur de bâteau
     */
    virtual ~Boat();

    /**
     * Opérateur de flux pour l'affichage
     * @param os
     * @param boat
     * @return
     */
    friend ostream &operator<<(ostream &os, const Boat &boat);

    /**
     * Méthode pour changer la rive d'amarrage du bâteau
     * @param bank rive sur laquelle le bâteau sera amarré
     */
    void setBank(Bank *bank);

    /**
     * Méthode pour savoir sur quelle rive se situe le bâteau
     * @return un pointeur sur la rive
     */
    Bank *getBank() const;

    /**
     * Méthode qui permet de savoir si le bâteau est plein
     * @return
     */
    bool isFull();

private:
    Bank *_currentBank;
    static const unsigned _MAX_PASSAGER = 2;

};


#endif //POO2LABO3_2020_BOAT_H
