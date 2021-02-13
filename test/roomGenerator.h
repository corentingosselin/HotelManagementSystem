//
// Created by prodigy on 23/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_ROOMGENERATOR_H
#define HOTELMANAGEMENTSYSTEM_ROOMGENERATOR_H


#include "../hotel/Hotel.h"
#include "Generator.h"

class roomGenerator : Generator {

public:
    roomGenerator(Hotel *hotel);
    void generate();

};


#endif //HOTELMANAGEMENTSYSTEM_ROOMGENERATOR_H
