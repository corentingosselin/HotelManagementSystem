//
// Created by prodigy on 23/12/2020.
//

#include "roomGenerator.h"
#include "../hotel/room/rooms/RelaxRoom.h"
#include "../hotel/room/rooms/ChicRoom.h"
#include "../hotel/room/rooms/GlamourRoom.h"
#include "../hotel/room/rooms/ExcentricRoom.h"
#include "../hotel/room/rooms/PresidentialRoom.h"

void roomGenerator::generate() {
    //floor 0
    hotel->registerRoom(RelaxRoom().setLocation(0,1).setAmount(1).setPrice(200));
    hotel->registerRoom(RelaxRoom().setLocation(0,2).setAmount(1).setPrice(200));
    hotel->registerRoom(RelaxRoom().setLocation(0,3).setAmount(1).setPrice(200));
    hotel->registerRoom(RelaxRoom().setLocation(0,4).setAmount(1).setPrice(200));
    hotel->registerRoom(RelaxRoom().setLocation(0,5).setAmount(1).setPrice(200));
    hotel->registerRoom(RelaxRoom().setLocation(0,6).setAmount(2).setPrice(300));
    hotel->registerRoom(RelaxRoom().setLocation(0,7).setAmount(2).setPrice(300));
    hotel->registerRoom(RelaxRoom().setLocation(0,8).setAmount(2).setPrice(300));
    hotel->registerRoom(RelaxRoom().setLocation(0,9).setAmount(2).setPrice(300));
    hotel->registerRoom(RelaxRoom().setLocation(0,10).setAmount(2).setPrice(300));

    //floor 1
    hotel->registerRoom(ChicRoom().setLocation(1,1).setAmount(2).setPrice(400));
    hotel->registerRoom(ChicRoom().setLocation(1,2).setAmount(2).setPrice(400));
    hotel->registerRoom(ChicRoom().setLocation(1,3).setAmount(4).setPrice(550));
    hotel->registerRoom(ChicRoom().setLocation(1,4).setAmount(4).setPrice(550));
    hotel->registerRoom(ChicRoom().setLocation(1,5).setAmount(4).setPrice(550));
    hotel->registerRoom(GlamourRoom().setLocation(1,6).setAmount(2).setPrice(600));
    hotel->registerRoom(GlamourRoom().setLocation(1,7).setAmount(2).setPrice(600));
    hotel->registerRoom(GlamourRoom().setLocation(1,8).setAmount(2).setPrice(600));
    hotel->registerRoom(GlamourRoom().setLocation(1,9).setAmount(2).setPrice(600));
    hotel->registerRoom(GlamourRoom().setLocation(1,10).setAmount(2).setPrice(600));


    //floor 2
    hotel->registerRoom(ExcentricRoom().setLocation(2,1).setAmount(2).setPrice(800));
    hotel->registerRoom(ExcentricRoom().setLocation(2,2).setAmount(2).setPrice(800));
    hotel->registerRoom(ExcentricRoom().setLocation(2,3).setAmount(2).setPrice(800));
    hotel->registerRoom(ExcentricRoom().setLocation(2,4).setAmount(2).setPrice(800));
    hotel->registerRoom(ExcentricRoom().setLocation(2,5).setAmount(2).setPrice(800));
    hotel->registerRoom(ExcentricRoom().setLocation(2,6).setAmount(2).setPrice(800));
    hotel->registerRoom(ExcentricRoom().setLocation(2,7).setAmount(2).setPrice(800));
    hotel->registerRoom(PresidentialRoom().setLocation(2,8).setAmount(6).setPrice(1000));
    hotel->registerRoom(PresidentialRoom().setLocation(2,9).setAmount(6).setPrice(1000));
    hotel->registerRoom(PresidentialRoom().setLocation(2,10).setAmount(6).setPrice(1000));
//29
}

roomGenerator::roomGenerator(Hotel* hotel) : Generator(hotel){

}