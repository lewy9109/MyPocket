//
//  UserMenager.hpp
//  Budget
//
//  Created by Krystian Lewandowski on 18/03/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#ifndef UserMenager_hpp
#define UserMenager_hpp

#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <vector>
#include "User.hpp"
#include "FileWithUser.hpp"
#include "AuxiliaryMethods.hpp"
using namespace std;
class UserMenager
{
    int idLoggingUser;
    vector <User> users;
    User giveDataNewUser();
    int downloadIdNewUser();
    bool isThereALogin(string login);
    FileWithUser fileWithUser;
    
public:
    UserMenager(string nameFileWithUser): fileWithUser(nameFileWithUser){
        idLoggingUser = 0;
        users = fileWithUser.readUsersFromFile();
    };
    
    int downloadIdOfLoggedInUser();
    bool isUserLoggedIn();
    void registerUaer();
    int loggingUser();
    void changePassworgLoggedUser();
    bool isUserLogging();
    void wyswietl();
    void logOut();
    
    
};  
#endif /* UserMenager_hpp */
