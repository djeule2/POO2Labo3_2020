//
// Created by Lenovo T50s on 17.04.2020.
//

#include <iomanip>
#include <iostream>
#include "Controller.h"

Controller::Controller(const list<Person *> &person, Bank* startBank, Bank* finalBank, Boat* boat): _person(person), _bank1(startBank),
_bank2(finalBank), _boat(boat){
    _bank1->addPersons(_person);

}

void Controller::showMenu(){
    const unsigned STREAM_SIZE =6;
    const char space=' ';
    cout<<_poster<< setfill(space) <<setw(STREAM_SIZE)<<space<<": afficher\n";
    cout<< _load << " <nom>: embarquer <nom>\n"
        << _disload << " <nom>: debarquer <nom>\n";
    cout<< _shift << setfill(space)<<setw(STREAM_SIZE)<<space<<": deplacer bateau\n";
    cout<< _reset << setfill(space)<< setw(STREAM_SIZE)<<space<< ": reinitialiser \n";
    cout<< _quit << setfill(space)<<setw(STREAM_SIZE)<<space<<": quitter\n";
    cout << _menu << setfill(space)<< setw(STREAM_SIZE)<<space<<": menu\n\n";
}


void Controller::display(){

    if(_boat->getBank()==_bank1) {
        cout << *_bank1 << *_boat << setfill('=') << setw(TAILLE_RIVIERE) << "\n\n" << *_bank2 << "\n";
    }
    else {
        cout <<* _bank1 << "\n\n" << setfill('=') << setw(TAILLE_RIVIERE) << "\n" << *_boat << *_bank2 << "\n";
    }
}


void Controller::nextTurn(){
    string commande;
    do{
        cout << _currentTurn++ << ">";
        getline(cin, commande);
        handleCommand(commande);
    }while (commande.at(0) != _quit);
}


void Controller::embark(const string& name){

    const Person* person = _boat->getBank()->getPersonne(name);
    if(person != nullptr)
        _boat->addPerson(_boat->getBank()->removePerson(name));
    else
        cout << "pesonne absente"<<endl;
}

void Controller::disembark(const string& name){
    const Person* person=_boat->getPersonne(name);
    if(person != nullptr)
        _boat->getBank()->addPerson(_boat->removePerson(name));
    else
        cout << "personne absente"<< endl;
}

void Controller::moveBoat(const Bank* bank){
    if(!_boat->isEmpty())
        if(bank==_bank1) {
            _boat->setBank(_bank2);
        }
        else {
            _boat->setBank(_bank1);
        }
    else
        cout << " Le bateau est vide \n";
}


void Controller::handleCommand(const string& cmd){
    string name;
    switch(cmd.at(0)){
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
            cout<<"Fermeture de l'application. \n";
            break;
        case _reset:
            cout <<"Reinitialisation du jeu. \n";
            showMenu();
            display();
            break;
        default:
            cout << "Commande invalide.\n";
            break;

    }
}



