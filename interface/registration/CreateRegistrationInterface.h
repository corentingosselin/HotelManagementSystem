//
// Created by prodigy on 22/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_CREATEREGISTRATIONINTERFACE_H
#define HOTELMANAGEMENTSYSTEM_CREATEREGISTRATIONINTERFACE_H


#include "../../hotel/registration/Registration.h"
#include "../Interface.h"

class CreateRegistrationInterface : Interface {

protected:
    Customer* customer;
    Room* room;
    void nextQuestion();

private:
    Registration tempRegistration = Registration(customer);
    int currentQuestion = 0;
    string questions[4] {
            "Indiquez la date d'arrivée:",
            "Indiquez la durée du séjour:",
            "Indiquez un moyen de transport pour se rendre à l'hotel (aucun, taxi, limousine, voiture_hotel, voiture_priv, helico):",
            //si amount room >= 2
            "Souhaitez-vous une option romantique de chambre ? (oui, non)",

    };
    string input;


public:
    CreateRegistrationInterface(Hotel *hotel, Customer* customer, Room* room);
    void checkAnswer(string answer);
    void display();


    void displayRegistrationSummary();

    void buildRegistration();

    Date getDate();
};


#endif //HOTELMANAGEMENTSYSTEM_CREATEREGISTRATIONINTERFACE_H
