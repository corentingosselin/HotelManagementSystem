//
// Created by prodigy on 18/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_CUSTOMERSEARCHINTERFACE_H
#define HOTELMANAGEMENTSYSTEM_CUSTOMERSEARCHINTERFACE_H


#include "../Interface.h"

class CustomerSearchInterface : public Interface {


public:
    CustomerSearchInterface(Hotel *hotel);
    void checkAnswer(string answer);
};


#endif //HOTELMANAGEMENTSYSTEM_CUSTOMERSEARCHINTERFACE_H
