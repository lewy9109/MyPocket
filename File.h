//
//  File.h
//  Budget
//
//  Created by Krystian Lewandowski on 23/03/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#ifndef File_h
#define File_h
#include <iostream>
using namespace std;
 
class File {
 
    const string NAME_FILE;

public:
 
    File(string nameFile) : NAME_FILE(nameFile) {
    }
    string getNameFile()
    {
        return NAME_FILE;
    }
};
#endif /* File_h */
