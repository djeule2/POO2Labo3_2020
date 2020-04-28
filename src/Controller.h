//
// Created by Lenovo T50s on 17.04.2020.
//

#ifndef POO2LABO3_2020_CONTROLLER_H
#define POO2LABO3_2020_CONTROLLER_H


#include <list>
#include "Bank.h"
#include "Boat.h"
#include "Son.h"
#include "Mother.h"
#include "Father.h"
#include "Daughter.h"
#include "Policeman.h"
#include "Robber.h"

class Controller {
public:
    Controller();

    void startGame();

    /**
     * Displays the different commands admissible for the game
     */
    void showMenu();


    /**
     * Displays the current state of the game and the various admissible commands
     */
    void display();


    /**
     * go to the next round
     */
    void nextTurn();


    /**
     * embark a personn
     * @param name
     */
    void embark(const string &name);


    /**
     * disembark a person
     * @param name
     */
    void disembark(const string &name);

    /**
     *
     * @param bank
     */

    void moveBoat(const Bank *bank);


    /**
     * Handle user command
     * @param cmd
     */
    void handleCommand(const string &cmd);

private:
    list<Person *> _persons;
    list<Father *> _fathers;
    list<Mother *> _mothers;
    list<Son *> _sons;
    list<Daughter *> _daughters;
    list<Policeman *> _polimen;
    list<Robber *> _robbers;
    Bank *_bank1;
    Bank *_bank2;
    Boat *_boat;
    unsigned _currentTurn = 0;
    const int TAILLE_RIVIERE = 60;
    static const char _quit = 'q', _menu = 'h', _poster = 'p', _shift = 'm', _reset = 'r', _load = 'e', _disload = 'd';

};


#endif //POO2LABO3_2020_CONTROLLER_H
