//
// Created by prodigy on 27/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_SERVICEREGISTRATIONINTERFACE_H
#define HOTELMANAGEMENTSYSTEM_SERVICEREGISTRATIONINTERFACE_H


#include "../Interface.h"

class ServiceRegistrationInterface : public Interface {

public:
    ServiceRegistrationInterface(Hotel* hotel,Registration* registration);
    void checkAnswer(string answer);
    void display();

protected:
    Registration* registration;
    vector<int> selections;

    void reset();
};

#endif //HOTELMANAGEMENTSYSTEM_SERVICEREGISTRATIONINTERFACE_H
