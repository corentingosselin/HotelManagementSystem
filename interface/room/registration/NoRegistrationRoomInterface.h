//
// Created by prodigy on 26/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_NOREGISTRATIONROOMINTERFACE_H
#define HOTELMANAGEMENTSYSTEM_NOREGISTRATIONROOMINTERFACE_H


#include "../../../hotel/Hotel.h"
#include "../../Interface.h"

class NoRegistrationRoomInterface : public Interface {


public:

    NoRegistrationRoomInterface(Hotel *hotel);
    void checkAnswer(string answer);


};



#endif //HOTELMANAGEMENTSYSTEM_NOREGISTRATIONROOMINTERFACE_H
