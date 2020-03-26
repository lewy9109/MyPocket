//
//  Expense.hpp
//  Budget
//
//  Created by Krystian Lewandowski on 26/03/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#ifndef Expense_hpp
#define Expense_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Expense {
    int expenseId;
    int userId;
    string date;
    string item;
    double amount;
   // int dateAsUnixTime;

public:
    void setExpenseId (int newExpenseId);
    void setUserId (int newUserId);
    void setDate (string newDate);
    void setItem (string newItem);
    void setAmount (double newAmount);
   // void setDateAsUnixTime (int newDateAsUnixTime);

    int getExpenseId();
    int getUserId();
    string getDate();
    string getItem();
    double getAmount();
  //  int downloadDateAsUnixTime() const;
};

#endif /* Expense_hpp */
