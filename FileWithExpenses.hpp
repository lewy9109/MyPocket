//
//  FileWithExpenses.hpp
//  Budget
//
//  Created by Krystian Lewandowski on 26/03/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#ifndef FileWithExpenses_hpp
#define FileWithExpenses_hpp

#include <stdio.h>
#include <iostream>
#include "Expense.hpp"
#include "pugi/pugixml.hpp"
#include "AuxiliaryMethods.hpp"
#include "File.h"
#include <vector>
using namespace std;
class FileWithExpenses : File
{
    int idOfLastExpense;
public:
    FileWithExpenses(string nameOfTheFileWithExpenses) : File(nameOfTheFileWithExpenses) {
        idOfLastExpense = 0;
    };
    int getTheIdOfLastExpense();
    void addExpenseToFile(Expense expense);
    vector <Expense> loadExpenseOfLoggedInUserFromFile(int LOGGING_USER_ID);
};
#endif /* FileWithExpenses_hpp */
