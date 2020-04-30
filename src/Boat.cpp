/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo3 - Rivières
 Fichier     : Boat.cpp
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 30.04.2020

 But         : Fichier d'implémentation de la classe Boat

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#include "Boat.h"

Boat::Boat(const string &name, Bank *bank) : Container(name), _currentBank(bank) {}

Boat::~Boat() {}

ostream &operator<<(ostream &os, const Boat &boat) {
    os << boat.getName() << " : < " << (Container) boat << ">\n";
    return os;
}

void Boat::setBank(Bank *bank) {
    _currentBank = bank;
}

Bank *Boat::getBank() const {
    return _currentBank;
}

bool Boat::isFull() {
    return _person.size() >= _MAX_PASSAGER;
}
