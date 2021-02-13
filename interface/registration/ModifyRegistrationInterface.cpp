//
// Created by prodigy on 04/01/2021.
//

#include "ModifyRegistrationInterface.h"
#include "../main/HomeInterface.h"
#include "ActivityOrServiceInterface.h"
#include "EndRegistrationInterface.h"

ModifyRegistrationInterface::ModifyRegistrationInterface(Hotel *hotel, Registration* registration) : Interface(hotel) {
    this -> lines = {
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••",
            "                          -=- Hotel Manament System: Modification du séjour -=-",
            "",
            "            Pour le séjour du client <customer>",
            "",
            "                Vous souhaitez ? ",
            "",
            "                                                          (1) Modifier les activités/services",
            "                                                          (2) Mettre fin au séjour",
            "                                                          (3) Retourner au menu principal",
            "",
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••"
    };

    this -> registration = registration;

}

void ModifyRegistrationInterface::checkAnswer(string answer) {
    vector<string> options { "1","2","3"};
    if (!isValidOption(options,answer)) {
        sendAvailableOptions(options);
        return;
    }
    if(answer == "3") {
        HomeInterface i = HomeInterface(hotel);
        i.display();
    } else if(answer == "2") {
        EndRegistrationInterface(hotel,registration).display();
    } else if(answer == "1") {
        ActivityOrServiceInterface(hotel,registration).display();
    }

}


void ModifyRegistrationInterface::display() {
    map<string, string> m = {
            {"<customer>", registration->getCustomer()->getName() + " " + registration->getCustomer()->getFirstname()}};
    replaceTags(m);
    Interface::display();
}