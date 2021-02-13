//
// Created by prodigy on 25/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_CUSTOMERSFOUNDINTERFACE_H
#define HOTELMANAGEMENTSYSTEM_CUSTOMERSFOUNDINTERFACE_H


#include "../Interface.h"


class CustomersFoundInterface : public Interface {

public:
    CustomersFoundInterface(Hotel* hotel, string input);
    void checkAnswer(string answer);
    void display();

protected:
    string input;
};


#endif //HOTELMANAGEMENTSYSTEM_CUSTOMERSFOUNDINTERFACE_H
