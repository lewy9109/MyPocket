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
#include <iomanip>
#include <unistd.h>
#include "Income.hpp"
#include "Expense.hpp"
//#include "User.hpp"
//#include "FileWithUser.hpp"
#include "AuxiliaryMethods.hpp"
#include "FileWithIncomes.hpp"
#include "FileWithExpenses.hpp"
using namespace std;
class PocketMenager     
{
    const int LOGGING_USER_ID;
    vector <Income> incomes;
    vector <Expense> expenses;
    //vector <User> users;    
    AuxiliaryMethods auxiliaryMethods;
    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;
    char menuDate(char pick);
    string setTheDateOfTheFinancialOperation (char choice);
    Income addDetailsOfTheIncome(string dateOfTheExpense);
    Expense addDetailsOfTheExpense(string dateOfTheExpense);
    double checkFormatAndChangeIntoDouble (string amount);
    vector <Income> loadIncomesOnlyFromCurrentMonth();
    vector <Expense> loadExpensesOnlyFromCurrentMonth();
    vector <Income> sortIncomesFromSelectedPeriodOfTime(vector <Income> incomes);
    vector <Expense> sortExpensesFromSelectedPeriodOfTime(vector <Expense> expenses);
    vector <Income> loadIncomesOnlyFromPreviousMonth();
    vector <Expense> loadExpensesOnlyFromPreviousMonth();
    vector <Income> loadIncomesOnlyFromPeriod(string startDate, string endDate);
    void displayExpensesFromSelectedPeriodOfTime(vector <Expense> expenses);
    void displayIncomesFromSelectedPeriodOfTime(vector <Income> incomes);
    double sumIncomes (vector <Income> incomes);
    double sumExpenses (vector <Expense> expenses);
    double sumIncomesAndExpenses (double incomes, double expenses);

public:
    PocketMenager (string nameOfTheFileWithIncomes, string nameOfTheFileWithExpenses,  int loggingUserId) :
        fileWithIncomes(nameOfTheFileWithIncomes), fileWithExpenses(nameOfTheFileWithExpenses), LOGGING_USER_ID(loggingUserId) {
        incomes = fileWithIncomes.loadIncomesOfLoggedInUserFromFile(LOGGING_USER_ID);
        expenses = fileWithExpenses.loadExpenseOfLoggedInUserFromFile(LOGGING_USER_ID);
    };
    void addIncome();
    void addExpense();
    void showBalanceFromTheCurrentMonth();
    void showBalanceFromThePreviousMonth();
    void showBalanceFromPeriod();   
};
#endif /* PocketMenager_hpp */
