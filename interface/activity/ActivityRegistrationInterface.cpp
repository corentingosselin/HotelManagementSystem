//
// Created by prodigy on 24/12/2020.
//

#include "ActivityRegistrationInterface.h"
#include "../main/HomeInterface.h"
#include "../registration/ActivityOrServiceInterface.h"

ActivityRegistrationInterface::ActivityRegistrationInterface(Hotel *hotel, Registration* registration, Date date) : Interface(hotel) {
    reset();
    this -> registration = registration;
    this -> date = date;

}

void ActivityRegistrationInterface::reset() {
    this -> lines = {
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••",
            "                          -=- Hotel Manament System: Ajout/annulation d'activité -=-",
            ""
    };
}


void ActivityRegistrationInterface::display() {
    reset();
    int current = 0;
    for(int i = 0; i < 13; i++) {
        Activity* a = hotel->getActivity(i);
       if(!hotel->isActivityFull(registration->getCustomer(), a,date)) {
            string check = "";
            if(hotel->hasActivity(registration,a, date)) check = "✓";
            lines.push_back("       (" + to_string(current) + ") " + check + " "
            + a->getDisplayName() + " " + to_string(hotel->getActivityCount(a,date)) + "/" + to_string(a->getMaxRegistrations()));
            selections.push_back(i);
           current++;
       }
    }
    selections.push_back(selections.size());
    lines.push_back("       (" + to_string(current ) + ")  Retours au choix des options");

    Interface::display();
}

void ActivityRegistrationInterface::checkAnswer(string answer) {
    vector<string> options;
    options.clear();
    for(int i : selections)
        options.push_back(to_string(i));
    if (!isValidOption(options,answer)) {
        sendAvailableOptions(options);
        return;
    }

    //is back
    if(answer == options.back()) {
        ActivityOrServiceInterface(hotel,registration).display();
    } else {
        Activity* act = hotel->getActivity(stoi(answer));

        if(!hotel->hasActivity(registration,act, date)) {
            hotel->addActivity(registration,act, date);
        } else {
            hotel->removeActivity(registration,act,date);
        }
        display();
    }

}
