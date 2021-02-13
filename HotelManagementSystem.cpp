#include "interface/main/HomeInterface.h"
#include "test/roomGenerator.h"
#include "test/customerGenerator.h"

void generateCustomer(Hotel hotel);

using namespace std;

int main() {

    Hotel hotel = Hotel();

    roomGenerator rg = roomGenerator(&hotel);
    rg.generate();

    Room* room_relax_0 = &hotel.getRooms()[0];
    Room* room_presidential_last = &hotel.getRooms()[29];
    Room* room_chic_first = &hotel.getRooms()[10];


    Customer c = Customer().setFirstname("Nathan").setName("Cucheval")
            .setBirth(Date {23,12,2000})
            .setGender(Gender::MALE)
            .setAddress("36 rue des picasso")
            .setCity("Lille")
            .setPhone("0678345566");
    hotel.registerCustomer(c);


    Registration r = Registration(&c);
    r.setRoom(room_relax_0);
    r.setDayDuration(10);
    r.setStart(Date{10,1,2021});
    r.setCustomer(&c);
    r.addService(1);
    r.addService(2);
    hotel.registerRegistration(r);
    hotel.addActivity(&hotel.getRegistrations()[0],
                      hotel.getActivity(5),
                      Date{11,1,2021});





    Customer c2 = Customer().setFirstname("Corentin").setName("Gosselin")
            .setBirth(Date {23,12,1998})
            .setGender(Gender::MALE)
            .setAddress("3 avenue des historilis")
            .setCity("Cambrai")
            .setPhone("0633776522");
    hotel.registerCustomer(c2);


    Registration r2 = Registration(&c2);
    r2.setRoom(room_presidential_last);
    r2.setDayDuration(5);
    r2.setStart(Date{10,2,2021});
    r2.setCustomer(&c2);
    r2.addService(1);
    r2.addService(2);
    r2.addService(3);
    r2.addService(7);
    r2.setTransport(hotel.getTransportWay(3));
    hotel.registerRegistration(r2);

    hotel.addActivity(&hotel.getRegistrations()[1],
                      hotel.getActivity(1),
                      Date{12,2,2021});
    hotel.addActivity(&hotel.getRegistrations()[1],
                      hotel.getActivity(7),
                      Date{13,2,2021});


    Customer c3 = Customer().setFirstname("Mohamed").setName("Amine")
            .setBirth(Date {2,3,2000})
            .setGender(Gender::MALE)
            .setAddress("2 rue bis des follies")
            .setCity("Fâche")
            .setPhone("0655243377");
    hotel.registerCustomer(c3);


    Customer c4 = Customer().setFirstname("Jacqueline").setName("Ducamp")
            .setBirth(Date {12,10,1990})
            .setGender(Gender::FEMALE)
            .setAddress("33 boulevard hugo")
            .setCity("Paris")
            .setPhone("0655875643");
    hotel.registerCustomer(c4);

    Registration r3 = Registration(&c4);
    r3.setRoom(room_chic_first);
    r3.setDayDuration(14);
    r3.setStart(Date{22,1,2021});
    r3.setCustomer(&c4);
    r3.addService(0);
    r3.addService(4);
    r3.addService(5);
    r3.addService(7);
    r3.setTransport(hotel.getTransportWay(5));
    hotel.registerRegistration(r3);

    hotel.addActivity(&hotel.getRegistrations()[2],
                      hotel.getActivity(5),
                      Date{23,1,2021});
    hotel.addActivity(&hotel.getRegistrations()[2],
                      hotel.getActivity(4),
                      Date{22,1,2021});


    Customer c5 = Customer().setFirstname("Josiane").setName("Permude")
            .setBirth(Date {31,8,1956})
            .setGender(Gender::FEMALE)
            .setAddress("53 avenue des fleurs")
            .setCity("Lyon")
            .setPhone("0677324566");
    hotel.registerCustomer(c5);


    Customer c6 = Customer().setFirstname("Michel").setName("Lelouche")
            .setBirth(Date {4,4,1977})
            .setGender(Gender::MALE)
            .setAddress("22 avenue des cycomores")
            .setCity("Caen")
            .setPhone("0687121099");
    hotel.registerCustomer(c6);


    HomeInterface i = HomeInterface(&hotel);
    i.display();

    return 0;
}

void generateCustomer(Hotel hotel) {

}


