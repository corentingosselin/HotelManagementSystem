//
// Created by prodigy on 19/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_CREATECUSTOMERINTERFACE_H
#define HOTELMANAGEMENTSYSTEM_CREATECUSTOMERINTERFACE_H


#include "../Interface.h"

class CreateCustomerInterface: public Interface {


public:
    CreateCustomerInterface(Hotel *hotel);
    void nextQuestion();
    void checkAnswer(string answer);
    void display();


private:
    int currentQuestion = 0;
    string questions[7] {
            "Indiquez le genre (homme/femme):",
            "Indiquez un prénom:",
            "Indiquez un nom:",
            "Indiquez une date de naissance:",
            "Indiquez la ville de résidence:",
            "Indiquez le numéro et rue de résidence:",
            "Indiquez un numéro de téléphone:"
    };
    Customer tempCustomer;
    string input;


protected:
    Gender getValidGender(string gender);
    void buildCustomer();

    void displayCustomerSummary();
};


#endif //HOTELMANAGEMENTSYSTEM_CREATECUSTOMERINTERFACE_H
