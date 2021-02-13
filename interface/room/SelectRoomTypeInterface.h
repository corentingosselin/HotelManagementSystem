//
// Created by prodigy on 23/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_SELECTROOMTYPEINTERFACE_H
#define HOTELMANAGEMENTSYSTEM_SELECTROOMTYPEINTERFACE_H


#include "../../hotel/customer/Customer.h"
#include "../../hotel/Hotel.h"
#include "../Interface.h"

class SelectRoomTypeInterface : Interface {

public:
    SelectRoomTypeInterface(Hotel* hotel);
    void checkAnswer(string answer);
    void display();
    void setCustomer(Customer* customer);

protected:
    Customer* customer = (0);
    vector<int> selections;


};


#endif //HOTELMANAGEMENTSYSTEM_SELECTROOMTYPEINTERFACE_H
