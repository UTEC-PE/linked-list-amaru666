//
// Created by damin on 21/08/18.
//

#ifndef ADE_NODE_H
#define ADE_NODE_H


template <typename T>
struct Node {
    T data;
    struct Node* next;

    void killSelf();
};

template <typename T>
void Node<T>::killSelf() {
    if (next) {
        next->killSelf();
    }

    delete this;
}

#endif //ADE_NODE_H
