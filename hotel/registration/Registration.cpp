//
// Created by prodigy on 16/12/2020.
//

#include "Registration.h"


Registration::Registration(Customer *customer) {
    this -> customer = customer;
}

/**
 * Setters
 */

void Registration::setCustomer(Customer *customer) {
    this -> customer = customer;
}

void Registration::setDayDuration(int duration) {
    this -> days = duration;
}

void Registration::setStart(Date date) {
    this -> startDate = date;
}

void Registration::setRoom(Room* room) {
    this -> room = room;
}

void Registration::setState(CustomerState state) {
    this -> state = state;
}

void Registration::setTransport(Transport *transport) {
    this -> transport = transport;
}

void Registration::addService(int i) {
    services.push_back(i);
}

/**
 * Getters
 */
CustomerState Registration::getState() {
    return state;
}

Customer* Registration::getCustomer() {
    return customer;
}

Room* Registration::getRoom() {
    return room;
}

int Registration::getDayDuration() {
    return days;
}

Date Registration::getStartDate() {
    return startDate;
}


Transport * Registration::getTransport() {
    return transport;
}


void Registration::setID(int id) {
    this -> id = id;
}

int Registration::getID() {
    return id;
}

vector<int> Registration::getServices() {
    return services;
}

bool Registration::hasService(int i) {
    return find(services.begin(), services.end(), i) != services.end();
}


void Registration::removeService(int i) {
    services.erase (services.begin()+i);
}
