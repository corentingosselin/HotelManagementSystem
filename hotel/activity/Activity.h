//
// Created by prodigy on 16/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_ACTIVITY_H
#define HOTELMANAGEMENTSYSTEM_ACTIVITY_H

#include "string"
using namespace std;

class Activity {

public:
    Activity();
    int getMaxRegistrations();
    string getDisplayName();
    int getPrice();


protected:
    int pricePerHour;
    int maximumRegistrations;
    string displayName;
};


#endif //HOTELMANAGEMENTSYSTEM_ACTIVITY_H
