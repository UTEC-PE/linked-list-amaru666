//
// Created by damin on 21/08/18.
//

#ifndef ADE_LIST_H
#define ADE_LIST_H


#include <iostream>
#include "Node.h"
#include "Iterator.h"

using namespace std;

template <typename T>
class List {
private:
    Node<T>* head;
    Node<T>* tail;
    int nodes;

    void print_reverse(Node<T>* head);

public:
    List();

    T front() {
        return head->data;
    };
    T back() {
        return tail->data;
    };
    void push_front(T value) {
        Node<T>* nuevo = new Node<T>;
        nuevo->next = head;
        nuevo->data = value;
        head= nuevo;
    };
    void push_back(T value) {
        Node<T>* nuevo = new Node<T>;
        nuevo->data = value;
        nuevo->next = NULL;
        tail->next = nuevo;
        tail = nuevo;
    };
    void pop_front() {

    };
    void pop_back();
    T get(int position);
    void concat(List<T> &other);
    bool empty();
    int size() {

    };
    void print() {
        if(empty()) {
            cout<<"la lista está vacía"<<endl;
        } else {
            Node<T>* temp = head;
            while(temp != NULL) {
                cout<<temp->data<<endl;
                temp = temp->next;
            }
        }
    };
    void print_reverse();
    void clear();
    Iterator<T> begin();
    Iterator<T> end();

    ~List();


};
template <typename T>

#endif //ADE_LIST_H
