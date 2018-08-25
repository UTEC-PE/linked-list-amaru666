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
    return 0;
}