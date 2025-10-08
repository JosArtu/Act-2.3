// José Arturo Mitre García A00228334
// Alejandro Moctezuma Manrique A01614778
// Isaac Esaú Vega Reynaga A01647044

#include "SearchSystem.h"
#include "MyLinkedList.h"

// Complejidad: O(n)
void SearchSystem::search(string start, string end){

    double startIpSortValue = this->ipSortValueConvertor(start);
    double endIpSortValue = this->ipSortValueConvertor(end);
    MyNodoLL* startNode, *endNode;
    MyNodoLL*current = requests->getAtNode(0);
    
    for (int i=0;i<requests->length();i++){
        if (current->request->getIpSortValue()>=startIpSortValue){
            break;
        }
        current=current->next;
    }
    startNode = current;
    for (int i=0;i<requests->length();i++){
        if (current->request->getIpSortValue()>=endIpSortValue){
            break;
        }
        current=current->next;
    }
    endNode = current;
    outputSearch(startNode, endNode);
}
// Referencias: https://www.geeksforgeeks.org/cpp/converting-number-to-string-in-cpp/ to_string
// Referencias: https://www.youtube.com/watch?v=Rfe2Jb2JP-Y escritura de archivos
// Complejidad O(n)
void SearchSystem::outputSearch(MyNodoLL* startNode, MyNodoLL* endNode){
    searchNumber++;
    ofstream sortedFile("salida" + to_string(searchNumber) + "-eq8.txt");

    MyNodoLL* actualNode = startNode;
    int n = requests->length();
    while(actualNode != endNode || startNode == endNode){
        sortedFile << actualNode->request->getMonth() << " ";
        sortedFile << actualNode->request->getDay() << " ";
        sortedFile << actualNode->request->getTime() << " ";
        sortedFile << actualNode->request->getIp() << " ";
        sortedFile << actualNode->request->getReason() << " ";

        if (startNode == endNode)
        {
            break;
        }
        if(actualNode->next != endNode){
            sortedFile << "\n";
        }
        if (actualNode->next != nullptr)
        {
            actualNode = actualNode->next;
        }
    }
}

// Referencias: https://www.geeksforgeeks.org/cpp/substring-in-cpp/ Uso de substr y stoi
// Referencias: https://www.geeksforgeeks.org/cpp/stdstringerase-in-cpp/ Uso de erase
// Referencias: https://www.geeksforgeeks.org/cpp/std-find-in-cpp/ Uso de find
//Complejidad: O(1)
double SearchSystem::ipSortValueConvertor(string ip){
    double answer;

    int pos = ip.find(".");
    double ipNumber1 = stoi(ip.substr(0,pos));
    ip.erase(0,pos+1);

    pos = ip.find(".");
    double ipNumber2 = stoi(ip.substr(0, pos));
    ip.erase(0,pos+1);

    pos = ip.find(".");
    double ipNumber3 = stoi(ip.substr(0, pos));
    ip.erase(0,pos+1);

    pos = ip.find(":");
    double ipNumber4 = stoi(ip.substr(0, pos));
    ip.erase(0,pos+1);

    answer = 0;
    answer += ipNumber1;  
    answer += ipNumber2/100.00;
    answer += ipNumber3/100000.00;
    answer += ipNumber4/100000000.00;

    return answer;
}