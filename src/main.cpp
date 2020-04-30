/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo3 - Rivières
 Fichier     : main.cpp
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 30.04.2020

 But         : Point d'entrée du programme pour lancer notre casse-tête des rivières

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#include <iostream>
#include "Controller.h"

int main() {
    Controller c;
    c.startGame();
    return EXIT_SUCCESS;
}
