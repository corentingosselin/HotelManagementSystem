//
// Created by prodigy on 16/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_SERVICE_H
#define HOTELMANAGEMENTSYSTEM_SERVICE_H

#include "string"
using namespace std;

class Service {

public:
    Service();
    string getDisplayName();
    int getPrice();


protected:
    string displayName;
    int price;
};


#endif //HOTELMANAGEMENTSYSTEM_SERVICE_H
