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

#include "Common.h"
#include "Card.h"
#include "Suit.h"

class Deck{
public:
    Deck() {}
    Deck(int number) {
        this->SetNum(number);
        createCards(number);
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
   
    int getTotalCard() {
        return cardList.size();
    }
    
    Card drawCard() {
        Card popCard;
        if (cardList.size() == 0) {
            //throw new NoMoreCardException();
            std::cout << "Empty Deck! " << endl;
        }
        popCard = cardList.back();
        cardList.pop_back();
        std::cout << "Draw Card: " << popCard.Rank() << std::endl;
        return popCard;
        
    }
    
    void createCards(int number) {
        string suit;
        Card newCard();
        
        Card newCard_(number, "SS");
        this->cardList.push_back(newCard_);
        Card newCard2(2, "SS");
        this->cardList.push_back(newCard2);
        Card newCard3(3, "SS");
        this->cardList.push_back(newCard3);
        
        /*
        for (int j = 0; j < number; j++) {
            for (Suit suit : Suit.values()) {
                for (int i = 1 ; i < 14; i++) {
                    Card card = new Card(i, suit);
                    cardList.add(card);
                }
            }
        }
         */
    }
private:
    int number;
    
    list<Card> cardList;
    
};
#endif /* Deck_h */
