//
// Created by prodigy on 26/12/2020.
//

#include "NoRegistrationRoomInterface.h"
#include "../../main/HomeInterface.h"

NoRegistrationRoomInterface::NoRegistrationRoomInterface(Hotel *hotel) : Interface(hotel) {
    this -> lines = {
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••",
            "                      -=- Hotel Manament System: Résultat -=-",
            "",
            "            Aucun séjour en cours pour cette chambre...",
            "",
            "                                                          - (1) retour",
            "",
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••"
    };

}


void NoRegistrationRoomInterface::checkAnswer(string answer) {
    vector<string> options { "1"};
    if (answer != "1") {
        sendAvailableOptions(options);
        return;
    }

    HomeInterface(hotel).display();



}
