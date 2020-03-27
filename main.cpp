//
//  main.cpp
//  Budget
//
//  Created by Krystian Lewandowski on 18/03/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#include <iostream>

#include "MyPocket.hpp"

using namespace std;

char chooseOptionFromMainMenu();
char chooseOptionFromUsersMenu();
char loadChar();

int main() {

    MyPocket myPocket ("FileWithUsers.xml", "Incomes.xml", "Expenses.xml");

    char choice;

    while (true) {
        if (myPocket.isUserLoggedIn() == false) {
            choice = chooseOptionFromMainMenu();

            switch (choice) {
            case '1':
                myPocket.singInUser();
                break;
            case '2':
                myPocket.loggingUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "There is no such option in main menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            choice = chooseOptionFromUsersMenu();

            switch (choice) {
            case '1':
                myPocket.addIncome();
                break;
            case '2':
                myPocket.addExpense();
                break;
            case '3':
                myPocket.showBalanceFromTheCurrentMonth();
                break;
            case '4':
                myPocket.showBalanceFromThePreviousMonth();
                break;
            case '5':
                myPocket.showBalanceFromPeriod();
                break;
            case '6':
                myPocket.changePassword();
                break;
            case '7':
                myPocket.logOut();
                break;
            }
        }
    }
    return 0;
}

char chooseOptionFromMainMenu() {
    char choice;

    system("cls");
    cout << "     >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Wyjscie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = loadChar();

    return choice;
}

char chooseOptionFromUsersMenu() {
    char choice;

    system("cls");
    cout << "             >>> Menu <<<" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "1. Przychod" << endl;
    cout << "2. Koszty" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego przedzialu daty" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = loadChar();

    return choice;
}

char loadChar() {
    string entry = "";
    char character  = {0};
    cin.sync();

    while (true) {
        getline(cin, entry);

        if (entry.length() == 1) {
            character = entry[0];
            break;
        }
        cout << "This is not a single character. Try again." << endl;
    }
    return character;
}



    
