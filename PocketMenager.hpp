//
//  PocketMenager.hpp
//  Budget
//
//  Created by Krystian Lewandowski on 24/03/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#ifndef PocketMenager_hpp
#define PocketMenager_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Income.hpp"
#include "AuxiliaryMethods.hpp"
#include "FileWithIncomes.hpp"
using namespace std;
class PocketMenager     
{
    int LOGGING_USER_ID;
    vector <Income> incomes;
    char menuDate(char pick);
    string setTheDateOfTheFinancialOperation (char choice);
    Income addDetailsOfTheIncome(string dateOfTheExpense);
    double checkFormatAndChangeIntoDouble (string amount);
    AuxiliaryMethods auxiliaryMethods;
    FileWithIncomes fileWithIncomes;
public:
    PocketMenager (string nameOfTheFileWithIncomes) :
        fileWithIncomes(nameOfTheFileWithIncomes) {
        LOGGING_USER_ID = 0;
        incomes = fileWithIncomes.loadIncomesOfLoggedInUserFromFile(LOGGING_USER_ID);
        //expenses = fileWithExpenses.loadExpensesOfLoggedInUserFromFile(loggedInUserId);
    };
   // AuxiliaryMethods auxiliaryMethods;
    void addIncome();
};
#endif /* PocketMenager_hpp */
