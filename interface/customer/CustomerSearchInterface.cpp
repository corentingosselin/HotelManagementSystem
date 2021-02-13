//
// Created by prodigy on 18/12/2020.
//

#include "CustomerSearchInterface.h"
#include "CustomerNotFoundInterface.h"
#include "CustomersFoundInterface.h"

CustomerSearchInterface::CustomerSearchInterface(Hotel *hotel) : Interface(hotel) {
    this -> lines = {
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••",
            "                          -=- Hotel Manament System: Recherche clientèle -=-",
            "",
            "",
            "          Entrez un nom, prénom, téléphone ou identifiant:",
            "",
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••"
    };

}

void CustomerSearchInterface::checkAnswer(string answer) {
    vector<Customer> customers = hotel->getCustomers();
    bool found = false;
    for (int i = 0; i<customers.size();i++) {
        Customer customer = customers[i];
        if (customer.getName() == answer
            or customer.getFirstname() == answer
            or customer.getPhone() == answer) {
            found = true;
        }
    }

    if(found) {
        CustomersFoundInterface(hotel,answer).display();
    } else {
        CustomerNotFoundInterface(hotel).display();
    }

}
