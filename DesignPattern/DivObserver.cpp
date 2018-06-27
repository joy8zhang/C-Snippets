//
// Created by Joy Senpai on 2018-06-27.
//

#include "DivObserver.h"

#include <iostream>

void DivObserver::update(int v) {
    std::cout<<v<<"div"<<m_div<<"is"<<v/m_div<<'\n';
}