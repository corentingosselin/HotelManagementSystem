//
// Created by prodigy on 23/12/2020.
//

#include "ChooseAnyRoomInterface.h"
#include "../../registration/ConfirmNewRegistrationInterface.h"
#include "../../registration/CreateRegistrationInterface.h"
#include "../registration/RegistrationRoomFoundInterface.h"
#include "../registration/NoRegistrationRoomInterface.h"

ChooseAnyRoomInterface::ChooseAnyRoomInterface(Hotel *hotel, int type) : Interface(hotel) {
    this -> lines = {
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••\n"
            "                          -=- Hotel Manament System: Résultat pour la suite <roomType> -=-\n",
            "",
    };
    this -> type = type;
}


void ChooseAnyRoomInterface::checkAnswer(string answer) {
    vector<string> options;
    int i = 0;
    for(Room* r : found) {
        options.push_back(to_string(i));
        i++;
    }
    if (!isValidOption(options,answer)) {
        sendAvailableOptions(options);
        return;
    }

    Room* room = &hotel->getRooms()[stoi(answer)];
    if(customer) {
        CreateRegistrationInterface interface = CreateRegistrationInterface(hotel, customer, room);
        interface.display();
    } else {
        if(hotel->hasCurrentRegistration(room)) {
            int i;
            for(Registration r : hotel->getRegistrations()) {
                if(r.getRoom()->getRoomID() == room->getRoomID()) {
                    i = r.getID();
                }
            }
            RegistrationRoomFoundInterface(hotel,i).display();
        } else {
            NoRegistrationRoomInterface(hotel).display();
        }

    }

}

void ChooseAnyRoomInterface::display() {
    string roomName = hotel->getRoomName(type);

    map<string, string> m = {
            {"<roomType>", roomName}};
    replaceTags(m);

    int i = 0;

    for(Room r : hotel->getRooms()) {
        if(r.getRoomType() == type) {
            if(r.getRoomState() == RoomState::EMPTY or !customer) {


                lines.push_back("       (" + to_string(i) + ")"
                                + " | ID: " + to_string(r.getRoomNumber())
                                + " | Numéro: " + to_string(r.getRoomNumber())
                                + " | Étage: " + to_string(r.getFloor())
                                + " | Nbr de personnes: " + to_string(r.getAmount())
                                + " | Prix: " + to_string(r.getPrice()) + " euros");
                found.push_back(&r);
                i++;
            }
        }
    }

    lines.push_back("");
    lines.push_back("      Sélectionnez une chambre: ");



    Interface::display();
}

void ChooseAnyRoomInterface::setCustomer(Customer *customer) {
    this -> customer = customer;
}