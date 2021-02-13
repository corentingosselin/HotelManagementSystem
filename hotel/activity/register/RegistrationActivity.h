//
// Created by prodigy on 27/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_REGISTRATIONACTIVITY_H
#define HOTELMANAGEMENTSYSTEM_REGISTRATIONACTIVITY_H


#include "../../registration/Registration.h"
#include "../Activity.h"

class RegistrationActivity {

public:
    RegistrationActivity(Registration* registration, Activity* activity, Date date);
    Activity* getActivity();
    Date getDate();
    Registration* getRegistration();
protected:
    Registration* registration;
    Activity* activity;
    Date date;


};


#endif //HOTELMANAGEMENTSYSTEM_REGISTRATIONACTIVITY_H
