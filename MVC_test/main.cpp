//
//  main.cpp
//  MVC_test
//
//  Created by 김노은 on 29/11/2019.
//  Copyright © 2019 Noeun-Kim. All rights reserved.
//

#include <iostream>
#include "Model.h"
#include "Deck.h"
#include "Card.h"
#include "View.h"
#include "Controller.h"

using namespace std;
void DataChange(string data) {
    cout << "Data Changes: " << data <<endl;
}

int main() {
    Model model("Model");
    Card card(14, "MODEL");
    Deck deck(1);
    View view(model);
    // register the data-change event
    model.RegisterDataChangeHandler(&DataChange);
    
    // binds model and view.
    Controller controller(model, view);
    // when application starts or button is clicked or form is shown...
    controller.OnLoad();
    model.SetData("Changes"); // this should trigger View to render
    return 0;
}
