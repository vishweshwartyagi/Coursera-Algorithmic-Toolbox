//
//  main.cpp
//  3.6 Maximum Number of Prizes
//
//  Created by Vishweshwar Tyagi on 08/08/20.
//  Copyright © 2020 Vishweshwar Tyagi. All rights reserved.
//  Time Complexity: 𝑂(\sqrt n)
//  Auxiliary Space: 𝑂(\sqrt n)

#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
    // Greedy Choice: Required partition can be obtained by
    // keeping the magnitude of each summand as low as possible
    vector<int> summands;
    int sum = 0, k = 1;
    // Find the maximum possible sum 1 + 2 + 3 + \ldots + k
    // which is \leq n
    // To do so, instead of the approach below,
    // we could also binary search for 'k'
    // but the final time complexity will again come out to be
    // 𝑂(\sqrt n) since we are also required to make the partition
    while( sum + k <= n) {
        summands.push_back(k);
        sum += k++;
    }
    // In case 1 + 2 + 3 + \ldots + k = n, then,
    // 1, 2, 3, \ldots k is our required partition
    if( sum == n )
        return summands;
    // otherwise we increase the largest summand by ( n - sum )
    // to obtain our required partition
    else
        summands[k-2] += n - sum; // (k-1) is size of 'summands' array
    
    return summands;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> summands = optimal_summands(n);
    std::cout << summands.size() << '\n';
    for (int i = 0; i < summands.size(); ++i)
        std::cout << summands[i] << ' ';
    return 0;
}
