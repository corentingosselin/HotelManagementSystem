//
// Created by prodigy on 26/12/2020.
//

#include "BillGenerationInterface.h"
#include "../main/HomeInterface.h"
#include "ConfirmPurchaseInterface.h"


BillGenerationInterface::BillGenerationInterface(Hotel *hotel, Registration *registration) : Interface(hotel) {
    this -> lines = {
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••",
            "                          -=- Hotel Manament System: Facture -=-",
            "",
            "            Client: <customer>",
            "",
            "",
            "                    date d'arrivée: <startDate>",
            "",
            "                    Tarifs des <duration> nuitées: <roomPrice>",
            "",
            "                    Services supplémentaires:",
            "",
            "                              <services>",
            "",
            "                              prix: <servicePrice>",
            "",
            "                    Activités supplémentaires:",
            "",
            "                              <activities>",
            "",
            "                              prix: <activityPrice>",
            "",
            "",
            "                    Distance hotel domicile: <distance>",
            "",
            "                    Transport: <transport>",
            "",
            "",
            "                Total: <total>",
            "",
            "                                                          (1) Paiement",
            "                                                          (2) Retourner au menu principal",
            "",
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••"
    };

    this -> registration = registration;

}


void BillGenerationInterface::display() {

    string activities = "";
    int activityPrice = 0;
    for(RegistrationActivity ra : hotel->getRegisteredActivities()) {
        if(ra.getRegistration()->getID() == registration->getID()) {
            activities = activities + + "- " + ra.getActivity()->getDisplayName() + " " + to_string(ra.getActivity()->getPrice()) + " euros \n                              ";
            activityPrice += ra.getActivity()->getPrice();
        }
    }
    if(activities == "") activities = "aucune";

    string services = "";
    int servicePrice = 0;
    for(int s : registration->getServices()) {
        Service service = hotel->getServices()[s];
        services = services + + "- " + service.getDisplayName() + " " + to_string(service.getPrice()) + " euros \n                              ";
        servicePrice += service.getPrice();
    }
    if(services == "") services = "aucun";


    int rKM = 5 + ( std::rand() % ( 5000 - 5 + 1 ) );

    int transportPrice = 0;
    string transport = "aucun";
    if(registration->getTransport() != nullptr) {
        transportPrice =  (registration->getTransport()->getPriceKM() * rKM);
        transport = registration->getTransport()->getDisplayName();
    }

    int nightsPrice = registration->getRoom()->getPrice() * (registration->getDayDuration() - 1);

    int total = servicePrice + activityPrice + nightsPrice + transportPrice;

    map<string, string> m = {
            {"<customer>", registration->getCustomer()->getName() + " " + registration->getCustomer()->getFirstname()},
            {"<startDate>", registration->getStartDate().stringify()},
            {"<duration>", to_string(registration->getDayDuration() - 1)},
            {"<activities>", activities},
            {"<services>",services},
            {"<servicePrice>",to_string(servicePrice)},
            {"<activityPrice>",to_string(activityPrice)},
            {"<roomPrice>", to_string(registration->getRoom()->getPrice() )},
            {"<distance>", to_string(rKM) + " kms"},
            {"<transport>", transport + " " + to_string(transportPrice) + " euros"},
            {"<total>", to_string(total) + " euros"}
    };


    replaceTags(m);
    Interface::display();

}

void BillGenerationInterface::checkAnswer(string answer) {
    vector<string> options { "1", "2"};
    if (!isValidOption(options,answer)) {
        sendAvailableOptions(options);
        return;
    }
    if(answer == "1") {
        ConfirmPurchaseInterface(hotel).display();
    } else if(answer == "2") {
       HomeInterface(hotel).display();
    }

}


