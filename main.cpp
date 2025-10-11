// José Arturo Mitre García A00228334
// Alejandro Moctezuma Manrique A01614778
// Isaac Esaú Vega Reynaga A01647044

#include <iostream>
#include "MyLinkedList.h"
#include "MyLinkedList.cpp"
#include "LoginSystem.h"
#include "LoginSystem.cpp"
#include "FailedRequest.h"
#include "FailedRequest.cpp"
#include "SortSystem.h"
#include "SortSystem.cpp"
#include "SearchSystem.h"
#include "SearchSystem.cpp"

int main(){
    LoginSystem system1;
    string start, end, option;

    //referencias: https://www.geeksforgeeks.org/cpp/getline-string-c/ Getline para tomar todo el input con espacios
    do
    {
        cout << "IP de inicio: ";
        getline(cin, start);
        cout << "IP de fin: ";
        getline(cin, end);
        system1.searchRequest(start, end);

        cout << "Deseas hacer otra busqueda? (si/no): ";
        getline(cin, option);

    }
    while(option == "si");
    
    return 0;
}