//
// Created by prodigy on 18/12/2020.
//

#ifndef HOTELMANAGEMENTSYSTEM_DATE_H
#define HOTELMANAGEMENTSYSTEM_DATE_H

using namespace std;

struct Date {
    int day = 0;
    int month = 0;
    int year = 0;

    string stringify() {
        return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
    }

};
#endif //HOTELMANAGEMENTSYSTEM_DATE_H
