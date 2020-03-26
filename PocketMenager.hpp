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
#include "Expense.hpp"
#include "AuxiliaryMethods.hpp"
#include "FileWithIncomes.hpp"
#include "FileWithExpenses.hpp"
using namespace std;
class PocketMenager     
{
    const int LOGGING_USER_ID;
    vector <Income> incomes;
    vector <Expense> expenses;
    char menuDate(char pick);
    string setTheDateOfTheFinancialOperation (char choice);
    Income addDetailsOfTheIncome(string dateOfTheExpense);
    Expense addDetailsOfTheExpense(string dateOfTheExpense);
    double checkFormatAndChangeIntoDouble (string amount);
    AuxiliaryMethods auxiliaryMethods;
    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;
public:
    PocketMenager (string nameOfTheFileWithIncomes, string nameOfTheFileWithExpenses,  int loggingUserId) :
        fileWithIncomes(nameOfTheFileWithIncomes), fileWithExpenses(nameOfTheFileWithExpenses), LOGGING_USER_ID(loggingUserId) {
        incomes = fileWithIncomes.loadIncomesOfLoggedInUserFromFile(LOGGING_USER_ID);
        expenses = fileWithExpenses.loadExpenseOfLoggedInUserFromFile(LOGGING_USER_ID);
    };
   // AuxiliaryMethods auxiliaryMethods;
    void addIncome();
    void addExpense();
};
#endif /* PocketMenager_hpp */
