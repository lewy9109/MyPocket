//
//  User.hpp
//  Budget
//
//  Created by Krystian Lewandowski on 18/03/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#ifndef User_hpp
#define User_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
class User
{
    int id;
    string name;
    string surname;
    string login;
    string password;
    
public:
    void setId(int newId);
    void setName(string newName);
    void setSurname(string newSurname);
    void setLogin(string newLogin);
    void setPassword(string newPassword);
    
    int getId();
    string getName();
    string getSurname();
    string getLogin();
    string getPassword();
};

#endif /* User_hpp */
