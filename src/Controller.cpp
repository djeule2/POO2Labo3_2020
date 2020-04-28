//
// Created by Lenovo T50s on 17.04.2020.
//

#include <iomanip>
#include <iostream>
#include "Controller.h"

Controller::Controller() {
    _fathers.push_back(new Father("pere"));
    for(Person *p : _fathers) {
        _persons.push_back(p);
    }
    _mothers.push_back(new Mother("mere"));
    for(Person *p : _mothers) {
        _persons.push_back(p);
    }
    _sons.push_back(new Son("paul"));
    _sons.push_back(new Son("pierre"));
    for(Person *p : _sons) {
        _persons.push_back(p);
    }
    _daughters.push_back(new Daughter("julie"));
    _daughters.push_back(new Daughter("jeanne"));
    for(Person *p : _daughters) {
        _persons.push_back(p);
    }
    _polimen.push_back(new Policeman("policier"));
    for(Person *p : _polimen) {
        _persons.push_back(p);
    }
    _robbers.push_back(new Robber("voleur"));
    for(Person *p : _robbers) {
        _persons.push_back(p);
    }

    _bank1 = new Bank("Gauche");
    _bank1->addPersons(_persons);
    _bank2 = new Bank("Droite");

    _boat = new Boat("Bateau", _bank1);

}

void Controller::showMenu() {
    const unsigned STREAM_SIZE = 6;
    const char space = ' ';
    cout << _poster << setfill(space) << setw(STREAM_SIZE) << space << ": afficher\n";
    cout << _load << " <nom>: embarquer <nom>\n"
         << _disload << " <nom>: debarquer <nom>\n";
    cout << _shift << setfill(space) << setw(STREAM_SIZE) << space << ": deplacer bateau\n";
    cout << _reset << setfill(space) << setw(STREAM_SIZE) << space << ": reinitialiser \n";
    cout << _quit << setfill(space) << setw(STREAM_SIZE) << space << ": quitter\n";
    cout << _menu << setfill(space) << setw(STREAM_SIZE) << space << ": menu\n\n";
}


void Controller::display() {

    if (_boat->getBank() == _bank1) {
        cout << *_bank1 << *_boat << setfill('=') << setw(TAILLE_RIVIERE) << "\n\n" << *_bank2 << "\n";
    } else {
        cout << *_bank1 << "\n\n" << setfill('=') << setw(TAILLE_RIVIERE) << "\n" << *_boat << *_bank2 << "\n";
    }
}


void Controller::nextTurn() {

}


void Controller::embark(const string &name) {

    const Person *person = _boat->getBank()->getPersonne(name);
    if (person != nullptr)
        _boat->addPerson(_boat->getBank()->removePerson(name));
    else
        cout << "pesonne absente" << endl;
}

void Controller::disembark(const string &name) {
    const Person *person = _boat->getPersonne(name);
    if (person != nullptr)
        _boat->getBank()->addPerson(_boat->removePerson(name));
    else
        cout << "personne absente" << endl;
}

void Controller::moveBoat(const Bank *bank) {
    if (!_boat->isEmpty())
        if (bank == _bank1) {
            _boat->setBank(_bank2);
        } else {
            _boat->setBank(_bank1);
        }
    else
        cout << " Le bateau est vide \n";
}


void Controller::handleCommand(const string &cmd) {
    string name;
    switch (cmd.at(0)) {
        case _disload:
            name = cmd.substr(2);
            disembark(name);
            display();
            break;
        case _load:
            name = cmd.substr(2);
            embark(name);
            display();
            break;
        case _menu:
            showMenu();
            break;
        case _shift:
            cout << "Deplacement du bateau \n";
            moveBoat(_boat->getBank());
            display();
            break;
        case _poster:
            display();
            break;
        case _quit:
            cout << "Fermeture de l'application. \n";
            break;
        case _reset:
            cout << "Reinitialisation du jeu. \n";
            showMenu();
            display();
            break;
        default:
            cout << "Commande invalide.\n";
            break;

    }
}

void Controller::startGame() {
    showMenu();
    display();
    string commande;
    do {
        cout << _currentTurn++ << ">";
        getline(cin, commande);
        handleCommand(commande);
    } while (commande.at(0) != _quit);
}



