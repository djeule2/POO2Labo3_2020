//
// Created by Lenovo T50s on 17.04.2020.
//

#include <iomanip>
#include <iostream>
#include "Controller.h"

Controller::Controller() : _currentTurn(0) {
    _fathers.push_back(new Father("pere"));
    for (Person *p : _fathers) {
        _persons.push_back(p);
    }
    _mothers.push_back(new Mother("mere"));
    for (Person *p : _mothers) {
        _persons.push_back(p);
    }
    _sons.push_back(new Son("paul"));
    _sons.push_back(new Son("pierre"));
    for (Person *p : _sons) {
        _persons.push_back(p);
    }
    _daughters.push_back(new Daughter("julie"));
    _daughters.push_back(new Daughter("jeanne"));
    for (Person *p : _daughters) {
        _persons.push_back(p);
    }
    _policemen.push_back(new Policeman("policier"));
    for (Person *p : _policemen) {
        _persons.push_back(p);
    }
    _robbers.push_back(new Robber("voleur"));
    for (Person *p : _robbers) {
        _persons.push_back(p);
    }

    _bank1 = new Bank("Gauche");
    _bank2 = new Bank("Droite");

    _boat = new Boat("Bateau", _bank1);

    reset();

}

void Controller::showMenu() {
    const unsigned STREAM_SIZE = 6;
    const char space = ' ';
    cout << DISPLAY << setfill(space) << setw(STREAM_SIZE) << space << ": afficher\n";
    cout << EMBARK << " <nom>: embarquer <nom>\n"
         << DISEMBARK << " <nom>: debarquer <nom>\n";
    cout << MOVE << setfill(space) << setw(STREAM_SIZE) << space << ": deplacer bateau\n";
    cout << RESET << setfill(space) << setw(STREAM_SIZE) << space << ": reinitialiser \n";
    cout << QUIT << setfill(space) << setw(STREAM_SIZE) << space << ": quitter\n";
    cout << MENU << setfill(space) << setw(STREAM_SIZE) << space << ": menu\n\n";
}


void Controller::display() {

    if (_boat->getBank() == _bank1) {
        cout << *_bank1 << *_boat << setfill('=') << setw(TAILLE_RIVIERE) << "\n\n" << *_bank2 << "\n";
    } else {
        cout << *_bank1 << "\n\n" << setfill('=') << setw(TAILLE_RIVIERE) << "\n" << *_boat << *_bank2 << "\n";
    }
}

void Controller::embark(Person *p) {
    movePerson(_boat->getBank(), _boat, p);
    if (!checkRules(_boat->getBank(), _boat)) {
        movePerson(_boat, _boat->getBank(), p);
    } else {
        nextTurn();
    }
}

void Controller::disembark(Person *p) {
    movePerson(_boat, _boat->getBank(), p);
    if (!checkRules(_boat, _boat->getBank())) {
        movePerson(_boat->getBank(), _boat, p);
    } else {
        nextTurn();
    }
}

void Controller::moveBoat() {
    if (!_boat->isEmpty())
        if (checkDriver(*_boat)) {
            _boat->getBank() == _bank1 ? _boat->setBank(_bank2) : _boat->setBank(_bank1);
            nextTurn();
        } else {
            cout << "Pas de conducteur à bord" << endl;
        }
    else
        cout << " Le bateau est vide \n";
}


void Controller::handleCommand(const string &cmd) {
    string name;
    Person *p;
    switch (cmd.at(0)) {
        case DISEMBARK:
            p = getPersonFromInput(cmd);
            if (p != nullptr) {
                disembark(p);
                display();
            }
            break;
        case EMBARK:
            p = getPersonFromInput(cmd);
            if (p != nullptr) {
                embark(p);
                display();
            }
            break;
        case MENU:
            showMenu();
            break;
        case MOVE:
            cout << "Deplacement du bateau \n";
            moveBoat();
            display();
            break;
        case DISPLAY:
            display();
            break;
        case QUIT:
            cout << "Fermeture de l'application. \n";
            break;
        case RESET:
            cout << "Reinitialisation du jeu. \n";
            reset();
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
        cout << _currentTurn << ">";
        getline(cin, commande);
        handleCommand(commande);
    } while (commande.at(0) != QUIT);
}

void Controller::nextTurn() {
    _currentTurn++;
}

bool Controller::checkDriver(Boat &b) {
    for (Person *p : b.getPersons()) {
        if (p->canDrive()) {
            return true;
        }
    }
    return false;
}

void Controller::movePerson(Container *from, Container *to, Person *p) {
    if (from->contains(p)) {
        if (!to->isFull()) {
            from->removePerson(p);
            to->addPerson(p);
        } else {
            cout << "destination est pleine" << endl;
        }
    } else {
        cout << "la personne ne se trouve pas dans le container de depart" << endl;
    }
}

bool Controller::checkRules(Container *from, Container *to) {
    return ruleRobber(from) && ruleRobber(to)
           && ruleFather(from) && ruleFather(to)
           && ruleMother(from) && ruleMother(to);
}

bool Controller::ruleRobber(Container *c) {
    for (list<Robber *>::const_iterator itRobber = _robbers.begin(); itRobber != _robbers.end(); ++itRobber) {
        if (c->contains(*itRobber) && c->getNumberOfPersons() > 1) {
            for (list<Policeman *>::const_iterator itPoliceman = _policemen.begin();
                 itPoliceman != _policemen.end(); ++itPoliceman) {
                if (c->contains(*itPoliceman)) {
                    return true; // cas au moins un voleur et un policier
                }
            }
            cout << "mouvement impossible un voleur n'est pas surveille" << endl;
            return false; // cas au moins un voleur pas de policier
        }
    }
    return true; // cas aucun voleur
}

Person *Controller::getPersonFromInput(const string &cmd) {
    if (cmd.size() < 2) {
        cout << "Veuillez entrer un nom" << endl;
        return nullptr;
    }
    string personName = cmd.substr(2, cmd.size());
    for (Person *p : _persons) {
        if (p->getName() == personName) {
            return p;
        }
    }
    cout << "ce nom ne correspond à personne dans le jeu" << endl;
    return nullptr;
}

bool Controller::ruleFather(Container *c) {
    for (list<Father *>::const_iterator itFather = _fathers.begin(); itFather != _fathers.end(); ++itFather) {
        if (c->contains(*itFather)) {
            for (list<Daughter *>::const_iterator itDaughter = _daughters.begin();
                 itDaughter != _daughters.end(); ++itDaughter) {
                if (c->contains(*itDaughter)) {
                    for (list<Mother *>::const_iterator itMother = _mothers.begin();
                         itMother != _mothers.end(); ++itMother) {
                        if (c->contains(*itMother)) {
                            return true; // cas au moins un père avec au moins une fille et au moins une mère
                        }
                    }
                    cout << "un papa en présence d'un de ses fille sans maman" << endl;
                    return false; // cas au moins un père et au moins une fille mais pas de mère
                }
            }
        }
    }
    return true; // cas pas de père ou au moins un père et pas de fille
}

bool Controller::ruleMother(Container *c) {
    for (list<Mother *>::const_iterator itMother = _mothers.begin(); itMother != _mothers.end(); ++itMother) {
        if (c->contains(*itMother)) {
            for (list<Son *>::const_iterator itSon = _sons.begin(); itSon != _sons.end(); ++itSon) {
                if (c->contains(*itSon)) {
                    for (list<Father *>::const_iterator itFather = _fathers.begin();
                         itFather != _fathers.end(); ++itFather) {
                        if (c->contains(*itFather)) {
                            return true; // cas au moins une mère avec au moins un fils et au moins un père
                        }
                    }
                    cout << "une maman en présence d'un de ses fils sans papa" << endl;
                    return false; // cas au moins une mère et au moins un fils mais pas de père
                }
            }
        }
    }
    return true; // cas pas de mère ou au moins une mère et pas de fils
}

void Controller::reset() {
    clear();
    _currentTurn = 0;
    _bank1->addPersons(_persons);
}

void Controller::clear() {
    _bank1->emtpy();
    _bank2->emtpy();
    _boat->emtpy();
    _boat->setBank(_bank1);
}





