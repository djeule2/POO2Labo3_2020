//
// Created by Lenovo T50s on 17.04.2020.
//

#ifndef POO2LABO3_2020_PERSON_H
#define POO2LABO3_2020_PERSON_H

#include <string>
#include <iostream>
#include "Container.h"
using namespace std;

class Person {
public:
    Person(const string& name, bool canDrive = false);
    ~Person();

    /**
    * specify if a person is able to drive
    * @param c
    * @return true is the Person is able to drive, false otherwise
    */
    virtual bool canDrive() ;

    /**
     * moves the Person from one Container to another
     * @param from Container this Person is actually in
     * @param to Container this Person need to move to
     * @return true is the specified movement is allowed
     */
  //  virtual bool move (Container* from, Container* to)const ;

   /**
    * Indicate whether the Person can leave the specified Container
    * @param c the Container we ask if the person can quit
    * @return true is the person can leave, false otherwise
    */
   // virtual bool canLeaveContainer(Container* c)const ;

    /**
    * Indicate whether the Person can join the specified Container
    * @param c the Container we ask if the person can quit
    * @return true is the person can leave, false otherwise
    */
   // virtual bool canJoinContainer(Container* c) const ;

    string getName()const ;

private:
    string  _name;
    bool _canDrive;

};


#endif //POO2LABO3_2020_PERSON_H
