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
    static void showMenu();


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
    void embark(Person *p);


    /**
     * disembark a person
     * @param name
     */
    void disembark(Person *p);

    /**
     *
     * @param bank
     */

    void moveBoat();


    /**
     * Handle user command
     * @param cmd
     */
    void handleCommand(const string &cmd);
    static bool checkDriver(Boat &b);
    bool ruleRobber(Container *c);
    bool ruleFather(Container *c);
    bool ruleMother(Container *c);
    void movePerson(Container *from, Container *to, Person *p);
    bool checkRules(Container *from, Container *to);
    void reset();
    void clear();
    Person* getPersonFromInput(const string &cmd);

private:
    list<Person *> _persons;
    list<Father *> _fathers;
    list<Mother *> _mothers;
    list<Son *> _sons;
    list<Daughter *> _daughters;
    list<Policeman *> _policemen;
    list<Robber *> _robbers;
    Bank *_bank1;
    Bank *_bank2;
    Boat *_boat;
    unsigned _currentTurn = 0;
    const int TAILLE_RIVIERE = 60;
    static const char QUIT = 'q', MENU = 'h', DISPLAY = 'p', MOVE = 'm', RESET = 'r', EMBARK = 'e', DISEMBARK = 'd';

};


#endif //POO2LABO3_2020_CONTROLLER_H
