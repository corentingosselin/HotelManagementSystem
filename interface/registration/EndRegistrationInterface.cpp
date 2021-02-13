//
// Created by prodigy on 26/12/2020.
//

#include "EndRegistrationInterface.h"
#include "../main/HomeInterface.h"
#include "RegistrationCancelledInterface.h"
#include "BillGenerationInterface.h"

EndRegistrationInterface::EndRegistrationInterface(Hotel *hotel, Registration* registration) : Interface(hotel) {
    this -> lines = {
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••",
            "                          -=- Hotel Manament System: Fin du séjour -=-",
            "",
            "            Le client <customer> termine son séjour ?",
            "",
            "                Vous souhaitez ? ",
            "",
            "                                                          (1) Générer la facture",
            "                                                          (2) Annuler le séjour",
            "                                                          (3) Retourner au menu principal",
            "",
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••"
    };

    this -> registration = registration;

}

void EndRegistrationInterface::checkAnswer(string answer) {
    vector<string> options { "1","2","3"};
    if (!isValidOption(options,answer)) {
        sendAvailableOptions(options);
        return;
    }
    if(answer == "3") {
        HomeInterface i = HomeInterface(hotel);
        i.display();
    } else if(answer == "2") {
        hotel->removeRegistration(registration);
        RegistrationCancelledInterface(hotel).display();
    } else if(answer == "1") {
        BillGenerationInterface(hotel,registration).display();

    }

}


void EndRegistrationInterface::display() {
    map<string, string> m = {
            {"<customer>", registration->getCustomer()->getName() + " " + registration->getCustomer()->getFirstname()}};
    replaceTags(m);
    Interface::display();
}