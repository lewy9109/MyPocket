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
#include "File.h"
#include "User.hpp"
#include "AuxiliaryMethods.hpp"
#include "pugixml.hpp"
#include <vector>
using namespace std;
class FileWithUser : File
{
   // const string NAME_FILE;

public:
    FileWithUser(string nameFileWithUser) : File(nameFileWithUser){};
    
    void addUserToFileXML(User user);
    void loadAllUserFromFile();
    vector <User> readUsersFromFile();
    void saveAllUseresToFile(vector <User> &users);
};

#endif /* FileWithUser_hpp */
