//
//  Controller.h
//  MVC_test
//
//  Created by 김노은 on 29/11/2019.
//  Copyright © 2019 Noeun-Kim. All rights reserved.
//

#ifndef Controller_h
#define Controller_h

#include <stdio.h>

#pragma once
#include "Model.h"
#include "View.h"

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

#endif /* Controller_h */
