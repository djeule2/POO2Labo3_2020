#include <iostream>
#include "Person.h"
#include "Controller.h"
#include "Container.h"
#include "Boat.h"
#include "Bank.h"

int main() {
    list<Person*> travellers = {
            new Person("pere", Gender::M),
            new Person("mere", Gender::F),
            new Person("paul", Gender::M),
            new Person("pierre", Gender::M),
            new Person("julie", Gender::F),
            new Person("jeanne", Gender::F),
            new Person("policier", Gender::M),
            new Person("voleur", Gender::M)};

    Bank leftBank("Gauche");
    Bank rigthBank("Droite");

    Boat boat("Bateau", &leftBank);

   Controller controller(travellers, &leftBank, &rigthBank, &boat);

   controller.showMenu();

   controller.display();

   controller.nextTurn();
    return EXIT_SUCCESS;
}
