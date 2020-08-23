//
//  main.cpp
//  5.2 Primitive Calculator
//
//  Created by Vishweshwar Tyagi on 17/08/20.
//  Copyright © 2020 Vishweshwar Tyagi. All rights reserved.
//
//  Time Complexity: 𝑂(n)
//  Auxiliary Space: 𝑂(n)

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using std::vector;
using std::pair;
using std::string;
using std::stack;
using namespace std;

#define endl "\n"
#define vec vector<int>

vector<pair<int, int>> optimal_values(1000000);
vec operations = { -1, -2, -3};

pair<int, int> calc( int num ) {
    if( num == 1 )
        return make_pair(0, 0);
    if( num == 2 )
        return make_pair(1, -1);
    if( num == 3 )
        return make_pair(1, -3);
    pair<int, int> min = make_pair(1000001, -1000001);
    for( int i = 0; i < operations.size(); ++i ) {
        if( i == 0 ) {
            min.first = optimal_values[ num - 2 ].first;
            min.second = -1;
        }else {
            if( num % (-operations[i])  == 0 && optimal_values[ num/(-operations[i]) - 1 ].first < min.first ) {
                min.first = optimal_values[ (num/(-operations[i])) - 1 ].first;
                min.second = operations[i];
            }
        }
    }
    min.first += 1;
    return min;
}

int main(void) {
    int n;
    cin >> n;
    for( int i = 0; i < n; ++i ) {
        optimal_values[i] = calc(i+1);
    }
    
    pair<int, int> res = optimal_values[n-1];
    cout << res.first << "\n";
    stack<int> nums;
    nums.push(n);
    while( res.second != 0 ) {
        if( res.second == -1 ) {
            nums.push(n-1);
            n += -1;
        }else if( res.second == -2 ) {
            nums.push(n/2);
            n /= 2;
        }else {
            nums.push(n/3);
            n /= 3;
        }
        res = optimal_values[n-1];
    }
    while( !nums.empty() ) {
        cout << nums.top() << "\t";
        nums.pop();
    }
    return 0;
}
