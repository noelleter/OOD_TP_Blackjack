//
//  Card.h
//  MVC_test
//
//  Created by 김노은 on 29/11/2019.
//  Copyright © 2019 Noeun-Kim. All rights reserved.
//

#ifndef Card_h
#define Card_h
#include "Common.h"
#include<iostream>

class Card{
public:
    Card(int rank, string suit) {
        if(rank>13){
            std::cout << "Error " << endl;
        }
        else{
            this->SetRank(rank);
            this->SetSuit(suit);
        }
    }
    
    Card() { } // default constructor
    
    // Getter
    int Rank(){
        return this->rank;
    }
    string Suit(){
        return this->suit;
    }
    
    // Setter
    void SetRank(const int &rank) {
        this->rank = rank;
        if (this->event != nullptr) { // data change callback event
            this->integerEvent(rank);
        }
    }
    void SetSuit(const string &suit) {
        this->suit = suit;
        if (this->event != nullptr) { // data change callback event
            this->event(suit);
        }

    }
    
    //  register the event when data changes.
    void RegisterDataChangeHandler(DataChangeHandler handler) {
        this->event = handler;
    }
    void RegisterDataChangeHandler(DataChangeHandler_Integer handler) {
        this->integerEvent = handler;
    }
    
private:
    int rank;
    string suit;
    DataChangeHandler event = nullptr;
    DataChangeHandler_Integer integerEvent = nullptr;
    
};
#endif /* Card_h */
