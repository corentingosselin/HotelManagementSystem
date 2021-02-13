//
// Created by prodigy on 26/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_REGISTRATIONROOMFOUNDINTERFACE_H
#define HOTELMANAGEMENTSYSTEM_REGISTRATIONROOMFOUNDINTERFACE_H


#include "../../Interface.h"

class RegistrationRoomFoundInterface : public Interface {


public:

    RegistrationRoomFoundInterface(Hotel *hotel, int registrationID);
    void checkAnswer(string answer);

protected:
    Registration* registration;
};


#endif //HOTELMANAGEMENTSYSTEM_REGISTRATIONROOMFOUNDINTERFACE_H
