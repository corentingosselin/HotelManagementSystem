//
// Created by Nathan on 17/12/2020.
//

#include "Customer.h"
#include <boost/algorithm/string.hpp>
#include <boost/date_time.hpp>



/**
 * Setters
 */
Customer& Customer::setName(string name){
    boost::algorithm::to_lower(name);
    this -> name = name;
    return *this;
}

Customer& Customer::setPhone(string phone) {
    this -> phone = phone;
    return *this;
}

Customer& Customer::setGender(Gender gender) {
    this -> gender = gender;
    return *this;
}

Customer& Customer::setFirstname(string firstName) {
    boost::algorithm::to_lower(firstName);
    this -> firstName = firstName;
    return *this;
}

Customer & Customer::setBirth(Date birth) {
    this -> birth = birth;
    boost::posix_time::ptime timeLocal = boost::posix_time::second_clock::local_time();
    this -> age = timeLocal.date().year() - birth.year;
    return *this;
}

Customer & Customer::setCity(string city) {
    this -> city = city;
    return *this;
}
Customer & Customer::setAddress(string address) {
    this ->  street = address;
    return *this;
}


Customer & Customer::setID(int id) {
    this ->  id = id;
    return *this;
}

Customer & Customer::setState(CustomerState state) {
    this ->  state = state;
    return *this;
}


/**
 * Getters
 */

string Customer::getFirstname() {
    return firstName;
}

string Customer::getPhone(){

    return phone;
}

int Customer::getAge() {
    return age;
}

Gender Customer::getGender()  {
    return gender;
}

string Customer::getName(){
    return name;
}

Date Customer::getBirth() {
    return birth;
}

int Customer::getID() {
    return id;
}

string Customer::getAddress() {
    return street;
}

string Customer::getCity() {
    return city;
}

CustomerState Customer::getState() {
    return state;
}

string Customer::getStateStringify() {
    if(state == CustomerState::COMING) {
        return "En cours";
    } else if(state == CustomerState::REGISTERED) {
        return "Enregistré";
    } else {
        return "Aucun";
    }
}

string Customer::getGenderStringify() {
    if(gender == Gender::MALE) {
        return "Homme";
    } else if(gender == Gender::FEMALE) {
        return "Femme";
    } else {
        return "Non connu";
    }
}

string Customer::getDateStringify() {
    return to_string(birth.day) + "/" + to_string(birth.month) + "/" + to_string(birth.year);
}

int Customer::getVisits() {
    return visits;
}



