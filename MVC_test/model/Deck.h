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

#include<algorithm>
#include<random>
#include<list>
#include<vector>
#include<chrono>

#include "Common.h"
#include "Card.h"
#include "Suit.h"



using namespace std;
using namespace CardGame_Scoped;

class Deck{
private:
    int number;
    list<Card> cardList;
public:
    // Constructor
    Deck() {}
    Deck(int number) {
        this->SetNum(number);
        createCards(number);
    }
    
    // Getter
    int Number(){
        return this->number;
    }
    int getTotalCard() {
        std::cout << this->cardList.size() << std::endl;
        return static_cast<int>(cardList.size());
    }
    
    // Setter
    void SetNum(int number) {
        this->number = number;
    }
    void SetList(list<Card> &newList) {
        this->cardList = newList;
    }
    // Public Method
    template <typename T> void shuffle( std::list<T>& lst )
    {
        std::vector< std::reference_wrapper< const T > > vec( lst.begin(), lst.end() ) ;
        
        // shuffle (the references in) the vector
        std::shuffle( vec.begin(), vec.end(), std::mt19937{ std::random_device{}() } ) ;
        
        // copy the shuffled sequence into a new list
        std::list<T> shuffled_list {  vec.begin(), vec.end() } ;
        
        // swap the old list with the shuffled list
        lst.swap(shuffled_list) ;
    }

    Card drawCard() {
        Card popCard;
        if (cardList.size() == 0) {
            //throw new NoMoreCardException();
            std::cout << "Empty Deck! " << endl;
        }
        popCard = cardList.back();
        cardList.pop_back();
        std::cout << "Draw Card: " << popCard.Rank() << ", " << popCard.Suit() << std::endl;
        return popCard;
    }
    
    void createCards(int number) {
        string suit;
        for (int j = 0; j < number; j++) {
            for (int check = static_cast<int>(Suit::Diamonds); check != static_cast<int>(Suit::Spades)+1; ++check) {
                for (int i = 1 ; i < 14; i++) {
                    switch (check) {
                        case 0:
                            suit = "Diamonds";
                            break;
                        case 1:
                            suit = "Hearts";
                            break;
                        case 2:
                            suit = "Clubs";
                            break;
                        case 3:
                            suit = "Spades";
                            break;
                    break;
                    }
                    Card newCard = *new Card(i, suit);
                    this->cardList.push_back(newCard);
                }
            }
        }
        shuffle(this->cardList);
    }
};
#endif /* Deck_h */
