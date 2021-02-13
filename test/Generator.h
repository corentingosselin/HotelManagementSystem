//
// Created by prodigy on 23/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_GENERATOR_H
#define HOTELMANAGEMENTSYSTEM_GENERATOR_H


#include "../hotel/Hotel.h"

class Generator {

public:
    Generator(Hotel *hotel) : hotel(hotel) {
    }
    void generate();

protected:
    Hotel* hotel;



};


#endif //HOTELMANAGEMENTSYSTEM_GENERATOR_H
