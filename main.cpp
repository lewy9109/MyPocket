//
//  main.cpp
//  Budget
//
//  Created by Krystian Lewandowski on 18/03/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#include <iostream>
#include "UserMenager.hpp"

#include "pugixml.hpp"
#include "User.hpp"
#include <vector>
#include "MyPocket.hpp"
using namespace std;
int main()
{
    
    
    UserMenager user ("Users");

    user.loggingUser(); 
    user.wyswietl();
    user.changePassworgLoggedUser();
 
        
    return 0;   
}



    
