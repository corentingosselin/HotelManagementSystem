//
// Created by prodigy on 22/12/2020.
//

#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include "CreateRegistrationInterface.h"
#include "../main/HomeInterface.h"
#include "ActivityOrServiceInterface.h"

CreateRegistrationInterface::CreateRegistrationInterface(Hotel *hotel, Customer* customer, Room* room) : customer(customer), Interface(hotel) {
    this -> lines = {
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••",
            "                          -=- Hotel Manament System: Création d'un séjour -=-",
            ""
    };
    lines[2] = questions[0];
    this -> customer = customer;
    tempRegistration.setRoom(room);
    //include room service by default
    tempRegistration.addService(1);
}



void CreateRegistrationInterface::buildRegistration() {
    if(currentQuestion == 0) {
        Date date;
        while (date.day == 0 or date.month == 0 or date.year == 0) {
            cin >> input;
            vector<string> strs;
            boost::split(strs, input, boost::is_any_of("/"));
            if (strs.size() == 3) {
                int day = atoi(strs[0].c_str());
                int month = atoi(strs[1].c_str());
                int year = atoi(strs[2].c_str());
                date.day = day;
                date.month = month;
                date.year = year;
            } else {
                cout << "La date saisie est incorrecte (d/m/yyyy): ";
            }
        }
        tempRegistration.setStart(date);
    } else if(currentQuestion == 1) {
        cin >> input;
        tempRegistration.setDayDuration(std::stoi(input));
    } else if(currentQuestion == 2) {
        string transport = " ";
        while(transport == " ") {
            cin >> input;
            if(input == "aucun" or input == "") {
                break;
            }
            else if(input == "taxi") {
                tempRegistration.setTransport(hotel->getTransportWay(4));
                break;

            } else if(input == "limousine") {
                tempRegistration.setTransport(hotel->getTransportWay(2));
                break;

            } else if(input == "voiture_priv") {
                tempRegistration.setTransport(hotel->getTransportWay(3));
                break;

            } else if(input == "voiture_hotel") {
                tempRegistration.setTransport(hotel->getTransportWay(1));
                break;

            } else if(input == "helico") {
                tempRegistration.setTransport(hotel->getTransportWay(0));
                break;

            } else {
                input = "";
                cout << "       Le type de transport que vous avez saisi est invalide" << endl;
                cout << "           (aucun, taxi, limousine, voiture_hotel, voiture_priv, helico): " << endl;
                transport = " ";
            }

        }
    } else if(currentQuestion == 3) {
        string answer = " ";
        while(answer == " ") {
            cin >> input;
            if(input == "non" or input == "") {
                break;
            } else if(input == "oui") {
                tempRegistration.addService(0);
            } else {
                cout << "       Veuillez préciser oui ou non: "    << endl;
                answer = " ";
            }
        }
    }

    if(currentQuestion > 4 or (currentQuestion == 2 and room->getAmount() >= 2))  {
        displayRegistrationSummary();
        return;
    }

    nextQuestion();
}

void CreateRegistrationInterface::displayRegistrationSummary() {
    for(int i= 0; i < 50; i++) {
        cout << "" << endl;
    }
    string display[13] = {
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••",
            "                                -=- Hotel Manament System: Séjour -=-",
            "",
            "                  " + customer->getName() + " " + customer->getFirstname() + ":",
            "",
            "                      Date d'arrivée: " + tempRegistration.getStartDate().stringify(),
            "                      Durée du séjour: " + to_string(tempRegistration.getDayDuration()) + " jour(s)",
            "                      Transport: " + tempRegistration.getTransport()->getDisplayName(),
            "",
            "                   Veuillez sélectionner une option: ",
            "",
            "                                   - (1) Confirmer",
            "                                   - (2) Retour"

    };

    for(int i = 0; i < 13; i++) {
        cout << display[i] << endl;
    }

    waitingForAnswer();
}

void CreateRegistrationInterface::checkAnswer(string answer) {
    vector<string> options { "1", "2","confirmer","retour", "c", "r"};
    if (!isValidOption(options,answer)) {
        sendAvailableOptions(options);
        return;
    }
    if(answer == "1" or answer == "confirmer" or answer == "c") {
        Registration r = hotel->registerRegistration(tempRegistration);
        r.setState(CustomerState::COMING);
        r.setState(CustomerState::REGISTERED);

        ActivityOrServiceInterface i = ActivityOrServiceInterface(hotel,&r);
        i.display();

    } else if(answer == "2" or answer == "retour" or answer == "r") {
        HomeInterface i = HomeInterface(hotel);
        i.display();
    }

}

void CreateRegistrationInterface::nextQuestion() {
    currentQuestion++;
    lines[2] = questions[currentQuestion];
    display();
}

void CreateRegistrationInterface::display() {
    if(lines.empty()) return;
    for(int i= 0; i < 50; i++) {
        cout << "" << endl;
    }
    for(vector<string>::iterator it=lines.begin(); it!=lines.end(); ++it)
    {
        cout << *it << endl;
    }
    for(int i= 0; i < 5; i++) {
        cout << "" << endl;
    }

    buildRegistration();
}
