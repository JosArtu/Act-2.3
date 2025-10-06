// José Arturo Mitre García A00228334
// Alejandro Moctezuma Manrique A01614778
// Isaac Esaú Vega Reynaga A01647044

#include "LoginSystem.h"

// Referencias: https://www.youtube.com/watch?v=Re417iwYM84 Lectura de archivos
// Referencias: https://www.geeksforgeeks.org/cpp/substring-in-cpp/ Uso de substr y stoi
// Referencias: https://www.geeksforgeeks.org/cpp/stdstringerase-in-cpp/ Uso de erase
// Referencias: https://www.youtube.com/watch?v=Rfe2Jb2JP-Y escritura de archivos
// Complejidad: O(n log n)
LoginSystem::LoginSystem(){
    double days, hours, minutes, seconds;
    string time, ip, reason, month;
    ifstream rawFile(FileLocation);
    lista = new MyLinkedList();

    while (!rawFile.eof()){
        rawFile >> month;
        rawFile >> days;
        rawFile >> time;
        rawFile >> ip; 

        getline(rawFile, reason);
        reason.erase(0, 1);

        hours = stoi(time.substr(0,2));
        minutes = stoi(time.substr(3,2));
        seconds = stoi(time.substr(6,2));

        lista->insertLast(days, hours, minutes, seconds, time, ip, reason, month);
    }
    
    cout << this->lista->length() << endl;
}
/*
    sortRequests = new SortSystem(FailedRequests);
    delete sortRequests;

    ofstream sortedFile("bitacoraOrdenada1.3-eq8.txt");

    int n = FailedRequests.size();
    for (int i = 0; i < n; i++){
        sortedFile << FailedRequests[i]->getMonth() << " ";
        sortedFile << FailedRequests[i]->getDay() << " ";
        sortedFile << FailedRequests[i]->getTime() << " ";
        sortedFile << FailedRequests[i]->getIp() << " ";
        sortedFile << FailedRequests[i]->getReason() << " ";

        if(i != n - 1){
            sortedFile << "\n";
        }
    }
    //searchRequests = new SearchSystem(FailedRequests);
}
void LoginSystem::searchRequest(string start, string end){
    searchRequests->search(start, end);
}
*/

