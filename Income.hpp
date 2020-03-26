//
//  Income.hpp
//  Budget
//
//  Created by Krystian Lewandowski on 24/03/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#ifndef Income_hpp
#define Income_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
class Income
{
    int incomeId;
    int userId;
    string date;
    string item;
    double amount;
    //int dateAsUnixTime;
    
public:
    void setIncomeId (int newIncomeId);
    void setUserId (int newUserId);
    void setDate (string newDate);
    void setItem (string newItem);
    void setAmount (double newAmount);
   // void setDateAsUnixTime (int newDateAsUnixTime);

    int getIncomeId();
    int getUserId();
    string getDate();
    string getItem();
    double getAmount();
    //int getDateAsUnixTime() const;
};

#endif /* Income_hpp */
