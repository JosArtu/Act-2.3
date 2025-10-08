// José Arturo Mitre García A00228334
// Alejandro Moctezuma Manrique A01614778
// Isaac Esaú Vega Reynaga A01647044

#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include <iostream>
#include "FailedRequest.h"
using namespace std;

struct MyNodoLL{
    MyNodoLL* next;
    FailedRequest* request;

    MyNodoLL(double days, string time, string ip, string reason, string month, MyNodoLL* next){
        this->request = new FailedRequest(month, days, time, ip, reason);
    }
    MyNodoLL(double days, string time, string ip, string reason, string month):MyNodoLL(days, time, ip, reason, month, nullptr){};
    MyNodoLL(FailedRequest* request):request(request){
        next = nullptr;
    }
};



class MyLinkedList{
    public:
        int size;
        MyNodoLL* head;
        MyNodoLL* tail;
        MyLinkedList();
        ~MyLinkedList();
        int length();
        MyNodoLL* getAtNode(int pos);
        FailedRequest* getAt(int pos); 
        FailedRequest* getAt(int pos, MyNodoLL* actualNode); 
        void insertLast(double days, string time, string ip, string reason, string month);
        void insertLast(FailedRequest* request);
        void setAt(int pos, FailedRequest* request);
};
#endif