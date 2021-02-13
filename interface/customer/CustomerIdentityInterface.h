//
// Created by prodigy on 25/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_CUSTOMERIDENTITYINTERFACE_H
#define HOTELMANAGEMENTSYSTEM_CUSTOMERIDENTITYINTERFACE_H


#include "../Interface.h"

class CustomerIdentityInterface : public Interface {

public:
    CustomerIdentityInterface(Hotel* hotel, Customer* customer);
    void checkAnswer(string answer);
    void display();

protected:
    Customer* customer;
    bool isRegistered = false;
};


#endif //HOTELMANAGEMENTSYSTEM_CUSTOMERIDENTITYINTERFACE_H
