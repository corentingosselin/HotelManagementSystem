//
// Created by prodigy on 16/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_REGISTRATION_H
#define HOTELMANAGEMENTSYSTEM_REGISTRATION_H


#include "vector"
#include "../customer/Customer.h"
#include "../service/Service.h"
#include "../transport/Transport.h"
#include "../room/Room.h"


using namespace std;

class Registration {

public:
    Registration(Customer *customer);

    //setters
    void setCustomer(Customer *customer);
    void setTransport(Transport *transport);
    void setRoom(Room* room);

    void setStart(Date date);
    void setDayDuration(int duration);
    void setState(CustomerState state);
    bool hasService(int i);
    void removeService(int i);

    //getters
    Customer* getCustomer();
    Transport* getTransport();
    Room* getRoom();

    Date getStartDate();
    int getDayDuration();
    CustomerState getState();

    void addService(int i);
    vector<int> getServices();

    int getID();
    void setID(int id);



protected:
    Customer *customer;
    Transport *transport;
    Room* room;

    Date startDate;
    int days;
    int id = 0;
    CustomerState state;

    vector<int> services;

};


#endif //HOTELMANAGEMENTSYSTEM_REGISTRATION_H
