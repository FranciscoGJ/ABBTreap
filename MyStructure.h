//
// Created by Francisco on 29-05-2015.
//Diccionario Priorida Utilizando Map y Unordered_Map

#ifndef TAREA2ESTRUCTURA_MYSTRUCTURE_H
#define TAREA2ESTRUCTURA_MYSTRUCTURE_H

#include <iostream>
#include <unordered_map>
#include <map>
#include "Diccionary.h"

using namespace std;

template <typename k, typename v>
class MyStructure{

public:

    k key;
    v value;
    unordered_map<k,v> diccionario;
    map<float,k> prior;
    MyStructure() : key(key), value(value) {

    }

    virtual ~MyStructure() { }

    void Insert(k key, v value,float priority){

        prior.insert(std::make_pair(priority,key));
        diccionario.insert(std::make_pair(key,value));
    }
    v Search(k key){

        return diccionario[key];
    }

    v GetTop(){

        auto iter = prior.begin();
        return diccionario[iter->second];
    }

    void Erase(k key){

        auto it = prior.begin();
        while(true){

            if(it->second == key){
                prior.erase(it->first);
                diccionario.erase(key);
                break;
            }else if(it == prior.end()){
                break;
            }else{
                ++it;
            }
        }
    }

    v pop(){

        auto it = prior.begin();
        v valor = diccionario[it->second];
        diccionario.erase(it->second);
        prior.erase(it->first);
        return valor;
    }
};

#endif //TAREA2ESTRUCTURA_MYSTRUCTURE_H
