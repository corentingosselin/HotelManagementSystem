//
// Created by prodigy on 27/12/2020.
//

#include "RegistrationActivity.h"
RegistrationActivity::RegistrationActivity(Registration* registration, Activity *activity, Date date) {
    this -> registration = registration;
    this -> activity = activity;
    this -> date = date;
}

Date RegistrationActivity::getDate() {
    return date;
}

Activity * RegistrationActivity::getActivity() {
    return activity;
}

Registration * RegistrationActivity::getRegistration() {
    return registration;
}