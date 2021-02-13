//
// Created by prodigy on 16/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_HOTEL_H
#define HOTELMANAGEMENTSYSTEM_HOTEL_H


#include <vector>
#include "customer/Customer.h"
#include "room/Room.h"
#include "transport/Transport.h"
#include "transport/transports/Helicopter.h"
#include "transport/transports/HotelCar.h"
#include "transport/transports/Limousine.h"
#include "transport/transports/Taxi.h"
#include "transport/transports/PrivateCar.h"
#include "activity/Activity.h"
#include "activity/sport/Yoga.h"
#include "activity/sport/Tennis.h"
#include "activity/sport/Golf.h"
#include "activity/sport/Fitness.h"
#include "activity/healthcare/Spa.h"
#include "activity/healthcare/Massage.h"
#include "activity/healthcare/FaceCare.h"
#include "activity/entertainment/Theater.h"
#include "activity/entertainment/Oenology.h"
#include "activity/entertainment/SwimingPool.h"
#include "activity/entertainment/Museum.h"
#include "activity/entertainment/Cinema.h"
#include "activity/entertainment/Casino.h"
#include "iostream"
#include "registration/Registration.h"
#include "activity/register/RegistrationActivity.h"
#include "service/room/RomanticOption.h"
#include "service/room/RoomService.h"
#include "service/rental/Bike.h"
#include "service/rental/Computer.h"
#include "service/rental/Scooter.h"
#include "service/event/Birthday.h"
#include "service/event/Weeding.h"
#include "service/other/Parking.h"
#include "service/restaurant/Breakfast.h"
#include "service/restaurant/Lunch.h"
#include "service/restaurant/Diner.h"

class Hotel {

public:
    Hotel();
    void registerCustomer(Customer customer);
    void registerRoom(Room room);
    Registration registerRegistration(Registration registration);
    void removeRegistration(Registration* registration);

    vector<Customer> getCustomers();
    vector<Room> getRooms();
    vector<Registration> getRegistrations();

    bool hasAnyRoomAvailable();
    bool hasCurrentRegistration(Customer* customer);
    bool hasCurrentRegistration(Room* room);
    Registration *getCurrentRegistration(Room *room);

    bool isArrived(Customer *customer);
    bool hasRoomTypeAvailable(int type);
    string getRoomName(int type);
    int getAvailableRoomAmount(int type);
    Transport* getTransportWay(int type);

    Activity* getActivity(int type);

    void addActivity(Registration* r, Activity* activity, Date date);
    bool isActivityFull(Customer* customer, Activity* activity, Date date);
    bool hasActivity(Registration* registration,Activity* activity, Date date);
    bool removeActivity(Registration* registration,Activity* activity, Date date);
    int getActivityCount(Activity *activity, Date date);

    vector<RegistrationActivity> getRegisteredActivities();
    vector<Service> getServices();


private:
    vector<Service> services {
        RomanticOption(),
        RoomService(),
        Bike(),
        Computer(),
        Scooter(),
        Birthday(),
        Weeding(),
        Parking(),

        Breakfast(),
        Lunch(),
        Diner()

    };
    vector<RegistrationActivity> activityRegistered;
    vector<Customer> customers;
    vector<Room> rooms;
    vector<Registration> registrations;
    Transport transportWays[5] = {
            Helicopter(),
            HotelCar(),
            Limousine(),
            PrivateCar(),
            Taxi()
    };

    Activity activities[13] = {
            Yoga(),
            Tennis(),
            Golf(),
            Fitness(),

            Spa(),
            Massage(),
            FaceCare(),

            Theater(),
            SwimingPool(),
            Oenology(),
            Museum(),
            Cinema(),
            Casino()
    };
};


#endif //HOTELMANAGEMENTSYSTEM_HOTEL_H
