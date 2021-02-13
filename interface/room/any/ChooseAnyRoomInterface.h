//
// Created by prodigy on 23/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_CHOOSEANYROOMINTERFACE_H
#define HOTELMANAGEMENTSYSTEM_CHOOSEANYROOMINTERFACE_H


#include "../../../hotel/Hotel.h"
#include "../../Interface.h"

class ChooseAnyRoomInterface  : Interface {

public:
    ChooseAnyRoomInterface(Hotel* hotel, int type);
    void checkAnswer(string answer);
    void display();
    void setCustomer(Customer* customer);
    vector<Room*> found;

protected:
    Customer* customer = (0);
    int type;



};


#endif //HOTELMANAGEMENTSYSTEM_CHOOSEANYROOMINTERFACE_H
