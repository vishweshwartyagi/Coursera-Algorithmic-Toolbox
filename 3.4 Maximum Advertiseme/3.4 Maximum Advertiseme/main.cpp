//
//  main.cpp
//  3.4 Maximum Advertiseme
//
//  Created by Vishweshwar Tyagi on 08/08/20.
//  Copyright © 2020 Vishweshwar Tyagi. All rights reserved.
//  Time Complexity: 𝑂(n.log n)
//  Auxiliary Space: 𝑂(1)

#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

bool compare(int &a, int &b) {
    // Sort in increasing order
    return a < b;
}

long long max_dot_product(vector<int> a, vector<int> b) {
    // Greedy Choice: Ads with higher profit and slots with higer click
    // should be paired together
    sort(a.begin(), a.end(), compare);
    sort(b.begin(), b.end(), compare);
    
    // Calculate dot product
    long long result = 0;
    for (int i = 0; i < a.size(); ++i)
        result += ((long long) a[i]) * b[i];
    
    return result;
}

int main() {
    size_t n;
    std::cin >> n;
    vector<int> a(n), b(n);
    for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
    }
    for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
    }
    std::cout << max_dot_product(a, b) << std::endl;
}
