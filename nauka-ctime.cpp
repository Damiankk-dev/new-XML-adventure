#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
//const string currentDateTime() {
//    time_t     now = time(0);
//    struct tm  tstruct;
//    char       buf[80];
//    tstruct = *localtime(&now);
//    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
//    // for more information about date/time format
//    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
//
//    return buf;
//}
bool isLeap(unsigned year) {
    if (((year%4 == 0)&& (year%100 != 0)) || (year%400 == 0)) return true;
    else return false ;
}

void compareDate(string, string);
time_t convertString2TimeFormat(string);
int main() {
//    cout << "currentDateTime()=" << currentDateTime() << endl;


    time_t ttime = time(0); //type time_t is arithmetic type capable of representing times
    // function time() returns current of the system as time since Epoch
    char* dt = ctime(&ttime); //ctime() converts time_t value to string (saved as char*)
    cout << "The current local date and time is: " << dt << endl;
    tm* gmt_time = gmtime(&ttime); // tm is struct which contains time components
    dt = asctime(gmt_time); // asctime converts tm to textual representation
    cout << "The current UTC date and time is:"<< dt << endl;
    cout << "Number of seconds elapsed since January 1, 1990:" << ttime << endl;
    tm* local_time = localtime(&ttime); //localtime() converts time_t format to calendar time ( returns pointer to tm struct)

    cout << "Year: "<<1900 + local_time->tm_year << endl;
    cout << "Month: "<<1 + local_time->tm_mon<< endl;
    cout << "Day: "<< local_time->tm_mday << endl;
    cout << "Time: "<<local_time->tm_hour << ":";
    cout << local_time->tm_min << ":";
    cout << local_time->tm_sec << endl;

    int monthNum = 3 - local_time->tm_mon + 2;
    int yearNum = 1900 + local_time->tm_year -21;
    cout << "Month: "<<monthNum<< endl;
    cout << "Year: "<<yearNum<< endl;
    int daysInMonth = 0;
    if ( monthNum < 8 ) {
        if ( monthNum % 2 != 0 ) {
            daysInMonth = 31;
        } else if ( monthNum == 2 ) {
            if ( isLeap(yearNum) ) daysInMonth = 29;
            else daysInMonth = 28;
        } else {
            daysInMonth = 30;
        }
    } else {
        if ( monthNum % 2 != 0 ) {
            daysInMonth = 30;
        } else {
            daysInMonth = 31;
        }
    }
    cout << "\nIn actual month we have: " << daysInMonth << " days\n";


    time_t time1;
    time_t time2;
    struct tm * timeinfo;
    struct tm * timeinfo2;
    int year, month,day, year2, month2,day2;
    string weekday[] = { "Sunday", "Monday",
                         "Tuesday", "Wednesday",
                         "Thursday", "Friday", "Saturday"
                       };

    /* prompt user for date */
//  cout << "data pierwsza:\n";
//  cout << "Enter year: ";
//  cin >> year;
//  cout << "Enter month: ";
//  cin >> month;
//  cout << "Enter day: ";
//  cin >> day;
//
//  cout << "data druga:\n";
//  cout << "Enter year: ";
//  cin >> year2;
//  cout << "Enter month: ";
//  cin >> month2;
//  cout << "Enter day: ";
//  cin >> day2;

    string date1, date2;

//    getline(cin, date1);
//    getline(cin, date2);
    date1 = "2021-12-21";
    date2 = "2022-12-21";
    cout << "Date1: " << date1  << endl;
    cout << "Date2: " << date2  << endl;
    compareDate(date1, date2);
    date2 = "2021-12-21";
    date1 = "2022-12-21";
    cout << "Date1: " << date1  << endl;
    cout << "Date2: " << date2  << endl;
    compareDate(date1, date2);
    cin >> year;
    year = stoi(date1.substr(0,4));
    month = stoi(date1.substr(5,2));
    day = stoi(date1.substr(8,2));

    /* get current timeinfo and modify it to the user's choice */
    time (&time1);
    cout << "Time1 before convert: " << time1  << endl;
    time1 = convertString2TimeFormat(date1);
    cout << "Time1 after convert: " << time1 << endl;
    cin >> year;
    time (&time1);
    timeinfo = localtime ( &time1 );
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;
    time1 = mktime(timeinfo);
    cout << "Time: " << asctime(timeinfo) << endl;
    cin >> year;
    time (&time2);
    timeinfo2 = localtime ( &time2 );
    timeinfo2->tm_year = year2 - 1900;
    timeinfo2->tm_mon = month2 - 1;
    timeinfo2->tm_mday = day2;

    /* call mktime: timeinfo->tm_wday will be set */
    cout << "Time: " << time1 << endl;
    cout << "Time: " << asctime(timeinfo) << endl;
    time2 = mktime(timeinfo2);
    cout << "Time2: " << time2 << endl;
    cout << "Time2: " << asctime(timeinfo2) << endl;

    double timeDifference = difftime(time1, time2);
    cout << "Time diefference: " << timeDifference << endl;
    if ( timeDifference > 0 ) cout << "Druga data jest starsza\n";
    else cout << "Pierwsza data jest starsza\n";


    cout << "That day is a " << weekday[timeinfo->tm_wday] << ".\n";

    return 0;
}


void compareDate(string date1, string date2){
    time_t ttime1;
    time_t ttime2;
    ttime1 = convertString2TimeFormat(date1);
    ttime2 = convertString2TimeFormat(date2);
    double timeDifference = difftime(ttime1, ttime2);
    if ( timeDifference > 0 ) cout << "Date2 is older\n";
    else cout << "Date1 is older\n";

}

time_t convertString2TimeFormat(string date){
    //date format yyyy-mm-dd
    int year, month,day;
    time_t ttime;
    struct tm * timeinfo;
    year = stoi(date.substr(0,4));
    month = stoi(date.substr(5,2));
    day = stoi(date.substr(8,2));
    time(&ttime);
    timeinfo = localtime (&ttime);
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;
    return mktime(timeinfo);
}
