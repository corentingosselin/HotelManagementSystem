//
// Created by prodigy on 27/12/2020.
//

#include "ServiceRegistrationInterface.h"
#include "../registration/ActivityOrServiceInterface.h"

ServiceRegistrationInterface::ServiceRegistrationInterface(Hotel *hotel, Registration* registration) : Interface(hotel) {
    reset();
    this -> registration = registration;
}

void ServiceRegistrationInterface::reset() {
    this -> lines = {
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••",
            "                          -=- Hotel Manament System: Ajout/annulation de services -=-",
            ""
    };
}


void ServiceRegistrationInterface::display() {
    reset();
    int current = 0;
    for(Service service : hotel->getServices()) {
        string check = "";
        if(registration->hasService(current)) check = "✓";


        lines.push_back("       (" + to_string(current) + ") " + check + " " + service.getDisplayName() + " | " + to_string(service.getPrice()) + " euros par jour");
        selections.push_back(current);
        current++;
    }
    selections.push_back(current);
    lines.push_back("       (" + to_string(current ) + ")  Retours au menu des options");

    Interface::display();
}

void ServiceRegistrationInterface::checkAnswer(string answer) {
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
        int service = stoi(answer);
        if(!registration->hasService(service))
            registration->addService(service);
         else
            registration->removeService(service);

        display();
    }

}
