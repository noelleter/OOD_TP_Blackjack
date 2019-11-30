//
//  Dealer.h
//  MVC_test
//
//  Created by 김노은 on 30/11/2019.
//  Copyright © 2019 Noeun-Kim. All rights reserved.
//

#ifndef Dealer_h
#define Dealer_h

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


class Dealer {
private:
    int score;
public:
    int getDealerScore()
    {
        // Give Dealer random score between 17~25
        srand((unsigned int)time(NULL));
        int score;
        score = 17;//(rand()%25)+17;
        cout << score << endl;
        this->score = score;
        return score;
    }
};

#endif /* Dealer_h */
