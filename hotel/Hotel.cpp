//
// Created by prodigy on 16/12/2020.
//

#include <map>
#include "Hotel.h"
#include "activity/register/RegistrationActivity.h"

Hotel::Hotel() {
}

vector<Customer> Hotel::getCustomers() {
    return this -> customers;
}

vector<Room> Hotel::getRooms() {
    return rooms;
}

void Hotel::registerCustomer(Customer customer) {
    customer.setID(customers.size());
    customers.push_back(customer);
}

void Hotel::registerRoom(Room room) {
    room.setID(rooms.size());
    rooms.push_back(room);
}

string Hotel::getRoomName(int type) {
    string roomName = "";
    if(type == 0) roomName = "Relax";
    else if(type == 1) roomName = "Excentrique";
    else if(type == 2) roomName = "Glamour";
    else if(type == 3) roomName = "Chic";
    else if(type == 4) roomName = "Présidentielle";
    return roomName;
}

bool Hotel::hasAnyRoomAvailable() {
    for(Room r : rooms) {
        if(r.getRoomState() == RoomState::EMPTY)
            return true;
    }
    return false;
}

int Hotel::getAvailableRoomAmount(int type) {
    int count = 0;
    for(Room r : rooms) {
        if (r.getRoomType() == type and r.getRoomState() == RoomState::EMPTY) {
            count++;
        }
    }
    return count;
}

bool Hotel::hasRoomTypeAvailable(int type) {
    for(Room r : rooms) {
        if(r.getRoomType() == type and r.getRoomState() == RoomState::EMPTY) {
            return true;
        }
    }
    return false;
}

Activity * Hotel::getActivity(int type) {
    return &activities[type];
}

Transport* Hotel::getTransportWay(int type) {
    return &transportWays[type];
}

Registration Hotel::registerRegistration(Registration registration) {
    registration.setState(CustomerState::COMING);
    registration.getCustomer()->setState(CustomerState::COMING);
    registrations.push_back(registration);
    registration.setID(registrations.size());
    return registration;
}

void Hotel::removeRegistration(Registration *registration) {
    int i = 0;
    for(Registration r : registrations) {
        if(&r == registration) {
            registration->getCustomer()->setState(CustomerState::NONE);
            registration->getRoom()->setRoomState(RoomState::EMPTY);
            registrations.erase(registrations.begin() + i);
        }
        i++;
    }
}

vector<Registration> Hotel::getRegistrations() {
    return registrations;
}

bool Hotel::hasCurrentRegistration(Customer *customer) {
    for(Registration r : registrations) {
        if(r.getCustomer()->getID() == customer->getID()) {
            return true;
        }
    }
    return false;
}

bool Hotel::hasCurrentRegistration(Room *room) {
    for(Registration r : registrations) {
        if(r.getRoom()->getRoomID() == room->getRoomID()) {
            return true;
        }
    }
    return false;
}

void Hotel::addActivity(Registration* r, Activity* activity, Date date) {
    activityRegistered.push_back(RegistrationActivity(r,activity,date));
}


vector<Service> Hotel::getServices() {
    return services;
}

bool Hotel::isActivityFull(Customer* customer, Activity *activity, Date date) {
    int count = 0;
    for(RegistrationActivity ra : activityRegistered) {
        if(ra.getRegistration()->getCustomer() != customer) {
            if (ra.getActivity() == activity) {
                if (date.year == ra.getDate().year and date.month == ra.getDate().month and
                    date.day == ra.getDate().day) {
                    count++;
                }
            }
        }
    }
    return count >= activity->getMaxRegistrations();
}

int Hotel::getActivityCount(Activity *activity, Date date) {
    int count = 0;
    for(RegistrationActivity ra : activityRegistered) {
        if (ra.getActivity() == activity) {
            if (date.year == ra.getDate().year and date.month == ra.getDate().month and date.day == ra.getDate().day) {
                count++;
            }
        }
    }
    return count;
}

bool Hotel::hasActivity(Registration *registration, Activity* activity, Date date) {
    for(RegistrationActivity ra : activityRegistered) {
        if(ra.getRegistration()->getID() == registration->getID()) {
            if(ra.getActivity() == activity) {
                if (date.year == ra.getDate().year and date.month == ra.getDate().month and
                    date.day == ra.getDate().day) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Hotel::removeActivity(Registration *registration, Activity *activity, Date date) {
    int i = 0;
    for(RegistrationActivity ra : activityRegistered) {
        if(ra.getRegistration() == registration) {
            if(ra.getActivity() == activity) {
                if (date.year == ra.getDate().year and date.month == ra.getDate().month and date.day == ra.getDate().day) {
                    activityRegistered.erase(activityRegistered.begin() + i);
                }
            }
        }
        i++;
    }
}

vector<RegistrationActivity> Hotel::getRegisteredActivities() {
    return activityRegistered;
}



