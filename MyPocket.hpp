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
public:
    void registerUaer();
    void loggingUser();
};

#endif /* MyPocket_hpp */