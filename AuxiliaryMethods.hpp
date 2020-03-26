//
//  MetodyPomocnicze.hpp
//  ksiazka wlasna obiektowo
//
//  Created by Krystian Lewandowski on 27/02/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#ifndef AuxiliaryMethods_HPP
#define AuxiliaryMethods_HPP

#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctime>

using namespace std;

class AuxiliaryMethods
{
    bool checkTheFormatOfTheDate(int yearAsAnInteger, int monthAsAnInteger, int dayAsAnInteger);
public:
    static string convertDoubleToString(double number);
    static int convertStringToInt(string number);
    
    string wczytajLinie();
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string text);
    string pobierzLiczbe(string text, int pozycjaZnaku);
    int wczytajLiczbeCalkowita();
    char wczytajZnak();
    void deleteFile(string nameFileWithEnlargement);
    void changeNameFile(string oldName, string newName);
    string setCurrentDateOfTheOperation();
    string setUsersDateOfTheOperation();
    
    
};
#endif
