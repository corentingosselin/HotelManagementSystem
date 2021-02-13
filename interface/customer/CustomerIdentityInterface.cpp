//
// Created by prodigy on 25/12/2020.
//

#include "CustomerIdentityInterface.h"
#include "../main/HomeInterface.h"
#include "../registration/ConfirmNewRegistrationInterface.h"
#include "../notready/WorkingInProgressInterface.h"
#include "../registration/ModifyRegistrationInterface.h"

CustomerIdentityInterface::CustomerIdentityInterface(Hotel *hotel, Customer* customer) : Interface(hotel) {
    this -> lines = {
            "•••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••",
            "                          -=- Fiche d'identité -=-",
            "",
            "",
            "                  <surname> <name>:",
            "",
            "                      ID: <id>",
            "                      Genre: <gender>",
            "                      Age: <age>",
            "                      Date de naissance: <birth>",
            "                      Addresse: <street>, <city>",
            "                      Téléphone: <phone>",
            "                      Status du séjour: <status>",
            "",
            "                  Statistiques:",
            "",
            "                      Nombre de visite(s): <visit>",
            "",
            "                      Dernier séjour: (Aucun ou)",
            "                              - chambre louée: Glamour",
            "                              - position: 1èr étage chambre 6",
            "                              - durée du séjour: 10 jours",
            "",
            "",
            "",
            "              <registration>",
            "              (2) Modifier les coordonnées du client",
            "              (3) retour",
            "",
            "",
            "",
            "•••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••"
    };

            this -> customer = customer;


}

void CustomerIdentityInterface::checkAnswer(string answer) {
    vector<string> options { "1", "2","3"};
    if (!isValidOption(options,answer)) {
        sendAvailableOptions(options);
        return;
    }
    if(answer == "1") {
        if(isRegistered) {
            for (Registration r : hotel->getRegistrations()) {
                //id does not work, don't know why
                if (r.getCustomer()->getName() == customer->getName()
                    and r.getCustomer()->getFirstname() == customer->getFirstname()
                    and r.getCustomer()->getCity() == customer->getCity()) {
                    ModifyRegistrationInterface(hotel,&r).display();

                }
            }

        } else {
            ConfirmNewRegistrationInterface(hotel, customer).display();
        }
    } else if(answer == "2") {
        WorkingInProgressInterface(hotel).display();
    } else if(answer == "3") {
        HomeInterface(hotel).display();
    }

}

void CustomerIdentityInterface::display() {
    string registered = "Créer un nouveau séjour";
    string status = "Aucun";
    for(Registration r : hotel->getRegistrations()) {
        //id does not work, don't know why
        if(r.getCustomer()->getName() == customer->getName()
        and r.getCustomer()->getFirstname() == customer->getFirstname()
        and r.getCustomer()->getCity() == customer->getCity()) {
            registered = "Modifier le séjour en cours";
            status = "En cours";
            isRegistered = true;
        }
    }
    cout << " registered " << registered << endl;
    map<string, string> m = {
              {"<surname>", customer->getFirstname()}
            , {"<name>", customer->getName()}
            , {"<gender>", customer->getGenderStringify()}
            , {"<id>", to_string(customer->getID())}
            , {"<birth>", customer->getBirth().stringify()}
            , {"<street>", customer->getAddress()}
            , {"<city>", customer->getCity()}
            , {"<phone>", customer->getPhone()}
            , {"<status>", status}
            , {"<age>", to_string(customer->getAge())}
            , {"<visit>", to_string(customer->getVisits())}
            , {"<registration>", "(1) "
            + registered}

    };
    replaceTags(m);

    Interface::display();

}