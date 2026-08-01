
#include <bits/stdc++.h>
using namespace std;

bool leap(int year){
    return (((year%4==0 && year%100!=0)) || (year%400==0));
}

string WeekDay(int day, int month, int year)
{   
    // 01/01/0001 => Monday
    long days=0;
	// for(int i=1; i<year; i++){
    //     days += (leap(i)?366:365);
    // }

    days =   (year-1)*365
            + (year-1)/4
            - (year-1)/100
            + (year+1)/400;

    vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for(int i=1; i<month; i++){
        days += daysInMonth[i-1];
        if(i==2 && leap(year)) days++;
    }

    days += day;
    vector<string> week = {
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday"
    };

    return week[days%7];
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int day, month, year;
	cin >> day >> month >> year;
	
	cout << WeekDay(day, month, year);
}
