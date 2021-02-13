//
// Created by prodigy on 16/12/2020.
//

#include <regex>
#include "Interface.h"


void Interface::display() {
    if(lines.empty()) return;
    for(int i= 0; i < 50; i++) {
        cout << "" << endl;
    }

    for(vector<string>::iterator it=lines.begin(); it!=lines.end(); ++it)
    {
        cout << *it << endl;
    }

    for(int i= 0; i < 5; i++) {
        cout << "" << endl;
    }

    waitingForAnswer();
}


void Interface::waitingForAnswer() {
    string value;
    cin >> value;
    checkAnswer(value);
}

void Interface::checkAnswer(string answer) {
}

void Interface::sendAvailableOptions(vector<string>& options) {
    cout << "Veuillez sélectionner l'une des options suivantes: ";
    for(int i=0; i < options.size(); i++)
        cout << options.at(i) << ' ';
    cout << endl;
    waitingForAnswer();
}

void Interface::replaceTag(string tag, string data) {
    for (string& line : lines) {
        if(line.find(tag)) {
            string newData = std::regex_replace(line, regex(tag), data);
            line = newData;
        }
    }
}

void Interface::replaceTags(map<string,string> args) {
    for (string& line : lines) {
        for (auto const& x : args) {
            if (line.find(x.first)) {
                string newData = std::regex_replace(line, regex(x.first), x.second);
                line = newData;
            }
        }
    }
}
