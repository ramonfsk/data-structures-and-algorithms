//
//  main.cpp
//  BusyLife
//
//  Created by Ramon Ferreira on 01/07/24.
//

/*
 Busy Life Exercise

 You are actually very busy person. You have a long list of activities. Your aim is to finish much as activities as possible.

 In the given figure, if you go to date with crush, you cannot participate in the coding contest and you can’t watch the movie. Also if you play DotA, you can’t study for the exam. If you study for the exam you can’t sleep peacefully. The maximum number of activities that you can do for this schedule is 3.
 
 Either you can:
    - watch movie, play DotA and sleep peacefully (or)
    - date with crush, play DotA and sleep peacefully
 
 Given the start and finish times of activities, print the maximum number of activities. Input is already store in a vector of pairs. Each pair contains the start and end of the activity.
 
 Input:
    (7,9) (0,10) (4,5) (8,9) (4,10) (5,7)
 Output:
    3
 */

#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

bool activityCompare(pair<int, int> a, pair<int, int>  b) {
    return a.second < b.second;
}

int countActivites(vector<pair<int,int> > activities) {
    // sort first
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

int main() {
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
