//
//  MyPocket.cpp
//  Budget
//
//  Created by Krystian Lewandowski on 18/03/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#include "MyPocket.hpp"

void MyPocket::registerUaer()
{
    userMenager.registerUaer();
}
void MyPocket::loggingUser()
{
    userMenager.loggingUser();
    if(userMenager.isUserLogging())
    {
       // adresatMenager = new AdresatMenager(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenager.pobierzIdZalogowanegoUzytkownika());
    }
}

