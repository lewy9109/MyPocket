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
    
    if (date == "0")
    {
            cout << "Niepoprawna data." << endl;
    return;
    } else
    {
        income = addDetailsOfTheIncome(date);
        incomes.push_back(income);
        fileWithIncomes.addIncomeToFile(income);
        cout << "Przychod dodany." << endl;
        usleep(2000000);
    }
}
void PocketMenager::addExpense()
{
    Expense expense;
    system("cls");
    char pick = 2;
    string date;
    pick = menuDate(pick);
    date = setTheDateOfTheFinancialOperation(pick);
    if (date == "0") {
        cout << "The date is incorrect." << endl;
        return;
    } else {
        expense = addDetailsOfTheExpense(date);
        expenses.push_back(expense);
        
        fileWithExpenses.addExpenseToFile(expense); 
        cout << "Koszt dodany." << endl;
        usleep(2000000);
    }
}
char PocketMenager::menuDate(char pick)
{
    system("cls");
    cout << "Wybierz Pomiedzy:"    << endl;
    cout << "--------------------------" << endl;
    cout << "1. Dodaj z dzisiejsza data" << endl;
    cout << "2. Wprowadz inna date"      << endl;
    
    while (pick == 1 || pick == 2) {
        pick = auxiliaryMethods.getChar();
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
Expense PocketMenager::addDetailsOfTheExpense(string dateOfTheExpense)
{
    Expense expense;
    string nameOfTheExpense;
    string amountOfExpense;

    expense.setExpenseId(fileWithExpenses.getTheIdOfLastExpense() + 1);

    expense.setUserId(LOGGING_USER_ID);

    expense.setDate(dateOfTheExpense);

    cout << "Wprowadz nazwe wydatku: ";
    cin >> nameOfTheExpense;
    expense.setItem(nameOfTheExpense);

    cout << "Wprowadz wartosc: ";
    cin >> amountOfExpense;
    double amountOfExpenseAsDouble = checkFormatAndChangeIntoDouble(amountOfExpense);
    expense.setAmount(amountOfExpenseAsDouble);

    return expense;
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

void PocketMenager::showBalanceFromTheCurrentMonth()
{
    cout << setprecision (2);   
    cout << fixed;
    vector <Income> incomesFromCurrentMonth;
    vector <Income> sortedIncomesFromCurrentMonth;
    system("cls");
    incomesFromCurrentMonth = loadIncomesOnlyFromCurrentMonth();
    displayIncomesFromSelectedPeriodOfTime(incomesFromCurrentMonth);
    double totalIncomes;
    totalIncomes = sumIncomes(incomesFromCurrentMonth);
    cout << "---------------------------------------" << endl;
    cout << "WSZYSTKIE WPŁYWY: " << totalIncomes << endl;
    vector <Expense> expensesFromCurrentMonth;
    vector <Expense> sortedExpensesFromCurrentMonth;
    expensesFromCurrentMonth = loadExpensesOnlyFromCurrentMonth();
    displayExpensesFromSelectedPeriodOfTime(expensesFromCurrentMonth);
    double totalExpenses;
    totalExpenses = sumExpenses(expensesFromCurrentMonth);
    cout << "---------------------------------------" << endl;
    cout << "WSZYSTKIE KOSZTY: " << totalExpenses << endl << endl;
    double balanceFromCurrentMonth = sumIncomesAndExpenses(totalIncomes, totalExpenses);
    cout << "---------------------------------------" << endl;
    cout << "BILANS Z BIEZACEGO MIESIACA: " << balanceFromCurrentMonth << endl;
    cout << "---------------------------------------" << endl;
    usleep(10000000);
}

void PocketMenager::showBalanceFromThePreviousMonth()
{
    cout << setprecision (2);
    cout << fixed;
    vector <Income> incomesFromPreviousMonth;
    vector <Income> sortedIncomesFromPreviousMonth;
    system("cls");
    incomesFromPreviousMonth = loadIncomesOnlyFromPreviousMonth();
    displayIncomesFromSelectedPeriodOfTime(incomesFromPreviousMonth);
    double totalIncomes;
    totalIncomes = sumIncomes(incomesFromPreviousMonth);
    cout << "---------------------------------------" << endl;
    cout << "WSZYSTKIE WPŁYWY: " << totalIncomes << endl;
    vector <Expense> expensesFromPreviousMonth;
    vector <Expense> sortedExpensesFromPreviousMonth;
    expensesFromPreviousMonth = loadExpensesOnlyFromPreviousMonth();
    displayExpensesFromSelectedPeriodOfTime(expensesFromPreviousMonth);
    double totalExpenses;
    totalExpenses = sumExpenses(expensesFromPreviousMonth);
    cout << "---------------------------------------" << endl;
    cout << "WSZYTSKIE WYDATKI: " << totalExpenses << endl << endl;
    double balanceFromPreviousMonth = sumIncomesAndExpenses(totalIncomes, totalExpenses);
    cout << "---------------------------------------" << endl;
    cout << "BILANS Z POPRZEDNIEGO MIESIACA: " << balanceFromPreviousMonth << endl;
    cout << "---------------------------------------" << endl;
    usleep(10000000);
}

void PocketMenager::showBalanceFromPeriod() 
{
    cout << setprecision (2);
    cout << fixed;
    vector <Income> incomesFromPeriod;
    vector <Expense> expensesFromPeriod;
    system("cls");
    cout << "Start date for the balance" << endl;
    string startDate = auxiliaryMethods.setUsersDateOfTheOperation();
    cout << "End date for the balance: " << endl;
    string endDate = auxiliaryMethods.setUsersDateOfTheOperation();
    double totalIncomes;
    double totalExpenses;
    double balanceFromPeriod;
    incomesFromPeriod = loadIncomesOnlyFromPeriod(startDate, endDate);
    expensesFromPeriod = loadExpensesOnlyFromPeriod(startDate, endDate);
    if ((incomesFromPeriod.empty() == false) && (expensesFromPeriod.empty() == false)) {
        system("cls");
        vector <Income> sortedIncomesFromPeriod;
        displayIncomesFromSelectedPeriodOfTime(incomesFromPeriod);
        totalIncomes = sumIncomes(incomesFromPeriod);
        cout << "---------------------------------------" << endl;
        cout << "WSZYTSKIE WPLYWY: " << totalIncomes << endl;
        vector <Expense> sortedExpensesFromPeriod;
        displayExpensesFromSelectedPeriodOfTime(expensesFromPeriod);
        totalExpenses = sumExpenses(expensesFromPeriod);
        cout << "---------------------------------------" << endl;
        cout << "WSZYSTKIE KOSZTY: " << totalExpenses << endl << endl;
        balanceFromPeriod = sumIncomesAndExpenses(totalIncomes, totalExpenses);
        cout << "---------------------------------------" << endl;
        cout << "BILANS Z WYBRANEGO OKRESU: " << balanceFromPeriod << endl;
        cout << "---------------------------------------" << endl;
        usleep(10000000);
    } else {
        cout << "Nie ma czego tu wyswietlac" << endl;
       // system("pause");
        usleep(3000000);
    }
}

vector <Income> PocketMenager::loadIncomesOnlyFromCurrentMonth()
{
    Income income;
    vector <Income> incomesOnlyFromCurrentMonth;
    int currentYear = auxiliaryMethods.getCurrentYear();
    int currentMonth = auxiliaryMethods.getCurrentMonth();
    vector <Income>::iterator itr = incomes.begin();
    while (itr != incomes.end()) {
        string date = itr -> getDate();
        int yearFromUsersDate = auxiliaryMethods.getYearFromOperationDate(date);
        int monthFromUsersDate = auxiliaryMethods.getMonthFromOperationDate(date);
        if (yearFromUsersDate == currentYear && monthFromUsersDate == currentMonth) {
            income.setIncomeId(itr -> getIncomeId());
            income.setUserId(itr -> getUserId());
            income.setDate(itr -> getDate());
            income.setItem(itr -> getItem());
            income.setAmount(itr -> getAmount());
            income.setDateAsUnixTime(auxiliaryMethods.changeDateFormatForUnixTime(itr -> getDate()));   
            incomesOnlyFromCurrentMonth.push_back(income);
        }
        itr++;
    }
    return incomesOnlyFromCurrentMonth;
}

vector <Expense> PocketMenager::loadExpensesOnlyFromCurrentMonth()
{
    Expense expense;
    vector <Expense> expensesOnlyFromCurrentMonth;
    int currentYear = auxiliaryMethods.getCurrentYear();
    int currentMonth = auxiliaryMethods.getCurrentMonth();
    vector <Expense>::iterator itr = expenses.begin();
    while (itr != expenses.end()) {
        string date = itr -> getDate();
        int yearFromUsersDate = auxiliaryMethods.getYearFromOperationDate(date);
        int monthFromUsersDate = auxiliaryMethods.getMonthFromOperationDate(date);
        if (yearFromUsersDate == currentYear && monthFromUsersDate == currentMonth) {
            expense.setExpenseId(itr -> getExpenseId());
            expense.setUserId(itr -> getUserId());
            expense.setDate(itr -> getDate());
            expense.setItem(itr -> getItem());
            expense.setAmount(itr -> getAmount());
            expense.setDateAsUnixTime(auxiliaryMethods.changeDateFormatForUnixTime(itr -> getDate()));
            expensesOnlyFromCurrentMonth.push_back(expense);
        }
        itr++;
    }
    return expensesOnlyFromCurrentMonth;
}
vector <Income> PocketMenager::loadIncomesOnlyFromPreviousMonth()
{
    Income income;
    vector <Income> incomesOnlyFromPreviousMonth;
    int yearForPreviousMonth = auxiliaryMethods.getCurrentYear();
    int currentMonth = auxiliaryMethods.getCurrentMonth();
    int previousMonth;
    if (currentMonth == 1) {
        previousMonth = 12;
        yearForPreviousMonth--;
    } else {
        previousMonth = currentMonth - 1;
    }
    vector <Income>::iterator itr = incomes.begin();
    while (itr != incomes.end()) {
        string date = itr -> getDate();
        int yearFromUsersDate = auxiliaryMethods.getYearFromOperationDate(date);
        int monthFromUsersDate = auxiliaryMethods.getMonthFromOperationDate(date);
        if (yearFromUsersDate == yearForPreviousMonth && monthFromUsersDate == previousMonth) {
            income.setIncomeId(itr -> getIncomeId());
            income.setUserId(itr -> getUserId());
            income.setDate(itr -> getDate());
            income.setItem(itr -> getItem());
            income.setAmount(itr -> getAmount());
            income.setDateAsUnixTime(auxiliaryMethods.changeDateFormatForUnixTime(itr -> getDate()));
            incomesOnlyFromPreviousMonth.push_back(income);
        }
        itr++;
    }
    return incomesOnlyFromPreviousMonth;
}
vector <Expense> PocketMenager::loadExpensesOnlyFromPreviousMonth()
{
    Expense expense;
    vector <Expense> expensesOnlyFromPreviousMonth;
    int yearForPreviousMonth = auxiliaryMethods.getCurrentYear();
    int currentMonth = auxiliaryMethods.getCurrentMonth();
    int previousMonth;
    if (currentMonth == 1) {
        previousMonth = 12;
        yearForPreviousMonth--;
    } else {
        previousMonth = currentMonth - 1;
    }
    vector <Expense>::iterator itr = expenses.begin();
    while (itr != expenses.end()) {
        string date = itr -> getDate();
        int yearFromUsersDate = auxiliaryMethods.getYearFromOperationDate(date);
        int monthFromUsersDate = auxiliaryMethods.getMonthFromOperationDate(date);
        if (yearFromUsersDate == yearForPreviousMonth && monthFromUsersDate == previousMonth) {
            expense.setExpenseId(itr -> getExpenseId());
            expense.setUserId(itr -> getUserId());
            expense.setDate(itr -> getDate());
            expense.setItem(itr -> getItem());
            expense.setAmount(itr -> getAmount());
            expense.setDateAsUnixTime(auxiliaryMethods.changeDateFormatForUnixTime(itr -> getDate()));
            expensesOnlyFromPreviousMonth.push_back(expense);
        }
        itr++;
    }
    return expensesOnlyFromPreviousMonth;
}

vector <Income> PocketMenager::loadIncomesOnlyFromPeriod(string startDate, string endDate)
{
    Income income;
    vector <Income> incomesOnlyFromPeriod;
    time_t startDateInUnixTime = auxiliaryMethods.changeDateFormatForUnixTime(startDate);
    time_t endDateInUnixTime = auxiliaryMethods.changeDateFormatForUnixTime(endDate);
    if ((endDateInUnixTime-startDateInUnixTime)>=0) {
        vector <Income>::iterator itr = incomes.begin();
        while (itr != incomes.end()) {
            string date = itr -> getDate();
            int dateInUnixTime = auxiliaryMethods.changeDateFormatForUnixTime(date);
            if (dateInUnixTime >= startDateInUnixTime && dateInUnixTime <= endDateInUnixTime) {
                income.setIncomeId(itr -> getIncomeId());
                income.setUserId(itr -> getUserId());
                income.setDate(itr -> getDate());
                income.setItem(itr -> getItem());
                income.setAmount(itr -> getAmount());
                income.setDateAsUnixTime(dateInUnixTime);
                incomesOnlyFromPeriod.push_back(income);
            }
            itr++;
        }
    }
    return incomesOnlyFromPeriod;
}
vector <Expense> PocketMenager::loadExpensesOnlyFromPeriod(string startDate, string endDate)
{
    Expense expense;
    vector <Expense> expensesOnlyFromPeriod;
    time_t startDateInUnixTime = auxiliaryMethods.changeDateFormatForUnixTime(startDate);
    time_t endDateInUnixTime = auxiliaryMethods.changeDateFormatForUnixTime(endDate);
    if ((endDateInUnixTime-startDateInUnixTime)>=0) {
        vector <Expense>::iterator itr = expenses.begin();
        while (itr != expenses.end()) {
            string date = itr -> getDate();
            int dateInUnixTime = auxiliaryMethods.changeDateFormatForUnixTime(date);
            if (dateInUnixTime >= startDateInUnixTime && dateInUnixTime <= endDateInUnixTime) {
                expense.setExpenseId(itr -> getExpenseId());
                expense.setUserId(itr -> getUserId());
                expense.setDate(itr -> getDate());
                expense.setItem(itr -> getItem());
                expense.setAmount(itr -> getAmount());
                expense.setDateAsUnixTime(dateInUnixTime);
                expensesOnlyFromPeriod.push_back(expense);
            }
            itr++;
        }
        
    }
    return expensesOnlyFromPeriod;
}

void PocketMenager::displayIncomesFromSelectedPeriodOfTime(vector <Income> incomes)
{
    cout << "WPŁYWY:" << endl;
    for(int i = 0; i < incomes.size(); i++) {
        cout<<incomes.at(i).getDate()<<" "<<incomes.at(i).getItem()<< " " <<incomes.at(i).getAmount()<< endl;
    }
}
double PocketMenager::sumIncomes (vector <Income> incomes)
{
    double totalIncomes = 0;
    for(int i = 0; i < incomes.size(); i++) {
        totalIncomes += incomes.at(i).getAmount();
    }
    return totalIncomes;
}
void PocketMenager::displayExpensesFromSelectedPeriodOfTime(vector <Expense> expenses)
{
    cout << endl << "WYDATKI:" << endl;
    for(int i = 0; i < expenses.size(); i++) {
        cout<<expenses.at(i).getDate()<<" "<<expenses.at(i).getItem()<< " " <<expenses.at(i).getAmount()<< '\n';
    }
}
double PocketMenager::sumExpenses (vector <Expense> expenses)
{
    double totalExpenses = 0;
    for(int i = 0; i < expenses.size(); i++) {
        totalExpenses += expenses.at(i).getAmount();
    }
    return totalExpenses;
}
double PocketMenager::sumIncomesAndExpenses (double incomes, double expenses)
{
    double balance = incomes - expenses;
    return balance;
}

