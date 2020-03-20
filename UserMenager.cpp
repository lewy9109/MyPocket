//
//  UserMenager.cpp
//  Budget
//
//  Created by Krystian Lewandowski on 18/03/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#include "UserMenager.hpp"
void UserMenager::addNewUser()
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
