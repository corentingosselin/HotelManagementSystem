//
// Created by Nathan on 17/12/2020.
//

#ifndef HOTEL_CUSTOMER_H
#define HOTEL_CUSTOMER_H
#include <string>
#include "../../constants/Gender.h"
#include "../../constants/Date.h"
#include "../../constants/CustomerState.h"

using namespace std;

class Customer {
public:
    Customer& setName(string);
    Customer& setPhone(string);
    Customer& setGender(Gender);
    Customer& setFirstname(string);
    Customer& setBirth(Date);
    Customer& setAddress(string address);
    Customer& setCity(string city);
    Customer& setID(int id);
    Customer& setState(CustomerState state);


    string getPhone();
    int getAge();
    int getKmDistance();

    int getID();
    string getName();
    Gender getGender();
    string getFirstname();
    Date getBirth();
    string getCity();
    string getAddress();
    CustomerState getState();
    string getStateStringify();
    string getDateStringify();
    string getGenderStringify();
    int getVisits();



private:
    int id = -1;
    string name, firstName, street, city, phone = "";
    int age, visits;
    Gender gender;
    Date birth;
    CustomerState state = CustomerState::NONE;

};



#endif //HOTEL_CUSTOMER_H
