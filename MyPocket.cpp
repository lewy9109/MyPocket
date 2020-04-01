//
//  MyPocket.cpp
//  Budget
//
//  Created by Krystian Lewandowski on 18/03/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#include "MyPocket.hpp"

void MyPocket::singInUser()
{
    userMenager.registerUaer();
}
void MyPocket::loggingUser()
{
    userMenager.loggingUser();
    if(userMenager.isUserLogging())
    {
        pocketMenager = new PocketMenager(NAME_OF_FILE_WITH_INCOMES, NAME_OF_FILE_WITH_EXPENCES, userMenager.downloadIdOfLoggedInUser());
    }
}

bool MyPocket::isUserLoggedIn()
{
    return userMenager.isUserLoggedIn();
}   

void MyPocket::changePassword()
{
    userMenager.changePassworgLoggedUser();   
}
void MyPocket::addIncome() {
    if (userMenager.isUserLoggedIn())
    {
        pocketMenager->addIncome();
    } else {
        cout << "Zrobione !!." << endl;
        usleep(20000000);
    }
}

void MyPocket::addExpense() {
    if (userMenager.isUserLoggedIn())
    {
        pocketMenager->addExpense();
    } else {
        cout << "Zrobione." << endl;
        usleep(20000000);
    }
}

void MyPocket::showBalanceFromTheCurrentMonth()
{
    if (userMenager.isUserLoggedIn()) {
        pocketMenager->showBalanceFromTheCurrentMonth();
    } else {
        system("pause");
        usleep(20000000);
    }
}

void MyPocket::showBalanceFromThePreviousMonth()
{
    if (userMenager.isUserLoggedIn()) {
        pocketMenager->showBalanceFromThePreviousMonth();
    } else {
        system("pause");
        usleep(20000000);
    }
}

void MyPocket::showBalanceFromPeriod()
{
    if (userMenager.isUserLoggedIn()) {
        pocketMenager->showBalanceFromPeriod();
    } else {
       
        system("pause");
        usleep(20000000);
    }
}
void MyPocket::logOut()
{
    userMenager.logOut();
    delete pocketMenager;
    pocketMenager = NULL;
}
