//
//  main.cpp
//  3.2 Maximum Value of the Loot
//
//  Created by Vishweshwar Tyagi on 08/08/20.
//  Copyright © 2020 Vishweshwar Tyagi. All rights reserved.
//  Time Complexity: 𝑂(n.log n)
//  Auxiliary Space: 𝑂(n)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
    
    return( ((double)a.first) / a.second > ((double)b.first) / b.second );
    
}

double get_optimal_value(int &capacity, vector<int>& weights, vector<int>& values, int &n) {
    // Greedy choice: Have as much quantity of the item which has
    // higher value to weight ratio.
    double value = 0.0;
    
    vector<pair<int, int>> pairedVec;
    for(int i = 0; i < n; ++i) // Pair together the value and weight of each item
        pairedVec.push_back( make_pair(values[i], weights[i]) );

    // Sort 'pairedVec' in increasing order of value to weight ratio
    sort(pairedVec.begin(), pairedVec.end(), compare);
    
    int i = 0;
    while( capacity > 0  && i < n) { // Calculate required value
        value += min(pairedVec[i].second, capacity) * ( ((double)pairedVec[i].first) / pairedVec[i].second );
        capacity -= min(pairedVec[i].second, capacity);
        i++;
    }
    return value;
}

int main() {
    int n;
    int capacity;
    std::cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values, n);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    return 0;
}
