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
    
    string loadLine();
    string changeFirstLetterToUpper(string text);
    string getNumber(string text, int pozycjaZnaku);
    int getIntegerNumber();
    char getChar();
    void deleteFile(string nameFileWithEnlargement);
    void changeNameFile(string oldName, string newName);
    string setCurrentDateOfTheOperation();
    string setUsersDateOfTheOperation();
    int getCurrentYear();
    int getCurrentMonth();
    int getYearFromOperationDate(string date);
    int getMonthFromOperationDate(string date);
    time_t changeDateFormatForUnixTime (string date);
    void pause();

};
#endif
