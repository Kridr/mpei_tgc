#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//char to int
int perf(char ch) {
  return (int)ch-(int)48;
}

int main() {
    string date = "1900-03-25";
    int day = 0;
    int months[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    //adding only days in current month
    day += perf(date[8])*10 + perf(date[9]);

    //calculate number of months
    int m = perf(date[5])*10 + perf(date[6]);

    //adding all previous months
    for (int i = 0; i < m - 1; i++)
      day += months[i];

    //check for long year
    if ((perf(date[2])*10 + perf(date[3])) % 4 == 0 && (perf(date[6]) + perf(date[5])*10) > 2 && (perf(date[0])*1000 + perf(date[1])*100 + perf(date[2])*10 + perf(date[3])) != 1900)
      day++;

    cout << day << endl;
    return 0;
}
