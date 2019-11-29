//
//  Controller.cpp
//  MVC_test
//
//  Created by 김노은 on 29/11/2019.
//  Copyright © 2019 Noeun-Kim. All rights reserved.
//

#include <stdio.h>

#pragma once
#include "model.cpp"
#include "View.cpp"

// Controller combines Model and View
class Controller {
public:
    Controller(const Model &model, const View &view) {
        this->SetModel(model);
        this->SetView(view);
    }
    void SetModel(const Model &model) {
        this->model = model;
    }
    void SetView(const View &view) {
        this->view = view;
    }
    // when application starts
    void OnLoad() {
        this->view.Render();
    }
private:
    Model model;
    View view;
};
