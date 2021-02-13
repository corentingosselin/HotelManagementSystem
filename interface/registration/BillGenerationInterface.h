//
// Created by prodigy on 26/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_BILLGENERATIONINTERFACE_H
#define HOTELMANAGEMENTSYSTEM_BILLGENERATIONINTERFACE_H


#include "../Interface.h"

class BillGenerationInterface : Interface {

public:
    BillGenerationInterface(Hotel *hotel, Registration* registration);
    void checkAnswer(string answer);
    void display();

protected:
    Registration* registration;

};


#endif //HOTELMANAGEMENTSYSTEM_BILLGENERATIONINTERFACE_H
