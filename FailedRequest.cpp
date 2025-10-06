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

    date = 0;
    date += monthConvertor(month);
    date += days;
    date += hours/24;
    date += (minutes/60)/24;
    date += ((seconds/60)/60)/24;
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
double FailedRequest::getDate(){
    return this->date;
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
