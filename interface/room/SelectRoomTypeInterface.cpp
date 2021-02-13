//
// Created by prodigy on 23/12/2020.
//

#include "SelectRoomTypeInterface.h"
#include "any/ChooseAnyRoomInterface.h"

SelectRoomTypeInterface::SelectRoomTypeInterface(Hotel *hotel) : Interface(hotel) {
    this -> lines = {
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••",
            "                          -=- Hotel Manament System: Recherche de suite disponible -=-",
            "",
            ""
    };
}


void SelectRoomTypeInterface::checkAnswer(string answer) {
    vector<string> options;
    for(int i = 0; i < selections.size(); i++) {
        options.push_back(to_string(i));
    }
    if (!isValidOption(options,answer)) {
        sendAvailableOptions(options);
        return;
    }


    ChooseAnyRoomInterface i = ChooseAnyRoomInterface(hotel, std::stoi(answer));
    if(customer)
        i.setCustomer(customer);
    i.display();



}

void SelectRoomTypeInterface::setCustomer(Customer *customer) {
    this -> customer = customer;
}

void SelectRoomTypeInterface::display() {
    //relax

    int k = 0;
    for(int i = 0; i < 5; i++) {
        if (hotel->hasRoomTypeAvailable(i) or !customer) {
            string roomName = hotel->getRoomName(i);
            lines.push_back("           (" + to_string(k) + ") " + roomName + " - " + to_string(hotel->getAvailableRoomAmount(i)));
            selections.push_back(i);
            k++;
        }
    }

    lines.push_back("");
    lines.push_back("        Sélectionner un type de suite:");
    lines.push_back("");
    lines.push_back("");
    lines.push_back("••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••");

    Interface::display();
}
