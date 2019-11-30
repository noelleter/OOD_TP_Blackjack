//
//  View.h
//  MVC_test
//
//  Created by 김노은 on 29/11/2019.
//  Copyright © 2019 Noeun-Kim. All rights reserved.
//

#ifndef View_h
#define View_h

#include <stdio.h>
#include <iostream>
#include "model.h"
#include "Deck.h"

#pragma once

using namespace std;

class View {
public:
    View(const Model &model) {
        this->model = model;
    }
    View(const Deck &deck) {
        this->deck = deck;
    }
    View() {}
    void SetModel(const Model &model) {
        this->model = model;
    }
    void Render() {
        std::cout << "Model Data = " << model.Data() << endl;
    }
    void genDeck() {
        cout << "! Deck Generated: " << this->deck.Number() << " deck, " << this->deck.getTotalCard() << " cards" << endl;
    }
private:
    Model model;
    Deck deck;
};
#endif /* View_h */
