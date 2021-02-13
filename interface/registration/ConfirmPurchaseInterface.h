//
// Created by prodigy on 04/01/2021.
//

#ifndef HOTELMANAGEMENTSYSTEM_CONFIRMPURCHASEINTERFACE_H
#define HOTELMANAGEMENTSYSTEM_CONFIRMPURCHASEINTERFACE_H


#include "../Interface.h"

class ConfirmPurchaseInterface : public Interface {

public:
    ConfirmPurchaseInterface(Hotel *hotel);
    void checkAnswer(string answer);
};



#endif //HOTELMANAGEMENTSYSTEM_CONFIRMPURCHASEINTERFACE_H
