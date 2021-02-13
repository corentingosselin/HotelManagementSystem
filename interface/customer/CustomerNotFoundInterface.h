//
// Created by prodigy on 19/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_CUSTOMERNOTFOUNDINTERFACE_H
#define HOTELMANAGEMENTSYSTEM_CUSTOMERNOTFOUNDINTERFACE_H

#include "../Interface.h"

class CustomerNotFoundInterface: public Interface {


public:
    CustomerNotFoundInterface(Hotel *hotel);
    void checkAnswer(string answer);

};



#endif //HOTELMANAGEMENTSYSTEM_CUSTOMERNOTFOUNDINTERFACE_H
