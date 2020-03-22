//
//  UserMenager.cpp
//  Budget
//
//  Created by Krystian Lewandowski on 18/03/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#include "UserMenager.hpp"
void UserMenager::registerUaer()
{
    User user = giveDataNewUser();
    
    users.push_back(user);
    
    fileWithUser.addUserToFile(user);
    
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    usleep(2000000);
   // system("pause"); include <windows.h>
}
User UserMenager::giveDataNewUser()
{
    User user;

    user.setId(downloadIdNewUser());
    string login, password, name, surname;
    
    cout << "Podaj Imie: ";
    cin >> name;
    user.setName(name);
    cout << "Podaj Nazwisko: ";
    cin >> surname;
    user.setSurname(surname);
   
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    
    } while (isThereALogin(user.getLogin()) == true);

    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    return user;
}
int UserMenager::downloadIdNewUser()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}
bool UserMenager::isThereALogin(string login)
{
    for (int i = 0; i < users.size(); i++)
    {
        if(users[i].getLogin() == login)
        {
        cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
        return true;
        }
    }
    return false;
}

int UserMenager::loggingUser()
{

    User user;
    AuxiliaryMethods aluxiliaryMethods;
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = aluxiliaryMethods.wczytajLinie();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                password = aluxiliaryMethods.wczytajLinie();

                if (itr -> getPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                   ID_LOG_USER = itr -> getId();
                   system("pause");
                    usleep(2000000);
                   return ID_LOG_USER;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            usleep(2000000);
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    usleep(2000000);
    return 0;
}

