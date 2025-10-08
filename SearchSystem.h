// José Arturo Mitre García A00228334
// Alejandro Moctezuma Manrique A01614778
// Isaac Esaú Vega Reynaga A01647044

#ifndef SEARCHSYSTEM_H
#define SEARCHSYSTEM_H

#include "FailedRequest.h"
#include "MyLinkedList.h"
#include <fstream>

using namespace std;

class SearchSystem{
    private:
        int searchNumber = 0;
        MyLinkedList* requests;
        int monthConvertor(string month);
    public:
        SearchSystem(MyLinkedList* requests):requests(requests){};
        void search(string start, string end);
        void outputSearch(MyNodoLL *start, MyNodoLL *end);
        double ipSortValueConvertor(string ip);
};
#endif
