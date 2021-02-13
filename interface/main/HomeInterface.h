//
// Created by prodigy on 17/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_HOMEINTERFACE_H
#define HOTELMANAGEMENTSYSTEM_HOMEINTERFACE_H


#include "../Interface.h"

class HomeInterface : public Interface {


public:

    HomeInterface(Hotel *hotel);

    void display();

    void checkAnswer(string answer);


};


#endif //HOTELMANAGEMENTSYSTEM_HOMEINTERFACE_H
