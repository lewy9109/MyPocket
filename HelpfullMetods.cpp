//
//  MetodyPomocnicze.cpp
//  ksiazka wlasna obiektowo
//
//  Created by Krystian Lewandowski on 27/02/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#include "HelpfullMetods.hpp"

string HelpfullMetods::convertIntToString(int number)
{
    ostringstream ss;       
    ss << number;
    string str = ss.str();
    return str;
}

int HelpfullMetods::convertStringToInt(string number)
{
    int liczbaInt;
    istringstream iss(number);
    iss >> liczbaInt;
    return liczbaInt;
}
string HelpfullMetods::wczytajLinie()
{
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}
string HelpfullMetods::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

int HelpfullMetods::wczytajLiczbeCalkowita()
{
    string wejscie = "";
    int liczba = 0;

    while (true)
    {
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}
char HelpfullMetods::wczytajZnak()
{
    string wejscie = "";
    char znak  = {0};

    while (true)
    {
        getline(cin, wejscie);

        if (wejscie.length() == 1)
        {
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return znak;
}

