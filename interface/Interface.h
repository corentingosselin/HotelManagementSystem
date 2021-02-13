//
// Created by prodigy on 16/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_INTERFACE_H
#define HOTELMANAGEMENTSYSTEM_INTERFACE_H

#include <vector>
#include "string"
#include "../hotel/Hotel.h"
#include <iostream>
#include "map"
#include <list>



using namespace std;

/***
 * Dev note:
 *
 *   Virtual keyword is used to allow override of the abstract function
 */

class Interface {


protected:
    Hotel *hotel;
    vector<string> lines;

    void replaceTag(string tag, string data);
    void replaceTags(map<string,string> args);

public:
    virtual void display();
    Interface(Hotel *hotel) : hotel(hotel) {
    }
    Interface * clone() { return new Interface(*this); }
    virtual void waitingForAnswer();
    virtual void checkAnswer(string answer);

    //display
    //output logic, handle info send by receptionist

    void sendAvailableOptions(vector<string>& options);
    bool isValidOption(vector<string>& options, string check) {
        return find(options.begin(), options.end(), check) != options.end();
    }

};


#endif //HOTELMANAGEMENTSYSTEM_INTERFACE_H
