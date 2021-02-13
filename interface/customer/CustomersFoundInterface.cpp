//
// Created by prodigy on 25/12/2020.
//

#include "CustomersFoundInterface.h"

#include <utility>
#include "../main/HomeInterface.h"
#include "CreateCustomerInterface.h"
#include "CustomerIdentityInterface.h"

CustomersFoundInterface::CustomersFoundInterface(Hotel *hotel, string input) : Interface(hotel) {
    this -> input = std::move(input);


    this -> lines = {
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••",
            "                          -=- Hotel Manament System: Recherche client -=-",
            "",
            "            Résultat(s) de la recherche:",
            "",
            "                (1) Créer un nouveau client",
            "",
            "                  ID | Prénom | Nom | Ville"
    };
}

void CustomersFoundInterface::display() {

    vector<Customer> customers = hotel->getCustomers();
    int i = 2;
    for (int index = 0; index<customers.size();index++) {
        Customer c = customers[index];
        if (c.getName() == input
            or c.getFirstname() == input
            or c.getPhone() == input) {
            lines.push_back("               (" + to_string(i) + ") " + to_string(c.getID()) + " | " + c.getFirstname() + " | " + c.getName() + " | " + c.getCity());
            i++;

        }
    }

    lines.push_back("");
    lines.push_back("");
    lines.push_back("                  (" + to_string(i) + ") " + " retour");
    lines.push_back("");
    lines.push_back("");
    lines.push_back("       Sélectionner une des options: ");
    lines.push_back("");
    lines.push_back("••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••");

    Interface::display();
}



void CustomersFoundInterface::checkAnswer(string answer) {
    vector<string> options;
    map<string, int> selections;
    int i = 2;
    options.push_back("1");

    vector<Customer> customers = hotel->getCustomers();
    for (int index = 0; index<customers.size();index++) {
        Customer c = customers[index];
        if (c.getName() == input
            or c.getFirstname() == input
            or c.getPhone() == input) {
            options.push_back(to_string(i));
            selections.insert(pair<string,int>(to_string(i), index));
            i++;

        }
    }



    options.push_back(to_string(i));
    if (!isValidOption(options,answer)) {
        sendAvailableOptions(options);
        return;
    }


    if(answer == "1") {
        CreateCustomerInterface(hotel).display();
    } else if(answer == to_string(i)){
        HomeInterface(hotel).display();
    } else  {
        CustomerIdentityInterface(hotel,&customers[selections[answer]]).display();
    }
}

