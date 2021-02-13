//
// Created by prodigy on 16/12/2020.
//

#include "Room.h"


Room& Room::setAmount(int amount) {
    this -> amount = amount;
    return *this;
}

Room& Room::setLocation(int floor, int roomNumber) {
    this -> floorNumber = floor;
    this -> roomNumber = roomNumber;
    return *this;
}

Room& Room::setPrice(int price) {
    this -> price = price;
    return *this;
}

void Room::setID(int ID) {
    this -> roomID = ID;
}

void Room::setRoomState(RoomState roomState) {
    this ->roomState = roomState;
}

int Room::getRoomID() {
    return roomID;
}

int Room::getPrice() {
    return price;
}

int Room::getAmount() {
    return amount;
}

string Room::getDisplayName() {
    return displayName;
}

int Room::getFloor() {
    return floorNumber;
}

int Room::getRoomNumber() {
    return roomNumber;
}

int Room::getRoomType() {
    return roomType;
}

RoomState Room::getRoomState() {
    return roomState;
}

