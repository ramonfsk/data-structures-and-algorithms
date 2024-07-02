//
//  main.cpp
//  DigitalClock
//
//  Created by Ramon Ferreira on 02/07/24.
//

/*
 Digital Clock Exercise

 You are building a logic for a clock that requires you convert absolute time in minutes into a format supported by a digital clock. See examples below.
 
 125 minutes can be displayed as 2:05
 155 minutes can be displayed as 2:35

 (You can assume the maximum value of minutes will be less than 24 X 60)

 Input:
    1180
 Output:
    19:40
 */

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <format>

using namespace std;

string convertToDigitalTime(int minutes) {
    double h = minutes / 60;
    double m = minutes % 60;

    return format("{:02}:{:02}", h, m);
}

//string convertToDigitalTime(int minutes) {
//    double h = minutes / 60;
//    double m = minutes % 60;
//    
//    stringstream ss;
//    ss << setfill('0') << setw(2) << h << ':' << setfill('0') << setw(2) << m;
//    
//    return ss.str();
//}

int main() {
    cout << convertToDigitalTime(1180) << endl;
    
    return 0;
}
