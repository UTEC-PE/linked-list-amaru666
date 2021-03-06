//
// Created by damin on 21/08/18.
//

#ifndef ADE_LIST_H
#define ADE_LIST_H


#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
private:
    Node<T>* head;
    Node<T>* tail;
    int nodes;

    void print_reverse(Node<T>* head);

public:
    List():head(NULL),tail(NULL){

    };

    T front() {
        return head->data; // Falta controlar caso vacío
    };
    T back() {
        return tail->data; // Igual que el anterior
    };
    void push_front(T value) {
        Node<T>* nuevo = new Node<T>;
        nuevo->data = value;
        if(empty()) {
            nuevo->next = NULL;
            tail = nuevo;
            head = nuevo;
        } else {
            nuevo->next = head;
            head= nuevo;
        }
    }; //correcto
    void push_back(T value) {
        Node<T>* nuevo = new Node<T>;
        nuevo->data = value;
        nuevo->next = NULL;
        if(empty()) {
            tail = nuevo;
            head = nuevo;
        }else{
            tail->next = nuevo;
            tail = nuevo;
        }
    };
    void pop_front() { // No se controla el caso de lista vacía
        Node<T> *node = new Node<T>;
        node = head->next;
        delete head;
        head = node;
    };
    void pop_back(){ // No se controla el caso de lista vacía
        Node<T> *node = head;
        while(node->next != tail) {
            node = node->next;
            if(node->next == tail) {
                delete tail;
                tail = node;
                tail->next = NULL;
                break;
            }
        }
    };
    T get(int position){
        if(empty()){
            return 0;
        }else{
            int i = 0;
            Node<T> *node = head;
            while(node != NULL) {
                if(i == position)break;
                node=node->next;
                i++;
            }
            return node->data;
        }
    };
    void concat(List<T> *other) { // Se debería poder con referencia &
        if(!other->empty()){
            tail->next = other->head;
            tail = other->tail;
        } else if(empty() && !other->empty()) {
            head = other->head;
            tail = other->tail;
        }
    };
    bool empty() { // No es necesario el ?true:false
        return head==NULL?true:false;
    };
   int size() { // Podría usarse el int nodes para mejorar el tiempo
        int contador = 0;
        if(empty()){
            return contador;
        } else {

            Node<T> *temp = head;
            while(temp != NULL){
                contador++;
                temp = temp->next;
            }
            return contador;
        }
    };
   void print() {
        if(empty()) {
            cout<<"la lista está vacía"<<endl;
        } else {
            Node<T>* temp = head;
            while(temp != NULL) {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
    };
   void print_reverse() { // Podría implementarse mejor con recursión
        if(empty()){
            cout<<"la lista está vacía"<<endl;
        }else{
            int i = size()-1;
            while(i>=0){
                cout<<get(i)<<" ";
                i--;
            }
            cout<<endl;
        }
    };
   void clear() { // No se implementó

    };
    Iterator<T> begin();
    Iterator<T> end();

    ~List(); // No se implementó


};

#endif //ADE_LIST_H