//
// Created by prodigy on 04/01/2021.
//

#ifndef HOTELMANAGEMENTSYSTEM_WORKINGINPROGRESSINTERFACE_H
#define HOTELMANAGEMENTSYSTEM_WORKINGINPROGRESSINTERFACE_H


#include "../Interface.h"

class WorkingInProgressInterface : public Interface {

public:
    WorkingInProgressInterface(Hotel *hotel);
    void checkAnswer(string answer);

};



#endif //HOTELMANAGEMENTSYSTEM_WORKINGINPROGRESSINTERFACE_H
