//
// Created by prodigy on 26/12/2020.
//

#include <boost/algorithm/string.hpp>
#include "DateActivityInterface.h"
#include "ActivityRegistrationInterface.h"

DateActivityInterface::DateActivityInterface(Hotel *hotel, Registration *registration) : Interface(hotel) {
    this -> lines = {
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••",
            "                          -=- Hotel Manament System: Date de réservation -=-",
            "",
            "",
            "                Entrez une date pour laquelle vous souhaitez réserver l'activité:",
            "",
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••"
    };

    this -> registration = registration;

}

void DateActivityInterface::checkAnswer(string answer) {
    Date date;
    while (date.day == 0 or date.month == 0 or date.year == 0) {
        vector<string> strs;
        boost::split(strs, answer, boost::is_any_of("/"));
        if (strs.size() == 3) {
            int day = atoi(strs[0].c_str());
            int month = atoi(strs[1].c_str());
            int year = atoi(strs[2].c_str());
            date.day = day;
            date.month = month;
            date.year = year;
        } else {
            cout << "La date saisie est incorrecte (d/m/yyyy): " << endl;
            cin >> answer;
        }
    }

    ActivityRegistrationInterface(hotel,registration,date).display();

}
