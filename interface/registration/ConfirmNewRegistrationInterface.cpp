//
// Created by prodigy on 22/12/2020.
//

#include "ConfirmNewRegistrationInterface.h"
#include "../main/HomeInterface.h"
#include "../room/SelectFindRoomOptionInterface.h"

ConfirmNewRegistrationInterface::ConfirmNewRegistrationInterface(Hotel *hotel, Customer *customer) : Interface(hotel) {
            this -> lines = {
                    "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••",
                    "                          -=- Hotel Manament System: Résultat -=-",
                    "",
                    "",
                    "                Souhaitez-vous attribuer un nouveau séjour à <customer> ? ",
                    "",
                    "                                                          - (1) oui",
                    "                                                          - (2) non",
                    "",
                    "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••"
            };

            this -> customer = customer;

    }

    void ConfirmNewRegistrationInterface::checkAnswer(string answer) {
        vector<string> options { "oui", "non","o","n", "1", "2"};
        if (!isValidOption(options,answer)) {
            sendAvailableOptions(options);
            return;
        }
        if(answer == "non" or answer == "n" or answer == "2") {
            HomeInterface i = HomeInterface(hotel);
            i.display();
        } else if(answer == "oui" or answer == "o" or answer == "1") {
            SelectFindRoomOptionInterface i = SelectFindRoomOptionInterface(hotel,customer);
            i.display();
        }

    }


    void ConfirmNewRegistrationInterface::display() {
        map<string, string> m = {
                {"<customer>", customer->getName() + " " + customer->getFirstname()}};
        replaceTags(m);
        Interface::display();
}