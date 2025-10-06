//José Arturo Mitre Garcia
//A00228334
#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include <iostream>
#include "FailedRequest.h"
using namespace std;

struct MyNodoLL{
    MyNodoLL* next;
    FailedRequest* request;

    MyNodoLL(double days, double hours, double minutes, double seconds, string time, string ip, string reason, string month, MyNodoLL* next){
        this->request = new FailedRequest(month, days, time, hours, minutes, seconds, ip, reason);
    }
    MyNodoLL(double days, double hours, double minutes, double seconds, string time, string ip, string reason, string month):MyNodoLL(days, hours, minutes, seconds, time, ip, reason, month, nullptr){};
};



class MyLinkedList{
    public:
        int size;
        MyNodoLL* head;
        MyNodoLL* tail;
        MyLinkedList();
        ~MyLinkedList();
        int length();
        string firstIP(); //Exc invalid_argument
        string lastIP(); //Exc invalid_argument
        string getAtIP(int pos); //Exc invalid_argument
        void insertLast(double days, double hours, double minutes, double seconds, string time, string ip, string reason, string month);
};
#endif