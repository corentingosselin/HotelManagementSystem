//
// Created by prodigy on 24/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_ACTIVITYREGISTRATIONINTERFACE_H
#define HOTELMANAGEMENTSYSTEM_ACTIVITYREGISTRATIONINTERFACE_H


#include "../Interface.h"

class ActivityRegistrationInterface : public Interface {

public:
    ActivityRegistrationInterface(Hotel* hotel,Registration* registration, Date date);
    void checkAnswer(string answer);
    void display();

protected:
    Registration* registration;
    vector<int> selections;
    Date date;

    void reset();
};


#endif //HOTELMANAGEMENTSYSTEM_ACTIVITYREGISTRATIONINTERFACE_H
