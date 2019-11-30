//
//  main.cpp
//  MVC_test
//
//  Created by 김노은 on 29/11/2019.
//  Copyright © 2019 Noeun-Kim. All rights reserved.
//

#include <iostream>

#include "Game.cpp"
#include "Deck.h"
#include "Card.h"
#include "Hand.h"
#include "Player.h"
#include "Dealer.h"


using namespace std;
void DataChange(string data) {
    cout << "Data Changes: " << data <<endl;
}

int main() {
    /*
    Model model("Model");
    View view(model);
    model.RegisterDataChangeHandler(&DataChange);
    Controller controller(model, view);
    controller.OnLoad();
    model.SetData("Changes");
    */
    
    
    Deck* deck = new Deck(3);
    Hand* hand = new Hand(*deck);
    
    Game game = *new Game(*deck);
    
    game.start();
    return 0;
}
