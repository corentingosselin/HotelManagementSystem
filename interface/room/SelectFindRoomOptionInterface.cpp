//
// Created by prodigy on 23/12/2020.
//

#include "SelectFindRoomOptionInterface.h"
#include "../../hotel/Hotel.h"
#include "../main/HomeInterface.h"
#include "SelectRoomTypeInterface.h"

SelectFindRoomOptionInterface::SelectFindRoomOptionInterface(Hotel *hotel, Customer* customer) : Interface(hotel) {
    this -> lines = {
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••\n"
            "                          -=- Hotel Manament System: Recherche de suite disponible -=-\n",
            "",
            "",
            "         Pour le client <customer> vous cherchez:",
            "",
            "                  (1) Une suite disponible",
            "                  (2) Revenir au menu principal"
            "",
            "",
            "        Sélectionner une option:"
    };

    this -> customer = customer;
}


void SelectFindRoomOptionInterface::checkAnswer(string answer) {
    vector<string> options { "1", "2"};
    if (!isValidOption(options,answer)) {
        sendAvailableOptions(options);
        return;
    }
    if(answer == "1") {
        SelectRoomTypeInterface i = SelectRoomTypeInterface(hotel);
        i.setCustomer(customer);
        i.display();
    } else  if(answer == "2") {
        HomeInterface h = HomeInterface(hotel);
        h.display();
    }
}

void SelectFindRoomOptionInterface::display() {
    map<string, string> m = {
              {"<customer>", customer->getName() + " " + customer->getFirstname()}};
    replaceTags(m);
    Interface::display();
}