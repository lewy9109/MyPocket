//
//  MyPocket.hpp
//  Budget
//
//  Created by Krystian Lewandowski on 18/03/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#ifndef MyPocket_hpp
#define MyPocket_hpp

#include <stdio.h>
#include <iostream>
#include "UserMenager.hpp"
using namespace std;

class MyPocket
{
    UserMenager userMenager;
   // AdresatMenager *adresatMenager;
public:
    MyPocket(string nameFileWithUser /*, string nazwaPlikuZAdresatami*/) : userMenager(nameFileWithUser) /*, NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)*/
       {
          // adresatMenager = NULL;
       };
    /*
    ~KsiazkaAdresowa()  
       {
           delete adresatMenager;
           adresatMenager = NULL;
       };
     */
    void registerUaer();
    void loggingUser();
   // void changePassworgLoggedUser();

};

#endif /* MyPocket_hpp */
