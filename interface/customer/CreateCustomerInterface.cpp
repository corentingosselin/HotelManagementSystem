//
// Created by prodigy on 19/12/2020.
//

#include "CreateCustomerInterface.h"
#include "../../hotel/Hotel.h"
#include "../main/HomeInterface.h"
#include "../registration/ConfirmNewRegistrationInterface.h"
#include <boost/algorithm/string.hpp>



CreateCustomerInterface::CreateCustomerInterface(Hotel *hotel) : Interface(hotel) {
    this -> lines = {
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••",
            "                          -=- Hotel Manament System: Création d'un utilisateur -=-",
            ""
    };
    tempCustomer = Customer();
    lines[2] = questions[0];
}


Gender CreateCustomerInterface::getValidGender(string gender) {
    if (gender == "homme" or gender == "h") {
        return Gender::MALE;
    } else if (gender == "femme" or gender == "f") {
        return Gender::FEMALE;
    }
    cout << "Veuillez indiquez un sexe: homme ou femme" << endl;
    return Gender::UNKNOW;
}

void CreateCustomerInterface::buildCustomer() {


    if(currentQuestion == 0) {
        Gender g = Gender::UNKNOW;
        while (g == Gender::UNKNOW) {
            cin >> input;
            g = getValidGender(input);
        }
        tempCustomer.setGender(g);
    } else if(currentQuestion == 1) {
        string surname = "";
        cin >> surname;
        tempCustomer.setFirstname(surname);
    } else if(currentQuestion == 2) {
        string name = "";
        cin >> name;
        tempCustomer.setName(name);
    } else if(currentQuestion == 3) {
        Date date;
        while (date.day == 0 or date.month == 0 or date.year == 0) {
            string dateInput;
            cin >> dateInput;
            vector<string> strs;
            boost::split(strs, dateInput, boost::is_any_of("/"));
            if (strs.size() == 3) {
                int day = atoi(strs[0].c_str());
                int month = atoi(strs[1].c_str());
                int year = atoi(strs[2].c_str());
                date.day = day;
                date.month = month;
                date.year = year;
                tempCustomer.setBirth(date);
            }
        }
    } else if(currentQuestion == 4) {
        string city = "";
        cin >> city;
        tempCustomer.setCity(city);
    } else if(currentQuestion == 5) {
        string address = "";
        cin.ignore();
        getline(cin, address);
        tempCustomer.setAddress(address);
    } else if(currentQuestion == 6) {
        string phone = "";
        cin >> phone;
        tempCustomer.setPhone(phone);
    }

    if(currentQuestion > 5)  {
        displayCustomerSummary();

        return;
    }

    nextQuestion();
}

void CreateCustomerInterface::displayCustomerSummary() {
    string display[15] = {
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••",
            "                                -=- Hotel Manament System: Fiche d'identité -=-",
            ""
            "                  " + tempCustomer.getName() + " " + tempCustomer.getFirstname() + ":",
            "",
            "                      Genre: " + tempCustomer.getGenderStringify(),
            "                      Age: " + to_string(tempCustomer.getAge()),
            "                      Date de naissance: " + tempCustomer.getDateStringify(),
            "                      Addresse: " + tempCustomer.getAddress() + ", " + tempCustomer.getCity(),
            "                      Téléphone: " + tempCustomer.getPhone(),
            "",
            "                   Veuillez sélectionner une option: ",
            "",
            "                                   - (1) Confirmer",
            "                                   - (2) Retour"
    };

    for(int i= 0; i < 50; i++) {
        cout << "" << endl;
    }
    for(int i = 0; i < 15; i++) {
        cout << display[i] << endl;
    }

    for(int i= 0; i < 5; i++) {
        cout << "" << endl;
    }

    waitingForAnswer();
}

void CreateCustomerInterface::checkAnswer(string answer) {
    vector<string> options { "1", "2","confirmer","retour", "c", "r"};
    if (!isValidOption(options,answer)) {
        sendAvailableOptions(options);
        return;
    }
    if(answer == "1" or answer == "confirmer" or answer == "c") {
        hotel->registerCustomer(tempCustomer);

        if(hotel->hasAnyRoomAvailable()) {
            ConfirmNewRegistrationInterface c = ConfirmNewRegistrationInterface(hotel, &tempCustomer);
            c.display();
        } else {
            HomeInterface i = HomeInterface(hotel);
            i.display();
        }

    } else if(answer == "2" or answer == "retour" or answer == "r") {
        HomeInterface i = HomeInterface(hotel);
        i.display();
    }

}

void CreateCustomerInterface::nextQuestion() {
    currentQuestion++;
    lines[2] = questions[currentQuestion];
    display();
}

void CreateCustomerInterface::display() {
    if(lines.empty()) return;
    for(int i= 0; i < 20; i++) {
        cout << "" << endl;
    }
    for(vector<string>::iterator it=lines.begin(); it!=lines.end(); ++it)
    {
        cout << *it << endl;
    }

    for(int i= 0; i < 5; i++) {
        cout << "" << endl;
    }

    buildCustomer();


}



