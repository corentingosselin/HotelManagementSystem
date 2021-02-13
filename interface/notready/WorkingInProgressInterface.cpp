//
// Created by prodigy on 04/01/2021.
//

#include "WorkingInProgressInterface.h"
#include "../main/HomeInterface.h"

WorkingInProgressInterface::WorkingInProgressInterface(Hotel *hotel) : Interface(hotel) {
    this -> lines = {
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••",
            "                          -=- Hotel Manament System: En travaux -=-",
            "",
            "",
            "                Cette fonctionnalité n'est pas disponible encore... ",
            "",
            "                                                          - (1) confirmer",
            "",
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••"
    };


}

void WorkingInProgressInterface::checkAnswer(string answer) {
        HomeInterface i = HomeInterface(hotel);
        i.display();
}

