//
// Created by prodigy on 22/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_CONFIRMNEWREGISTRATIONINTERFACE_H
#define HOTELMANAGEMENTSYSTEM_CONFIRMNEWREGISTRATIONINTERFACE_H


#include "../Interface.h"

class ConfirmNewRegistrationInterface : Interface {

public:
    ConfirmNewRegistrationInterface(Hotel *hotel, Customer *customer);
    void checkAnswer(string answer);
    void display();

protected:
    Customer* customer;

};


#endif //HOTELMANAGEMENTSYSTEM_CONFIRMNEWREGISTRATIONINTERFACE_H
