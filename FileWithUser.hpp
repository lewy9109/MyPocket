//
//  FileWithUser.hpp
//  Budget
//
//  Created by Krystian Lewandowski on 18/03/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#ifndef FileWithUser_hpp
#define FileWithUser_hpp

#include <iostream>
#include <stdio.h>
#include "User.hpp"
#include "HelpfullMetods.hpp"
#include <fstream>
using namespace std;
class FileWithUser
{
   const string NAME_FILE = "User.txt";
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(User user);
    bool czyPlikJestPusty(fstream &plikTekstowy);
    HelpfullMetods helpFullMetods;
public:
    void addUserToFile(User user);  
};

#endif /* FileWithUser_hpp */
