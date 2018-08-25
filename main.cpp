#include <iostream>
#include "list.h"


int main() {
    cout << "Hello, World!" << endl;
    List<int> *lista = new List<int> ;

    lista->print();
    lista->push_front(44);
    lista->push_front(55);
    lista->push_front(66);
    lista->print();
    cout<<"front() : "<<lista->front()<<endl;
    cout<<"back() : "<<lista->back()<<endl;


    lista->push_back(22);
    lista->push_back(33);
    lista->push_back(11);
    lista->print();
    cout<<"front() : "<<lista->front()<<endl;
    cout<<"back() : "<<lista->back()<<endl;

    lista->pop_front();
    lista->pop_back();
    lista->print();
    cout<<"front() : "<<lista->front()<<endl;
    cout<<"back() : "<<lista->back()<<endl;

    cout<<"get(2) :"<<lista->get(2)<<endl;


    return 0;
}