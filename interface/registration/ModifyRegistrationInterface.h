//
// Created by prodigy on 04/01/2021.
//

#ifndef HOTELMANAGEMENTSYSTEM_MODIFYREGISTRATIONINTERFACE_H
#define HOTELMANAGEMENTSYSTEM_MODIFYREGISTRATIONINTERFACE_H


#include "../Interface.h"

class ModifyRegistrationInterface : public Interface {

public:
    ModifyRegistrationInterface(Hotel* hotel, Registration* registration);
    void checkAnswer(string answer);
    void display();

protected:
    Registration* registration;

};



#endif //HOTELMANAGEMENTSYSTEM_MODIFYREGISTRATIONINTERFACE_H
