//
// Created by Lenovo T50s on 17.04.2020.
//

#ifndef POO2LABO3_2020_BOAT_H
#define POO2LABO3_2020_BOAT_H


#include "Container.h"
#include "Bank.h"

class Boat: public Container{
public:
    Boat(const string& name,  Bank* bank);
    virtual ~Boat();

    /**
     * boat display
     * @param os
     * @param boat
     * @return
     */
    friend ostream& operator<< (ostream& os, const Boat& boat);

    /**
     * move a boat
     * @param bank
     */
    void setBank(Bank* bank);

   /**
    * know on which shore the boat is
    * @return
    */
    Bank* getBank() const ;


private:
    Bank* _currentBank;
    static const unsigned _MAX_PASSAGER = 2;

};


#endif //POO2LABO3_2020_BOAT_H
