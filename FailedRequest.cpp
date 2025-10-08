// José Arturo Mitre García A00228334
// Alejandro Moctezuma Manrique A01614778
// Isaac Esaú Vega Reynaga A01647044

#include "FailedRequest.h"

// Complejidad O(1)
FailedRequest::FailedRequest(string month, double days, string time, double hours, double minutes, double seconds, string ip, string reason){
    this->month = month;
    this->days = days;
    this->time = time;
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
    this->ip = ip;
    this->reason = reason;
    
    string ipCopy = ip;
    int pos;

    pos = ipCopy.find(".");
    double ipNumber1 = stoi(ipCopy.substr(0,pos));
    ipCopy.erase(0,pos+1);

    pos = ipCopy.find(".");
    double ipNumber2 = stoi(ipCopy.substr(0, pos));
    ipCopy.erase(0,pos+1);

    pos = ipCopy.find(".");
    double ipNumber3 = stoi(ipCopy.substr(0, pos));
    ipCopy.erase(0,pos+1);

    pos = ipCopy.find(":");
    double ipNumber4 = stoi(ipCopy.substr(0, pos));
    ipCopy.erase(0,pos+1);

    double port = stoi(ipCopy);


    this->ipSortValue = 0;
    this->ipSortValue += ipNumber1;  
    this->ipSortValue += ipNumber2/100.00;
    this->ipSortValue += ipNumber3/100000.00;
    this->ipSortValue += ipNumber4/100000000.00;
    this->ipSortValue += port/1000000000000.00;
}
//Complejidad O(1)
double FailedRequest::getDay(){
    return this->days;
}
//Complejidad O(1)
string FailedRequest::getMonth(){
    return this->month;
}
//Complejidad O(1)
string FailedRequest::getTime(){
    return this->time;
}
//Complejidad O(1)
double FailedRequest::getIpSortValue(){
    return this->ipSortValue;
}
//Complejidad O(1)
string FailedRequest::getIp(){
    return this->ip;
}
//Complejidad O(1)
string FailedRequest::getReason(){
    return this->reason;
}
//Complejidad O(1)
int FailedRequest::monthConvertor(string month){
    if (month == "Jun")
    {
        return 6*30;
    }
    else if (month == "Jul"){
        return 7*30;
    }
    else if (month == "Aug"){
        return 8*30;
    }
    else if (month == "Sep"){
        return 9*30;
    }
    else if (month == "Oct"){
        return 10*30;
    }
    return 0;
}
//Complejidad O(1)
int FailedRequest::getTotalDays(){
    return monthConvertor(month) + days;
}