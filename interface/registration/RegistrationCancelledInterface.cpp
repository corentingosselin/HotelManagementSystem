//
// Created by prodigy on 26/12/2020.
//

#include "RegistrationCancelledInterface.h"
#include "../main/HomeInterface.h"

RegistrationCancelledInterface::RegistrationCancelledInterface(Hotel *hotel) : Interface(hotel) {
    this -> lines = {
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••",
            "                          -=- Hotel Manament System: Séjour annulé  -=-",
            "",
            "",
            "                Le séjour a été annulé... ",
            "",
            "                                                          - (1) confirmer",
            "",
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••"
    };


}

void RegistrationCancelledInterface::checkAnswer(string answer) {
    HomeInterface(hotel).display();

}
