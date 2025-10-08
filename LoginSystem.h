// José Arturo Mitre García A00228334
// Alejandro Moctezuma Manrique A01614778
// Isaac Esaú Vega Reynaga A01647044

#ifndef LOGINSYSTEM_H
#define LOGINSYSTEM_H

#include "FailedRequest.h"
#include "MyLinkedList.h"
#include "SortSystem.h"
//#include "SearchSystem.h"
#include <fstream>
#include <vector>

using namespace std;

class LoginSystem{
    private:
        MyLinkedList* lista;
        string FileLocation = "bitacora.txt";
        SortSystem *sortRequests;
        //SearchSystem *searchRequests;
    public:
        LoginSystem();
        void searchRequest(string start, string end);
};

#endif
