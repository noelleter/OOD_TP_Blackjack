//
//  Common.h
//  MVC_test
//
//  Created by 김노은 on 29/11/2019.
//  Copyright © 2019 Noeun-Kim. All rights reserved.
//

#ifndef Common_h
#define Common_h

#include <stdio.h>
#pragma once
#include <string>
using namespace std;
typedef void (*DataChangeHandler)(string newData);
typedef void (*DataChangeHandler_Integer)(int newData);

#endif /* Common_h */
