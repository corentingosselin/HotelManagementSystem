//
// Created by prodigy on 19/12/2020.
//

#include "CustomerNotFoundInterface.h"
#include "../main/HomeInterface.h"
#include "CreateCustomerInterface.h"

CustomerNotFoundInterface::CustomerNotFoundInterface(Hotel *hotel) : Interface(hotel) {
    this -> lines = {
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••",
            "                          -=- Hotel Manament System: Résultat -=-",
            "",
            "            Aucun résultat trouvé...",
            "",
            "                Souhaitez-vous créer un nouveau client ? ",
            "",
            "                                                          - (1) oui",
            "                                                          - (2) non",
            "",
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••"
    };

}

void CustomerNotFoundInterface::checkAnswer(string answer) {
    vector<string> options { "oui", "non","o","n", "1", "2"};
    if (!isValidOption(options,answer)) {
        sendAvailableOptions(options);
        return;
    }
    if(answer == "non" or answer == "n" or answer == "2") {
        HomeInterface i = HomeInterface(hotel);
        i.display();
    } else if(answer == "oui" or answer == "o" or answer == "1") {
        CreateCustomerInterface i = CreateCustomerInterface(hotel);
        i.display();
    }

}
