//
//  main.cpp
//  3.3 Car Fueling
//
//  Created by Vishweshwar Tyagi on 08/08/20.
//  Copyright © 2020 Vishweshwar Tyagi. All rights reserved.
//  Time Complexity: 𝑂(n)
//  Auxiliary Space: 𝑂(1)

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int>& stops) {
    // Greedy Choice: Refuel at the furthermost station that can be reached
    int numberOfRefuels = 0;
    int curr_tank = tank;
    
    // Check if it is possible to reach destination
    for(int i = 1; i < stops.size(); ++i)
        if(stops[i] - stops[i-1] > tank)
            return -1;
    
    // Calculate number of refuels
    for(int i = 1; i < stops.size() - 1; ++i) {
        curr_tank -= stops[i] - stops[i-1];
        // If next station can't be reached with current fuel,
        // then refuel at the current station
        if( stops[i+1] - stops[i] >  curr_tank ) {
            numberOfRefuels++;
            curr_tank = tank;
        }
    }
    return numberOfRefuels;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n+2);
    stops[0] = 0; // Starting point
    for (int i = 1; i < n + 1; ++i)
        cin >> stops[i]; // Intermediate fuel stations
    stops[n+1] = d; // End point (destination)
    
    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
