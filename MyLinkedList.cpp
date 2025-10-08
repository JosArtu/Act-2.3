//José Arturo Mitre Garcia
//A00228334
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
MyNodoLL* MyLinkedList::getAtNode(int pos){
    MyNodoLL* actualNode = head;
    for (int i = 0; i < pos; i++){
        actualNode = actualNode->next;
    }
    return actualNode;
}
//Complejidad: Peor de los casos: O(n), mejor de los casos: O(1)
FailedRequest* MyLinkedList::getAt(int pos){
    MyNodoLL* actualNode = head;
    for (int i = 0; i < pos; i++){
        actualNode = actualNode->next;
    }
    return actualNode->request;
}
FailedRequest* MyLinkedList::getAt(int pos, MyNodoLL* actualNode){
    return actualNode->next->request;
}
//Complejidad: O(1)
void MyLinkedList::insertLast(double days, double hours, double minutes, double seconds, string time, string ip, string reason, string month){
    if (this->size == 0){
        head = new MyNodoLL(days, hours, minutes, seconds, time, ip, reason, month);
        tail = head;
    }
    else{
        MyNodoLL* newNode = new MyNodoLL(days, hours, minutes, seconds, time, ip, reason, month);
        this->tail->next = newNode;
        this->tail = newNode;
    }
    this->size++;
}

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

//Complejidad: Peor de los casos: O(n), mejor de los casos: O(1)
void MyLinkedList::setAt(int pos, FailedRequest* request){
    MyNodoLL* selection = head;
    for (int i = 0; i < pos; i++){
        selection = selection->next;
    }
    selection->request = request;
}
