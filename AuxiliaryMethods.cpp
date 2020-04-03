//
//  MetodyPomocnicze.cpp
//  ksiazka wlasna obiektowo
//
//  Created by Krystian Lewandowski on 27/02/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#include "AuxiliaryMethods.hpp"

string AuxiliaryMethods::convertDoubleToString(double number)
{
    ostringstream ss;       
    ss << number;
    string str = ss.str();
    return str;
}

int AuxiliaryMethods::convertStringToInt(string number)
{
    int liczbaInt;
    istringstream iss(number);
    iss >> liczbaInt;
    return liczbaInt;
}
string AuxiliaryMethods::loadLine()
{
    
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}
string AuxiliaryMethods::changeFirstLetterToUpper(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

int AuxiliaryMethods::getIntegerNumber()
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
char AuxiliaryMethods::getChar()
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
void AuxiliaryMethods::deleteFile(string nameFileWithEnlargement)
{
    if (remove(nameFileWithEnlargement.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nameFileWithEnlargement << endl;
}
void AuxiliaryMethods::changeNameFile(string oldName, string newName)   
{
    if (rename(oldName.c_str(), newName.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << oldName << endl;
}

string AuxiliaryMethods::setCurrentDateOfTheOperation()
{

    time_t now = time(0);

    tm *ltm = localtime(&now);

    int yearInt =  1900 + ltm->tm_year;
    int monthInt = 1 + ltm->tm_mon;
    int dayInt =  ltm->tm_mday;
    
    string day, month, year, fulldate;
    year = convertDoubleToString(yearInt);
    month = convertDoubleToString(monthInt);
    if (month.length() == 1)
        month = "0" + month;
    day = convertDoubleToString(dayInt);
    if (day.length() == 1)
           day = "0" + day;

    fulldate = year + "-" + month + "-" + day;
    cout << fulldate << endl;
    return fulldate;
     
}

string AuxiliaryMethods::setUsersDateOfTheOperation()
{
    cout << "Please enter the date (yyyy-mm-dd): ";
    string date;
    cin >> date;
    if (date.length() < 10) {
        date = "0";
        return date;
    }
    string year = date.substr( 0, 4);
    int yearAsAnInteger;
    istringstream strYear(year);
    strYear >> yearAsAnInteger;
    string month = date.substr( 5, 2);
    int monthAsAnInteger;
    istringstream strMonth(month);
    strMonth >> monthAsAnInteger;
    string day = date.substr( 8, 2);
    int dayAsAnInteger;
    istringstream strDay(day);
    strDay >> dayAsAnInteger;
    bool hasTheDateCorrectFormat = checkTheFormatOfTheDate(yearAsAnInteger, monthAsAnInteger, dayAsAnInteger);
    if (hasTheDateCorrectFormat == true) {
        return date;
    } else {
        date = "0";
        return date;
    }
}

bool AuxiliaryMethods::checkTheFormatOfTheDate(int yearAsAnInteger, int monthAsAnInteger, int dayAsAnInteger)
{
    bool hasTheDateCorrectFormat = true;
    switch(monthAsAnInteger) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (dayAsAnInteger < 1 || dayAsAnInteger > 31) {
            hasTheDateCorrectFormat = false;
            return hasTheDateCorrectFormat;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (dayAsAnInteger < 1 || dayAsAnInteger > 30) {
            hasTheDateCorrectFormat = false;
            return hasTheDateCorrectFormat;
        }
        break;
    case 2:
        if (((yearAsAnInteger % 4 == 0) && (yearAsAnInteger % 100 != 0)) || (yearAsAnInteger%400 == 0)) {
            if (dayAsAnInteger < 1 || dayAsAnInteger > 29) {
                hasTheDateCorrectFormat = false;
                return hasTheDateCorrectFormat;
            }
        } else {
            if (dayAsAnInteger < 1 || dayAsAnInteger > 28) {
                hasTheDateCorrectFormat = false;
                return hasTheDateCorrectFormat;
            }
        }
        break;
    }
    if ((yearAsAnInteger < 2000) || (monthAsAnInteger < 1) || (monthAsAnInteger > 12)) {
        hasTheDateCorrectFormat = false;
        return hasTheDateCorrectFormat;
    }
    return hasTheDateCorrectFormat;
}
int AuxiliaryMethods::getCurrentYear()  
{
    time_t now = time(0);

     tm *ltm = localtime(&now);

     int yearInt =  1900 + ltm->tm_year;

    return yearInt;
}

int AuxiliaryMethods::getCurrentMonth()
{
    time_t now = time(0);

    tm *ltm = localtime(&now);

    int monthInt = 1 + ltm->tm_mon;

    return monthInt;
}
int AuxiliaryMethods::getYearFromOperationDate(string date)
{
    string year = date.substr( 0, 4);
    int yearAsAnInteger;
    istringstream strYear(year);
    strYear >> yearAsAnInteger;

    return yearAsAnInteger;
}

int AuxiliaryMethods::getMonthFromOperationDate(string date)
{
    string month = date.substr( 5, 2);
    int monthAsAnInteger;
    istringstream strMonth(month);
    strMonth >> monthAsAnInteger;

    return monthAsAnInteger;
}
time_t AuxiliaryMethods::changeDateFormatForUnixTime (string date)  
{
    tm time;
    string year = date.substr( 0, 4);
    int yearAsAnInteger;
    istringstream strYear(year);
    strYear >> yearAsAnInteger;
    time.tm_year = yearAsAnInteger-1900;
    string month = date.substr( 5, 2);
    int monthAsAnInteger;
    istringstream strMonth(month);
    strMonth >> monthAsAnInteger;
    time.tm_mon = monthAsAnInteger-1;
    string day = date.substr( 8, 2);
    int dayAsAnInteger;
    istringstream strDay(day);
    strDay >> dayAsAnInteger;
    time.tm_mday = dayAsAnInteger;
    time.tm_hour = 0;
    time.tm_min = 0;
    time.tm_sec = 0;
    time_t timestamp = mktime(&time);
    return timestamp;
}
void AuxiliaryMethods::pause()
{
    cin.clear();
    cout << endl << "Press any key to continue...";
    cin.ignore();
}
