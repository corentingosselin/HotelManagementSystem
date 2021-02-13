//
// Created by prodigy on 26/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_ENDREGISTRATIONINTERFACE_H
#define HOTELMANAGEMENTSYSTEM_ENDREGISTRATIONINTERFACE_H


#include "../Interface.h"

class EndRegistrationInterface : public Interface {

public:
    EndRegistrationInterface(Hotel* hotel, Registration* registration);
    void checkAnswer(string answer);
    void display();

protected:
    Registration* registration;

};


#endif //HOTELMANAGEMENTSYSTEM_ENDREGISTRATIONINTERFACE_H
