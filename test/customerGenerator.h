//
// Created by prodigy on 16/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_CUSTOMERGENERATOR_H
#define HOTELMANAGEMENTSYSTEM_CUSTOMERGENERATOR_H


#include "Generator.h"

class customerGenerator : Generator {
public:
    customerGenerator(Hotel *hotel);
    void generate();


};


#endif //HOTELMANAGEMENTSYSTEM_CUSTOMERGENERATOR_H
