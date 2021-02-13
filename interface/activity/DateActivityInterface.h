//
// Created by prodigy on 26/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_DATEACTIVITYINTERFACE_H
#define HOTELMANAGEMENTSYSTEM_DATEACTIVITYINTERFACE_H


#include "../Interface.h"

class DateActivityInterface : public Interface {

public:
    DateActivityInterface(Hotel* hotel, Registration *registration);
    void checkAnswer(string answer);

protected:
    Registration* registration;


};


#endif //HOTELMANAGEMENTSYSTEM_DATEACTIVITYINTERFACE_H
