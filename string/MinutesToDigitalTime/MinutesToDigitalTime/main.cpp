//
//  main.cpp
//  MinutesToDigitalTime
//
//  Created by Ramon Ferreira on 13/06/24.
//

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <format>

using namespace std;

//string convertToDigitalTime(int minutes) {
//    double h = minutes / 60;
//    double m = minutes % 60;
//    
//    return format("{:02}:{:02}", h, m);
//}

string convertToDigitalTime(int minutes) {
    double h = minutes / 60;
    double m = minutes % 60;
    
    stringstream ss;
    ss << setfill('0') << setw(2) << h << ':' << setfill('0') << setw(2) << m;
    
    return ss.str();
}

int main() {
    cout << convertToDigitalTime(1180) << endl;
    
    return 0;
}
