//
//  Hand.h
//  MVC_test
//
//  Created by 김노은 on 30/11/2019.
//  Copyright © 2019 Noeun-Kim. All rights reserved.
//

#ifndef Hand_h
#define Hand_h

#include<list>

#include "Card.h"
#include "Deck.h"


using namespace std;
#include <iostream>

class Hand {
private:
    list<Card> handList;
    Deck deck;
    
public:
    // 생성자
    // Hand(){}
    Hand(){}
    Hand(Deck &newDeck){
        deck = newDeck;
        // cout << "----------------Test-----------------" <<endl;
    }
    
    // Getter
    void getHandSize() {
        cout << this->handList.size() << endl;
    }
    list<Card> getHandList() {
        return this->handList;
    }
    
    // 공개 함수
    Card drawCard(Deck &newDeck) {
        Card card = newDeck.drawCard();
        this->handList.push_back(card);
        return card;
    }
    Card drawCard() {
        Card card = this->deck.drawCard();

        deck.getTotalCard();
        this->handList.push_back(card);
        return card;
    }
    /*
    list<Card> getCardList() {
        return this->cardList;
    }*/
};
#endif
