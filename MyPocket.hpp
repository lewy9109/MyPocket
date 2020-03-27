//
//  MyPocket.hpp
//  Budget
//
//  Created by Krystian Lewandowski on 18/03/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#ifndef MyPocket_hpp
#define MyPocket_hpp

#include <iostream>
#include <unistd.h>
#include "UserMenager.hpp"
#include "PocketMenager.hpp"
using namespace std;

class MyPocket
{
    UserMenager userMenager;
    PocketMenager *pocketMenager;
    const string NAME_OF_FILE_WITH_INCOMES;
    const string NAME_OF_FILE_WITH_EXPENCES;
public:
    MyPocket (string nameOfFileWithUsers, string nameOfFileWithIncomes, string nameOfFileWithExpences) :
        userMenager(nameOfFileWithUsers), NAME_OF_FILE_WITH_INCOMES (nameOfFileWithIncomes), NAME_OF_FILE_WITH_EXPENCES (nameOfFileWithExpences) {
            pocketMenager = NULL;
        };
    ~MyPocket() {
        delete pocketMenager;
    }
    bool isUserLoggedIn();
    void singInUser();
    void loggingUser();
    void changePassword();
    void logOut();
    void addIncome();
    void addExpense();
    void showBalanceFromTheCurrentMonth();
    void showBalanceFromThePreviousMonth();
    void showBalanceFromPeriod();
};

#endif /* MyPocket_hpp */
