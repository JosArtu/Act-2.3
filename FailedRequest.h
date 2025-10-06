// José Arturo Mitre García A00228334
// Alejandro Moctezuma Manrique A01614778
// Isaac Esaú Vega Reynaga A01647044

#ifndef FAILEDREQUEST_H
#define FAILEDREQUEST_H

#include "string"

using namespace std;

class FailedRequest{
    private:
        double days, hours, minutes, seconds, date;
        string ip, reason, month, time;
    public:
    FailedRequest(string month, double days, string time, double hours, double minutes, double seconds, string ip, string reason);
        double getDay();
        double getDate();
        string getTime();
        string getMonth();
        string getIp();
        string getReason();
        int monthConvertor(string month);
        int getTotalDays();
};
#endif
