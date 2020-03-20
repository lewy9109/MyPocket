//
//  MetodyPomocnicze.hpp
//  ksiazka wlasna obiektowo
//
//  Created by Krystian Lewandowski on 27/02/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#ifndef HelpfullMetods_HPP
#define HelpfullMetods_HPP

#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class HelpfullMetods
{
public:
    static string convertIntToString(int number);
    static int convertStringToInt(string number);
    
    string wczytajLinie();
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string text);
    string pobierzLiczbe(string text, int pozycjaZnaku);
    int wczytajLiczbeCalkowita();
    char wczytajZnak();
    
};
#endif /* MetodyPomocnicze_hpp */
