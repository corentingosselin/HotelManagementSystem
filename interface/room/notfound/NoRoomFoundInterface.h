//
// Created by prodigy on 23/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_NOROOMFOUNDINTERFACE_H
#define HOTELMANAGEMENTSYSTEM_NOROOMFOUNDINTERFACE_H


#include "../../Interface.h"

class NoRoomFoundInterface : Interface {

public:
    NoRoomFoundInterface(Hotel* hotel);
    void checkAnswer(string answer);
    void setCustomer(Customer* customer);

protected:
    Customer* customer = (0);

};




#endif //HOTELMANAGEMENTSYSTEM_NOROOMFOUNDINTERFACE_H
