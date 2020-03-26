//
//  PocketMenager.cpp
//  Budget
//
//  Created by Krystian Lewandowski on 24/03/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#include "PocketMenager.hpp"

void PocketMenager::addIncome()
{
    Income income;
    char pick = 2;
    string date;
    pick = menuDate(pick);
    
    date = setTheDateOfTheFinancialOperation(pick);
    
    if (date == "0") {
            cout << "The date is incorrect." << endl;
    system("pause");
    return;
        } else {
            income = addDetailsOfTheIncome(date);
            incomes.push_back(income);
            fileWithIncomes.addIncomeToFile(income);
            cout << "Income has been added." << endl;
    system("pause");
        }
}
char PocketMenager::menuDate(char pick)
{
    system("cls");
    cout << "Wybierz Pomiedzy:"    << endl;
    cout << "--------------------------" << endl;
    cout << "1. Dodaj z dzisiejsza data" << endl;
    cout << "2. Wprowadz inna date"      << endl;
    //cout << "9. Anuluj operacje"         << endl;
    //char pick = 0;
    
    while (pick == 1 || pick == 2) {
        pick = auxiliaryMethods.wczytajZnak();
    }
    return pick;
}
string PocketMenager::setTheDateOfTheFinancialOperation(char pick)
{
    string date = "zla";
    switch (pick)
    {
    case '1':
        date = auxiliaryMethods.setCurrentDateOfTheOperation();
        return date;
        break;
    case '2':
        date = auxiliaryMethods.setUsersDateOfTheOperation();
        return date;
        break;
    }
    return date;
}
Income PocketMenager::addDetailsOfTheIncome(string dateOfTheExpense)
{
    Income income;
    string nameOfTheIncome;
    string amountOfIncome;
    income.setIncomeId(fileWithIncomes.getTheIdOfLastIncome() + 1);
    income.setUserId(LOGGING_USER_ID);
    income.setDate(dateOfTheExpense);
    cin.clear();
    cout << "Wprowadz nazwe przychodu: ";
    cin >> nameOfTheIncome;
    income.setItem(nameOfTheIncome);
    cout << "Wprowadz wartosc: ";
    cin >> amountOfIncome;
    double amountOfIncomeAsDouble = checkFormatAndChangeIntoDouble(amountOfIncome); 
    income.setAmount(amountOfIncomeAsDouble);
    
    return income;
}

double PocketMenager::checkFormatAndChangeIntoDouble (string amount)    
{
size_t i = amount.find(",");
if (i != string::npos)
        amount.replace(i,1,".");
    stringstream ss;
double amountAsADouble;
    ss << amount;
    ss >> amountAsADouble;
return amountAsADouble;
}
