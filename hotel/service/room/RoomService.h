//
// Created by prodigy on 16/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_ROOMSERVICE_H
#define HOTELMANAGEMENTSYSTEM_ROOMSERVICE_H


#include "../Service.h"

class RoomService : public Service {

public:
    RoomService();
    void orderFood(int cost);
};


#endif //HOTELMANAGEMENTSYSTEM_ROOMSERVICE_H
