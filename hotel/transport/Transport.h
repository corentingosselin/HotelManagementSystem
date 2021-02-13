//
// Created by prodigy on 16/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_TRANSPORT_H
#define HOTELMANAGEMENTSYSTEM_TRANSPORT_H
#include "string"
using namespace std;
class Transport {

public:
    Transport();
    string getDisplayName();
    int getPriceKM();

protected:
    int pricePerKM;
    string displayName;


};


#endif //HOTELMANAGEMENTSYSTEM_TRANSPORT_H
