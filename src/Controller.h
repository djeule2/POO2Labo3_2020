/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo3 - Rivières
 Fichier     : Controller.h
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 30.04.2020

 But         : Classe qui représente le controller, elle gère chaque tour de jeu
                si la partie est gagnée et les règles.

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
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
    /**
     * Constructeur de Controller
     */
    Controller();

    /**
     * Destructeur de Controller
     */
    ~Controller();

    /**
     * Méthode qui lance le jeu
     */
    void startGame();

    /**
     * Méthode d'affichage du menu
     */
    static void showMenu();

    /**
     * Méthode d'affichage de l'état du jeu
     */
    void display();

    /**
     * Méthode qui incrémente le tour de jeu
     */
    void nextTurn();

    /**
     * Méthode qui embarque une personne
     * @param Person personne à embarquer
     */
    void embark(Person *p);

    /**
     * Méthode qui débarque une personne
     * @param Person personne à débarquer
     */
    void disembark(Person *p);

    /**
     * Méthode qui fait changer de rive au bâteau
     */
    void moveBoat();

    /**
     * Méthode qui agit selon la commande de l'utilisateur
     * @param cmd commande de l'utilisateur
     */
    void handleCommand(const string &cmd);

    /**
     * Méthode qui permet de savoir si les gens à bord du bâteau peuvent le faire naviguer
     * @param b bâteau à contrôler
     * @return boolean si le bâteau a un pilote
     */
    static bool checkDriver(Boat &b);

    /**
     * Méthode qui contrôle la règle de voleur/policier pour un conteneur
     * @param c conteneur sur lequel appliquer la règle
     * @return vrai si la règle n'est pas brisée
     */
    bool ruleRobber(Container *c);

    /**
     * Méthode qui contrôle la règle de père/fille pour un conteneur
     * @param c conteneur sur lequel appliquer la règle
     * @return vrai su  la règle n'est pas brisée
     */
    bool ruleFather(Container *c);

    /**
     * Méthode qui contrôle la règle mère/fils pour un conteneur
     * @param c conteneur sur lequel appliquer la règle
     * @return vrai si la règle n'est pas brisée
     */
    bool ruleMother(Container *c);

    /**
     * Méthode qui déplace une personne d'un conteneur à un autre vérifie si le déplacement peut se faire vis à vis
     *  des conteneurs et des personnes (capacité du conteneur/disponibilité de la personne dans le conteneur de départ)
     * @param from conteneur de départ
     * @param to conteneur d'arrivée
     * @param p personne à déplacer
     */
    void movePerson(Container *from, Container *to, Person *p);

    /**
     * Méthode qui passe en review toutes les règles sur deux conteneurs
     * @param from conteneur de départ
     * @param to conteneur d'arrivée
     */
    bool checkRules(Container *from, Container *to);

    /**
     * Méthode qui réinitialise l'état de la partie
     */
    void reset();

    /**
     * Méthode qui vide les conteneurs utilisés par le Controller
     */
    void clear();

    /**
     * Méthode qui prend en paramètre l'input de l'utilisateur pour en extraire la personne qui est entrée en second
     *  paramètre renvoi nullptr si la person n'est pas trouvée ou si il y a un soucis
     * @param cmd commande de l'utilisateur
     * @return pointeur vers la personne
     */
    Person *getPersonFromInput(const string &cmd);

    /**
     * Méthode qui permet de checker la condition de victoire.
     */
    void win();

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
