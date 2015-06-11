//
// Created by Francisco on 27-05-2015.
//

#ifndef TAREA2ESTRUCTURA_TREAP_H
#define TAREA2ESTRUCTURA_TREAP_H

#include <iostream>
#include "Node.h"
#include <queue>

using namespace std;

template <typename k, typename v >

class Treap{

public:
    Node<k,v>* m_root;
    Node<k,v>* m_subTree;
    Treap() : m_root(nullptr), m_subTree(nullptr) { }

    virtual ~Treap() { }

    void Insert(k key,v value, int priority){

        if(m_root == nullptr){
            m_root = new Node<k,v>(key, value, priority);
        }else if(priority > m_root->priority) {
            if(key > m_root->key){
                Node<k,v>* temp = new Node<k,v>(key,value,priority);
                if(m_root->m_left == nullptr && m_root->m_right == nullptr){
                    temp->m_left = m_root;
                    m_root = temp;

                }else if(m_root->m_right != nullptr && m_root->m_right->key > key){
                    temp->m_right = m_root->m_right;
                    m_root->m_right = nullptr;
                    temp->m_left = m_root;
                    m_root = temp;

                }else{
                    temp->m_left = m_root;
                    m_root = temp;
                }
            }
            if(key < m_root->key){
                Node<k,v>* temp = new Node<k,v>(key,value,priority);
                if(m_root->m_left == nullptr && m_root->m_right == nullptr){
                    temp->m_right = m_root;
                    m_root = temp;

                }else if(m_root->m_left != nullptr && m_root->m_left->key < key){
                    temp->m_left = m_root->m_left;
                    m_root->m_left = nullptr;
                    temp->m_right = m_root;
                    m_root = temp;

                }else{
                    temp->m_right = m_root;
                    m_root = temp;
                }
            }
        }else{

            Insertar(key,value,priority,m_root,m_root);
        }
    }

    void Insertar(k key, v value, int priority, Node<k,v>* ref, Node<k,v>* refAnt){

        if(priority <= ref->priority){

            if(key < ref->key){
                if(ref->m_left == nullptr){
                    ref->m_left = new Node<k,v>(key, value, priority);
                }else{
                    refAnt = ref;
                    Insertar(key,value,priority,ref->m_left,refAnt);
                }
            }
            if(key > ref->key){
                if(ref->m_right == nullptr){
                    ref->m_right = new Node<k,v>(key, value, priority);
                }else{
                    refAnt = ref;
                    Insertar(key,value,priority,ref->m_right,refAnt);
                }
            }
        }
        if(priority > ref->priority){

            if(refAnt->key > key){
                if(key > ref->key){
                    Node<k,v>* temp = new Node<k,v>(key,value,priority);
                    if(ref->m_left == nullptr && ref->m_right == nullptr){
                        temp->m_left = ref;
                        refAnt->m_left = temp;
                    }else if(ref->m_right != nullptr && ref->m_right->key > key){
                        temp->m_right = ref->m_right;
                        ref->m_right = nullptr;
                        temp->m_left = ref;
                        refAnt->m_left = temp;
                    }else{
                        temp->m_left = ref;
                        refAnt->m_left = temp;
                    }
                }
                if(key < ref->key){
                    Node<k,v>* temp = new Node<k,v>(key,value,priority);
                    if(ref->m_left == nullptr && ref->m_right == nullptr){
                        temp->m_right = ref;
                        refAnt->m_left = temp;
                    }else if(ref->m_left != nullptr && ref->m_left->key < key){
                        temp->m_left = ref->m_left;
                        ref->m_left = nullptr;
                        temp->m_right = ref;
                        refAnt->m_left = temp;
                    }else{
                        temp->m_right = ref;
                        refAnt->m_left = temp;
                    }
                }
            }
            if(refAnt->key < key){
                if(key > ref->key){
                    Node<k,v>* temp = new Node<k,v>(key,value,priority);
                    if(ref->m_left == nullptr && ref->m_right == nullptr){
                        temp->m_left = ref;
                        refAnt->m_right = temp;
                    }else if(ref->m_right != nullptr && ref->m_right->key > key){
                        temp->m_right = ref->m_right;
                        ref->m_right = nullptr;
                        temp->m_left = ref;
                        refAnt->m_right = temp;
                    }else{
                        temp->m_left = ref;
                        refAnt->m_right = temp;
                    }
                }
                if(key < ref->key){
                    Node<k,v>* temp = new Node<k,v>(key,value,priority);
                    if(ref->m_left == nullptr && ref->m_right == nullptr){
                        temp->m_right = ref;
                        refAnt->m_right = temp;
                    }else if(ref->m_left != nullptr && ref->m_left->key < key){
                        temp->m_left = ref->m_left;
                        ref->m_left = nullptr;
                        temp->m_right = ref;
                        refAnt->m_right = temp;
                    }else{
                        temp->m_right = ref;
                        refAnt->m_right = temp;
                    }
                }
            }

        }

    }

    v Search(k key){                                            //Esta función retorna el valor asociado a la llave que deseo buscar

        if(m_root == nullptr)
            return v();
        else{

            Node<k,v>* aux = m_root;
            while(aux != nullptr){

                if(aux->key == key){
                    return aux->value;
                }
                if(key > aux->key){
                    aux = aux->m_right;
                    continue;
                }
                if(key < aux->key){
                    aux = aux->m_left;
                    continue;
                }
            }
            if(aux == nullptr){
                return v();
            }

        }
    }

    v pop(){

        if(m_root == nullptr){
            return v();
        }else if(m_root->m_left == nullptr && m_root->m_right == nullptr){
            v valor = m_root->value;
            delete m_root;
            return valor;
        }else if(m_root->m_right == nullptr){
            Node<k,v>* auxBorrar = m_root;
            m_root = m_root->m_left;
            v valor = auxBorrar->value;
            delete auxBorrar;
            return valor;
        }else if(m_root->m_left == nullptr) {
            Node<k, v> *auxBorrar = m_root;
            m_root = m_root->m_right;
            v valor = auxBorrar->value;
            delete auxBorrar;
            return valor;
        }else{

            Node<k,v>* auxBorrar = m_root;
            if(auxBorrar->m_right->priority > auxBorrar->m_left->priority){
                if(auxBorrar->m_right->m_left == nullptr){
                    auxBorrar->m_right->m_left = auxBorrar->m_left;
                    m_root = auxBorrar->m_right;
                    v valor = auxBorrar->value;
                    delete auxBorrar;
                    return valor;
                }else{

                    queue<Node<k,v>*> cola;
                    queue<Node<k,v>*> subTree;
                    cola.push(m_root->m_left);
                    while(!cola.empty()) {                                                  //En esta seccion inserto el sub arbol del nodo a eliminar en una cola
                        Node<k,v>* aux1 = cola.front();
                        cola.pop();
                        if (aux1->m_left != nullptr) {
                            cola.push(aux1->m_left);
                            subTree.push(aux1->m_left);
                        }
                        if (aux1->m_right != nullptr) {
                            cola.push(aux1->m_right);
                            subTree.push(aux1->m_right);
                        }

                    }
                    m_root = m_root->m_right;
                    delete (auxBorrar);                                                         //Una vez Guardada la cola con el sub arbol del nodo a eliminar, se elimina dicho nodo
                    while(!subTree.empty()){                                                    //en la siguiente seccion se vuelve a insertar los hijos del nodo eliminado el el Treap
                        m_subTree = subTree.front();
                        subTree.pop();
                        Insert(m_subTree->key,m_subTree->value,m_subTree->priority);
                        cout << m_subTree->key << endl;
                    }

                }
            }else{
                if(auxBorrar->m_left->m_right == nullptr){
                    auxBorrar->m_left->m_right = auxBorrar->m_right;
                    m_root = auxBorrar->m_left;
                    v valor = auxBorrar->value;
                    delete auxBorrar;
                    return valor;
                }else{

                    queue<Node<k,v>*> cola;
                    queue<Node<k,v>*> subTree;
                    cola.push(m_root->m_right);
                    while(!cola.empty()) {                                                  //En esta seccion inserto el sub arbol del nodo a eliminar en una cola
                        Node<k,v>* aux1 = cola.front();
                        cola.pop();
                        if (aux1->m_left != nullptr) {
                            cola.push(aux1->m_left);
                            subTree.push(aux1->m_left);
                        }
                        if (aux1->m_right != nullptr) {
                            cola.push(aux1->m_right);
                            subTree.push(aux1->m_right);
                        }
                    }
                    m_root = m_root->m_right;
                    delete (auxBorrar);                                                         //Una vez Guardada la cola con el sub arbol del nodo a eliminar, se elimina dicho nodo
                    while(!subTree.empty()){                                                    //en la siguiente seccion se vuelve a insertar los hijos del nodo eliminado el el Treap
                        m_subTree = subTree.front();
                        subTree.pop();
                        Insert(m_subTree->key,m_subTree->value,m_subTree->priority);
                    }

                }
            }
        }

    }


    void Erase(k key) {                                                                //funcion que elimina un nodo del Treap

        if (m_root == nullptr){

            cout << "root == null" << endl;
        }else if(key == m_root->key){

            pop();

        }else{
            Node<k,v>* aux = m_root;
            Node<k,v>* aux2 = m_root;

            while(key != aux->key){
                if(key > aux->key){
                    aux2 = aux;
                    aux = aux->m_right;
                }else if(key < aux->key){
                    aux2 = aux;
                    aux = aux->m_left;
                }else{
                    if(aux == nullptr){
                        break;
                    }
                }
            }
            if(key > aux2->key){                                                    //Se elimina la referencia del Nodo padre al nodo a eliminar
                aux2->m_right = nullptr;
            }else{
                aux2->m_left = nullptr;
            }

            Node<k,v>* auxBorrar = aux;
            queue<Node<k,v>*> cola;
            queue<Node<k,v>*> subTree;
            cola.push(aux);
            while(!cola.empty()) {                                                  //En esta seccion inserto el sub arbol del nodo a eliminar en una cola
                Node<k,v>* aux1 = cola.front();
                cola.pop();
                if (aux1->m_left != nullptr) {
                    cola.push(aux1->m_left);
                    subTree.push(aux1->m_left);
                }
                if (aux1->m_right != nullptr) {
                    cola.push(aux1->m_right);
                    subTree.push(aux1->m_right);
                }
            }
            delete (auxBorrar);                                                         //Una vez Guardada la cola con el sub arbol del nodo a eliminar, se elimina dicho nodo
            while(!subTree.empty()){                                                    //en la siguiente seccion se vuelve a insertar los hijos del nodo eliminado el el Treap
                m_subTree = subTree.front();
                subTree.pop();
                    Insert(m_subTree->key,m_subTree->value,m_subTree->priority);
            }
        }
    }

    v GetTop(){

        return m_root->value;
    }

};

#endif //TAREA2ESTRUCTURA_TREAP_H
