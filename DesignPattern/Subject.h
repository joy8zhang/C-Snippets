//
// Created by Joy Senpai on 2018-06-27.
//

#ifndef DESIGNPATTERN_SUBJECT_H
#define DESIGNPATTERN_SUBJECT_H

#include "Observer.h"
#include <iostream>

class Subject {
private:
    int m_value;
    std::vector m_views;
public:
    void attach(Observer *obs);
    void set_val(int value);
    void notify();

};


#endif //DESIGNPATTERN_SUBJECT_H
