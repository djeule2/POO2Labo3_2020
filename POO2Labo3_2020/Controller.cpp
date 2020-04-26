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
    cout<<_poster;
    cout.width(STREAM_SIZE);
    cout<<" "<<": afficher\n";
    cout<< _load + " <nom>: embarquer <nom>\n"
        << _disload + " <nom>: debarquer <nom>\n";
    cout<< _shift;
    cout.width(STREAM_SIZE);
    cout<<" "<<": deplacer bateau\n";
    cout<< _reset;
    cout.width(STREAM_SIZE) ;
    cout<<" "<< ": reinitialiser \n";
    cout<< _quit;
    cout.width(STREAM_SIZE);
    cout<<" "<<": quitter\n";
    cout << _menu ;
    cout.width(STREAM_SIZE) ;
    cout<<" "<<": menu\n\n";
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
    }while (commande != _quit);
}


void Controller::embark(const string& name){

    const Person* person = _boat->getBank()->getPersonne(name);
    if(person != nullptr)
        _boat->addPerson(_boat->getBank()->removePerson(name));
    else
        cout << "pesonne absente"<<endl;
}

void Controller::disembark(const string& name){
    cout<<name<<endl;
    const Person* person=_boat->getPersonne(name);
    if(person != nullptr)
        _boat->getBank()->addPerson(_boat->removePerson(name));
    else
        cout << "personne absente"<< endl;
}

void Controller::handleCommand(const string& cmd){
    string name;
    switch(cmd.at(0)){
        case 'd':
            name = cmd.substr(2);
            disembark(name);
            display();
            break;
        case 'e':
            name = cmd.substr(2);
            embark(name);
            display();
            break;
        case 'h':
            showMenu();
            break;
        case 'm':
            cout << "Deplacement du bateau \n";
            if(!_boat->isEmpty())
                if(_boat->getBank()==_bank1) {
                    _boat->setBank(_bank2);
                    display();
                }
                else {
                    _boat->setBank(_bank1);
                    display();
                }
            else
                cout << " Le bateau est vide \n";
            break;
        case 'p':
            display();
            break;
        case 'q':
            cout<<"Fermeture de l'application. \n";
            break;
        case 'r':
            cout <<"Reinitialisation du jeu. \n";
            name.clear();
            showMenu();
            display();
            break;
        default:
            cout << "Commande invalide.\n";
            break;

    }
}



