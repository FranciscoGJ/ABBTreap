//
// Created by Francisco on 27-05-2015.
//

#ifndef TAREA2ESTRUCTURA_NODE_H
#define TAREA2ESTRUCTURA_NODE_H

#include <iostream>
using namespace std;

template <typename k, typename  v>
class Node{

public:
    k key;
    v value;
    int priority;
    Node<k,v>* m_right;
    Node<k,v>* m_left;


    Node(k key, v value, int priority) : key(key), value(value), priority(priority), m_right(nullptr),
                                                           m_left(nullptr) { }

    virtual ~Node() { }

};
#endif //TAREA2ESTRUCTURA_NODE_H
