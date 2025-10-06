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
    if (this->size > 0){
        MyNodoLL* actualNode = head;
        MyNodoLL* nextNode;
        for (int i = 0; i < size; i++)
        {
            nextNode = actualNode->next;
            delete actualNode;
            actualNode = nextNode;
        }
    }
}
//Complejidad: O(1)
int MyLinkedList::length(){
    return this->size;
}
//Complejidad: O(1)
string MyLinkedList::firstIP(){
    if (this->size == 0)
    {
        throw invalid_argument("La lista esta vacia");
    }
    return this->head->request->getIp();
}
//Complejidad: O(1)
string MyLinkedList::lastIP(){
    if (this->size == 0)
    {
        throw invalid_argument("La lista esta vacia");
    }
    return this->tail->request->getIp();
}
//Complejidad: Peor de los casos: O(n), mejor de los casos: O(1)
string MyLinkedList::getAtIP(int pos){
    if (this->size == 0)
    {
        throw invalid_argument("La lista esta vacia");
    }
    if (this->size <= pos || pos < 0){
        throw invalid_argument("Posicion invalida/fuera de rango");
    }
    MyNodoLL* actualNode = head;
    for (int i = 0; i < pos; i++){
        actualNode = actualNode->next;
    }
    return actualNode->request->getIp();
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
