//
//  main.cpp
//  EarthLevels
//
//  Created by Ramon Ferreira on 02/07/24.
//

/*
 Earth Levels Exercise

 The Planet Earth is under a threat from the aliens of the outer space and your task is to defeat an enemy who is N steps above you (assume yourself to be at ground level i.e. at the 0th level). You can take jumps in power of 2. In order to defeat the enemy as quickly as possible you have to reach the Nth step in minimum moves possible.

 Input Format:
    In the function an integer is passed.
 Output Format:
    Return an integer representing minimum jumps.

 Sample Input:
     7
 Sample Output:
     3
 Explanation:
     0 -> 4 -> 6 -> 7
 */

#include <iostream>

using namespace std;

int countEarthLevelSteps(int num) {
    int count = 0;
    
    while (num > 0) {
        count += (num & 1);
        num >>= 1;
    }
    
    return count;
}

int main() {
    int num;
    cout << "Enter the number of steps: ";
    cin >> num;
    
    cout << "Number of steps to defeat: " << countEarthLevelSteps(num) << endl;
    
    return 0;
}
