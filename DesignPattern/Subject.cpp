//
// Created by Joy Senpai on 2018-06-27.
//

#include "Subject.h"
#include "Observer.h"

void Subject::attach(Observer *obs) {
    m_views.push_back(obs);
}

void Subject::set_val(int value) {
    m_value = value;

}
void Subject::notify() {
    for(int i = 0; i < m_views.size(); i++)
        m_views[i]->update(m_value);
}


