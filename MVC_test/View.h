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
#pragma once
// View is responsible to present data to users
class View {
public:
    View(const Model &model) {
        this->model = model;
    }
    View() {}
    void SetModel(const Model &model) {
        this->model = model;
    }
    void Render() {
        std::cout << "Model Data = " << model.Data() << endl;
    }
private:
    Model model;
};
#endif /* View_h */
