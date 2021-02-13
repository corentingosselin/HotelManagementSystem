//
// Created by prodigy on 23/12/2020.
//

#include "NoRoomFoundInterface.h"
#include "../../main/HomeInterface.h"
#include "../SelectFindRoomOptionInterface.h"

NoRoomFoundInterface::NoRoomFoundInterface(Hotel *hotel) : Interface(hotel) {
    this -> lines = {
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••\n"
            "                          -=- Hotel Manament System: Résultat -=-\n",
            "",
            "",
            "         Aucune chambre trouvée pour votre recherche... ",
            "",
            "                  (1) Modifier la recherche>",
            "                  (2) Revenir au menu principal",
            "",
            "        Sélectionner une option:",
            ""
    };
}

void NoRoomFoundInterface::setCustomer(Customer *customer) {
    this -> customer = customer;
}

void NoRoomFoundInterface::checkAnswer(string answer) {
    vector<string> options { "1", "2"};
    if (!isValidOption(options,answer)) {
        sendAvailableOptions(options);
        return;
    }
    if(answer == "1") {
        if(customer) {
            SelectFindRoomOptionInterface i = SelectFindRoomOptionInterface(hotel, customer);
            i.display();
        } else {
            HomeInterface(hotel).display();
        }
    } else if(answer == "2") {
        HomeInterface(hotel).display();
    }
}
