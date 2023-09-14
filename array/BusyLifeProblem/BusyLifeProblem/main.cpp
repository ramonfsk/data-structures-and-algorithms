//
//  main.cpp
//  BusyLifeProblem
//
//  Created by Ramon Ferreira on 14/09/23.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool activityCompare(pair<int, int> a, pair<int, int>  b) {
    return a.second < b.second;
}

int countActivites(vector<pair<int,int> > activities) {
    sort(activities.begin(), activities.end(), activityCompare);

    int pairIndex = 0, qtdActivities = 1;
    
    for (int index = 1; index < activities.size(); index++) {
        if (activities[index].first >= activities[pairIndex].second) {
            qtdActivities++;
            pairIndex = index;
        }
    }
    
    return qtdActivities;
}

int main(int argc, const char * argv[]) {
    vector<pair<int, int>> arr {
        {7, 9},
        {0, 10},
        {4, 5},
        {8, 9},
        {4, 10},
        {5, 7}};
    
    cout << countActivites(arr) << endl;
    
    return 0;
}
