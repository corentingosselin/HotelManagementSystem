//
// Created by prodigy on 16/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_ROOM_H
#define HOTELMANAGEMENTSYSTEM_ROOM_H
#include "string"
#include "../../constants/RoomState.h"

using namespace std;

class Room {

public:
    Room() {
    }

    Room& setAmount(int amount);
    Room& setPrice(int price);
    int getAmount();
    Room& setLocation(int floor, int roomNumber);
    void setRoomState(RoomState roomState);
    int getFloor();
    int getRoomNumber();
    int getRoomID();
    int getPrice();
    string getDisplayName();
    RoomState getRoomState();

    int getRoomType();
    void setID(int ID);

protected:
    int roomType;
    int roomID;
    int roomNumber;
    int floorNumber;
    int amount;
    int price;
    string displayName;
    RoomState roomState = RoomState::EMPTY;


};


#endif //HOTELMANAGEMENTSYSTEM_ROOM_H
