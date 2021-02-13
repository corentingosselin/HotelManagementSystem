//
// Created by prodigy on 26/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_REGISTRATIONCANCELLEDINTERFACE_H
#define HOTELMANAGEMENTSYSTEM_REGISTRATIONCANCELLEDINTERFACE_H


#include "../Interface.h"

class RegistrationCancelledInterface : public Interface {


public:
    RegistrationCancelledInterface(Hotel* hotel);
    void checkAnswer(string answer);
};


#endif //HOTELMANAGEMENTSYSTEM_REGISTRATIONCANCELLEDINTERFACE_H
