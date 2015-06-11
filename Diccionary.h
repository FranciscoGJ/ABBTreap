//
// Created by Francisco on 29-05-2015.
//

#ifndef TAREA2ESTRUCTURA_DICCIONARY_H
#define TAREA2ESTRUCTURA_DICCIONARY_H

#include <iostream>
#include "Treap.h"

using namespace std;

template <typename type, typename k, typename v>
class DiccionarioPrioridad{

public:
    type m_tipo;

    DiccionarioPrioridad() {

        type* m_tipo = new type();

    }
    virtual ~DiccionarioPrioridad() { }

    void Insert(k key, v value, int priority){

        m_tipo.Insert(key,value,priority);
    }

    void Delete(k key) {

        m_tipo.Erase(key);
    }
    v Search(k key){

        return m_tipo.Search(key);

    }

    v GetTop(){
        return m_tipo.GetTop();
    }

    v pop(){

        return m_tipo.pop();

    }


};

#endif //TAREA2ESTRUCTURA_DICCIONARY_H
