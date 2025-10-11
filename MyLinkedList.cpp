// José Arturo Mitre García A00228334
// Alejandro Moctezuma Manrique A01614778
// Isaac Esaú Vega Reynaga A01647044

#include "MyLinkedList.h"

using namespace std;

//Complejidad: O(1)
MyLinkedList::MyLinkedList(){
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;
}
//Complejidad: O(n)
MyLinkedList::~MyLinkedList(){
    MyNodoLL* actualNode = head;
    MyNodoLL* nextNode;
    for (int i = 0; i < size; i++)
    {
        nextNode = actualNode->next;
        delete actualNode;
        actualNode = nextNode;
    }
}
//Complejidad: O(1)
int MyLinkedList::length(){
    return this->size;
}
//Complejidad: O(n)
MyNodoLL* MyLinkedList::getAtNode(int pos){
    MyNodoLL* actualNode = head;
    for (int i = 0; i < pos; i++){
        actualNode = actualNode->next;
    }
    return actualNode;
}
//Complejidad: Peor de los casos: O(n)
FailedRequest* MyLinkedList::getAt(int pos){
    MyNodoLL* actualNode = head;
    for (int i = 0; i < pos; i++){
        actualNode = actualNode->next;
    }
    return actualNode->request;
}
//Complejidad: O(1)
void MyLinkedList::insertLast(double days, string time, string ip, string reason, string month){
    if (this->size == 0){
        head = new MyNodoLL(days, time, ip, reason, month);
        tail = head;
    }
    else{
        MyNodoLL* newNode = new MyNodoLL(days, time, ip, reason, month);
        this->tail->next = newNode;
        this->tail = newNode;
    }
    this->size++;
}
//Complejidad: O(1)
void MyLinkedList::insertLast(FailedRequest* request){
    if (this->size == 0){
        head = new MyNodoLL(request);
        tail = head;
    }
    else{
        MyNodoLL* newNode = new MyNodoLL(request);
        this->tail->next = newNode;
        this->tail = newNode;
    }
    this->size++;
}

//Complejidad: Peor de los casos: O(n)
void MyLinkedList::setAt(int pos, FailedRequest* request){
    MyNodoLL* selection = head;
    for (int i = 0; i < pos; i++){
        selection = selection->next;
    }
    selection->request = request;
}
