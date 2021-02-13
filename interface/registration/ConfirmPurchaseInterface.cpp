//
// Created by prodigy on 04/01/2021.
//

#include "ConfirmPurchaseInterface.h"
#include "../main/HomeInterface.h"

ConfirmPurchaseInterface::ConfirmPurchaseInterface(Hotel *hotel) : Interface(hotel) {
    this -> lines = {
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••",
            "                          -=- Hotel Manament System: Merci -=-",
            "",
            "",
            "                Le séjour a été payé ! Merci",
            "",
            "                                                          - (1) confirmer",
            "",
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••"
    };

}

void ConfirmPurchaseInterface::checkAnswer(string answer) {
        HomeInterface(hotel).display();
}

