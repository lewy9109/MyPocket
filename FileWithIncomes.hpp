//
//  FileWithIncomes.hpp
//  Budget
//
//  Created by Krystian Lewandowski on 26/03/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#ifndef FileWithIncomes_hpp
#define FileWithIncomes_hpp

#include <stdio.h>
#include <iostream>
#include "Income.hpp"
#include "pugi/pugixml.hpp"
#include "AuxiliaryMethods.hpp"
#include "File.h"
#include <vector>
using namespace std;
class FileWithIncomes : File    
{
    Income income;
    vector <Income> incomes;
    int idOfLastIncome;
    float round_float_precision(float x, unsigned digits);
public:
    FileWithIncomes(string nameOfTheFileWithIncomes) : File(nameOfTheFileWithIncomes) {
        idOfLastIncome = 0; 
    };
    void addIncomeToFile(Income income);
    vector <Income> loadIncomesOfLoggedInUserFromFile(int LOGGING_USER_ID);
};
#endif /* FileWithIncomes_hpp */
