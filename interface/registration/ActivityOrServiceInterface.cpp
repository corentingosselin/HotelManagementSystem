//
// Created by prodigy on 24/12/2020.
//

#include "ActivityOrServiceInterface.h"
#include "../main/HomeInterface.h"
#include "../activity/ActivityRegistrationInterface.h"
#include "../activity/DateActivityInterface.h"
#include "../service/ServiceRegistrationInterface.h"

ActivityOrServiceInterface::ActivityOrServiceInterface(Hotel *hotel, Registration *registration) : Interface(hotel) {
    this -> lines = {
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••",
            "                          -=- Hotel Manament System: Résultat -=-",
            "",
            "",
            "                Quelle option souhaitez-vous ajouter/supprimer à la réservation du client: <customer> ? ",
            "",
            "                                                          - (1) Des activités",
            "                                                          - (2) Des services",
            "                                                          - (3) Aucune",
            "",
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••"
    };

    this -> registration = registration;

}

void ActivityOrServiceInterface::checkAnswer(string answer) {
    vector<string> options { "1", "2","3"};
    if (!isValidOption(options,answer)) {
        sendAvailableOptions(options);
        return;
    }
    if(answer == "1") {
        DateActivityInterface(hotel,registration).display();
    } else if(answer == "2") {
        ServiceRegistrationInterface(hotel,registration).display();
    } else if(answer == "3") {
        HomeInterface i = HomeInterface(hotel);
        i.display();
    }

}


void ActivityOrServiceInterface::display() {
    map<string, string> m = {
            {"<customer>", registration->getCustomer()->getName() + " " + registration->getCustomer()->getFirstname()}};
    replaceTags(m);
    Interface::display();
}