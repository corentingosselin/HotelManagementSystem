//
// Created by prodigy on 24/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_ACTIVITYORSERVICEINTERFACE_H
#define HOTELMANAGEMENTSYSTEM_ACTIVITYORSERVICEINTERFACE_H


#include "../Interface.h"
#include "../../hotel/registration/Registration.h"

class ActivityOrServiceInterface : Interface {

public:
    ActivityOrServiceInterface(Hotel *hotel, Registration* registration);
    void checkAnswer(string answer);
    void display();

protected:
    Registration* registration;

};


#endif //HOTELMANAGEMENTSYSTEM_ACTIVITYORSERVICEINTERFACE_H
