//
//  Deck.h
//  MVC_test
//
//  Created by 김노은 on 29/11/2019.
//  Copyright © 2019 Noeun-Kim. All rights reserved.
//

#ifndef Deck_h
#define Deck_h

#include <list>
#include <iostream>
#include "Suit.h"
#include "Common.h"
#include "Card.h"
class Deck{
public:
    Deck() {}
    Deck(int number) {
        this->SetNum(number);
        createCards(1);
    }
    // Getter
    int Number(){
        return this->number;
    }

    // Setter
    void SetNum(const int &number) {
        this->number = number;
        std::cout << "Setting : " << this->number << endl;
    }
   
    void createCards(int number) {
        Card newCard(number, "SS");
        this->cardList.push_back(newCard);
        std::cout << "Card Generated!: " << newCard.Rank() << ", " <<  newCard.Suit() << endl;
    }
private:
    int number;
    
    list<Card> cardList;
    
};
#endif /* Deck_h */
