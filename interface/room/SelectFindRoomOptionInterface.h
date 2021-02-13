//
// Created by prodigy on 23/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_SELECTFINDROOMOPTIONINTERFACE_H
#define HOTELMANAGEMENTSYSTEM_SELECTFINDROOMOPTIONINTERFACE_H


#include "../Interface.h"

class SelectFindRoomOptionInterface : Interface {

public:
    SelectFindRoomOptionInterface(Hotel* hotel, Customer* customer);
    void checkAnswer(string answer);
    void display();

protected:
    Customer* customer;



};


#endif //HOTELMANAGEMENTSYSTEM_SELECTFINDROOMOPTIONINTERFACE_H
