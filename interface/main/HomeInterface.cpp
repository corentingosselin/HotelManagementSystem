//
// Created by prodigy on 17/12/2020.
//

#include "HomeInterface.h"
#include "../customer/CustomerSearchInterface.h"
#include "../room/SelectRoomTypeInterface.h"
#include <algorithm>


HomeInterface::HomeInterface(Hotel *hotel) : Interface(hotel) {
    this -> lines = {
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••",
            "",
            "|''||''| '||                                                       '||",
            "   ||     || ..     ....       ... . ... ..   ....   .. ...      .. ||",
            "   ||     ||' ||  .|...||     || ||   ||' '' '' .||   ||  ||   .'  '||",
            "   ||     ||  ||  ||           |''    ||     .|' ||   ||  ||   |.   ||",
            " . ||.   .||. ||.  '|...'     '||||. .||.    '|..'|' .||. ||.  '|..'||.",
            "                             .|....'",
            "",
            "'||                .           '||  ★★★★★",
            " || ..     ...   .||.    ....   ||                          Welcome mister HMS v0.1",
            " ||' ||  .|  '|.  ||   .|...||  ||                       support: support@gmail.com",
            " ||  ||  ||   ||  ||   ||       ||",
            ".||. ||.  '|..|'  '|.'  '|...' .||.",
            "",
            "",
            "",
            "                              -=- Hotel Manament System: Accueil -=-",
            "",
            "",
            "          Choisissez une option:",
            "",
            "",
            "                       - (1) Recherche de client",
            "",
            "                       - (2) Recherche de chambre",
            "",
            "",
            "          Statistiques globales:",
            "",
            "",
            "               Nombre de chambre reservées:  <amount>",
            "               Nombre de clients enregistrés:  <customers>",
            "               Nombre d'activités:  <activities> ",
            "               Nombre de services:  <services> ",
            "",
            "",
            "••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••"
    };

}


void HomeInterface::checkAnswer(string answer) {
    vector<string> options { "1", "2"};
    if (!isValidOption(options,answer)) {
        sendAvailableOptions(options);
        return;
    }
    if(answer == "1") {
        CustomerSearchInterface csi = CustomerSearchInterface(hotel);
        csi.display();
        //Open customer search engine
    } else if(answer == "2") {
        SelectRoomTypeInterface(hotel).display();

    }
}

void HomeInterface::display() {
    map<string, string> m = {
              {"<amount>", to_string(hotel->getRegistrations().size())}
            , {"<customers>", to_string(hotel->getCustomers().size())}
            , {"<activities>", to_string(13)}
            , {"<services>", to_string(hotel->getServices().size())}
    };
    replaceTags(m);
    Interface::display();
}