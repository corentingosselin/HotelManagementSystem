//
// Created by prodigy on 26/12/2020.
//

#include "RegistrationRoomFoundInterface.h"
#include "../../main/HomeInterface.h"
#include "../../registration/ActivityOrServiceInterface.h"
#include "../../registration/ModifyRegistrationInterface.h"

RegistrationRoomFoundInterface::RegistrationRoomFoundInterface(Hotel *hotel, int registrationID) : Interface(hotel) {
    this -> lines = {
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••",
            "                          -=- Hotel Manament System: Résultat -=-",
            "",
            "            Un séjour est en cours pour cette chambre",
            "",
            "                Vous souhaitez ? ",
            "",
            "                                                          (1) Modifier le  séjour",
            "                                                          (2) Retour au menu principal",
            "",
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••"
    };

    for(Registration r : hotel->getRegistrations()) {
        if(r.getID() == registrationID) {
            this -> registration = &r;
            break;
        }
    }

}


void RegistrationRoomFoundInterface::checkAnswer(string answer) {
    vector<string> options { "1","2","3"};
    if (!isValidOption(options,answer)) {
        sendAvailableOptions(options);
        return;
    }

    if(answer == "2") {
        HomeInterface(hotel).display();
    } else if(answer == "1") {
        ModifyRegistrationInterface(hotel,registration).display();
    }
}
