//
// Created by Joy Senpai on 2018-06-27.
//

#ifndef DESIGNPATTERN_DIVOBSERVER_H
#define DESIGNPATTERN_DIVOBSERVER_H


#include "Subject.h"

class DivObserver {
private:
    int m_div;
public:
    DivObserver(Subject *model, int div){
        model->attach(this);
        m_div = div;
    }
    void update(int v);
};


#endif //DESIGNPATTERN_DIVOBSERVER_H
