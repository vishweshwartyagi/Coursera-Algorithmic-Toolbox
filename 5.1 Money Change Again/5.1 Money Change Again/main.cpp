//
//  main.cpp
//  5.1 Money Change Again
//
//  Created by Vishweshwar Tyagi on 17/08/20.
//  Copyright © 2020 Vishweshwar Tyagi. All rights reserved.
//
//  Preprocessing Time: 𝑂(n) where 'n' is upper bound of money
//  Query Time: 𝑂(1)
//  Auxiliary Space: 𝑂(n) where 'n' is upper bound of money

#include <iostream>
#include <vector>

#define vec vector<int>
#define endl "\n"

using std::vector;
using namespace std;

vec optimal_values(1000);
vec denominations = {1, 3, 4};

int change_money(int money) {
    if( money == 1 || money == 2 )
        return money;
    
    if( money == 3 )
        return 1;
    
    if( money == 4)
        return 1;
    int min = 1001;
    for(int i = 0; i < denominations.size(); ++i ) {
        if( denominations[i] == money )
            return 1;
        
        if( denominations[i] < money )
            if( optimal_values[ money - denominations[i] - 1 ] <= min )
                min = optimal_values[ money - denominations[i] - 1 ];
    }
    return 1 + min;
}

int main() {
    
    int money;
    for(int i = 0; i < 1000; ++i) {
        optimal_values[i] = change_money(i+1);
    }
    cin >> money;
    cout << optimal_values[money-1] << endl;
    return 0;
}
