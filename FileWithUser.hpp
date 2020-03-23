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
#include "AuxiliaryMethods.hpp"
#include <fstream>
#include "pugixml.hpp"
#include <vector>
using namespace std;
class FileWithUser
{
   const string NAME_FILE = "User.txt";
  //  string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(User user);
 //   bool czyPlikJestPusty(fstream &plikTekstowy);
  //  User pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

    
public:
   // void addUserToFile(User user);
    
   // void saveAllUseresToFile(vector <User> &users);
   // vector <User> loadAllUsersWithFile();
    void addUserToFileXML(User user);
    void loadAllUserFromFile();

  
};

#endif /* FileWithUser_hpp */
