//
//  Player.h
//  MVC_test
//
//  Created by 김노은 on 30/11/2019.
//  Copyright © 2019 Noeun-Kim. All rights reserved.
//

#ifndef Player_h
#define Player_h

#include "Hand.h"

class Player {
private:
    int balance;
    int currentBet;
    Hand hand;
    
public:
    // 생성자
    Player(){}
    Player(int seedMoney, Hand &hand) {
        this->balance = seedMoney;
        this->hand = hand;
    }
    
    // Getter
    Hand* getHand(){
        return &hand;
    }
    int Balance(){
        return this->balance;
    }
    int CurrBet(){
        return this->currentBet;
    }
    // Setter
    void setBalance(int newBal){
        this->balance = newBal;
    }
    
    // 공개 함수
    void placeBet(int bet) {
        if(balance < bet) {
            cout << "NotEnoughBalanceException" <<endl;
            // throw new NotEnoughBalanceException();
        }
        balance -= bet;
        currentBet = bet;
        cout << balance << ", " << currentBet <<endl;
    }
    
    Card hitCard() {
        return hand.drawCard();
    }
};


#endif /* Player_h */
