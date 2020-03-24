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
    
    fileWithUser.addUserToFileXML(user);
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    usleep(2000000);
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
                   idLoggingUser = itr -> getId();
                   system("pause");
                    usleep(2000000);
                   return idLoggingUser;
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

void UserMenager::changePassworgLoggedUser()
{
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    cin >> newPassword;

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getId() == idLoggingUser)
        {
            itr -> setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            usleep(2000000);
        }
    }
    fileWithUser.saveAllUseresToFile(users);
}

bool UserMenager::isUserLogging()   
{
    if(idLoggingUser > 0)
        return true;
    else
        return false;
}

void UserMenager::wyswietl()
{
    vector<User> :: iterator itr;
    for (itr = users.begin(); itr != users.end();itr ++)
    {
        cout << itr -> getId() << " " << itr -> getName() << endl;
    }
}
