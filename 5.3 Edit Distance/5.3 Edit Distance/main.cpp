//
//  main.cpp
//  5.3 Edit Distance
//
//  Created by Vishweshwar Tyagi on 22/08/20.
//  Copyright © 2020 Vishweshwar Tyagi. All rights reserved.
//
//  Time Complexity: 𝑂(A.size() * B.size())
//  Auxiliary Space: 𝑂(A.size() * B.size()) (2D Dynamic Programming)
//  Auxiliary Space can be reduced to 𝑂( min(A.size(), B.size()) )
//  by using 1D Dynamic Programming

#include <iostream>
#include <vector>
#include <string>

using namespace std;
using std::vector;
using std::string;

int myMin(int a, int b, int c) {
    if( a <= b && a <= c )
        return a;
    if( b <= c && b <= a)
        return b;
    return c;
}

void optimal_values(string A, string B, vector<vector<int>> &t) {
    // After this function is executed,
    // t[i][j] will contain the editing distance of
    // A[0, 1 ... i-1] and B[0, 1, ... j-1]
    // for i = 0, 1, ... A.size() and j = 0, 1, ... B.size()
    for(int i = 0; i < A.size()+1; ++i) // Base Case
        t[i][0] = i;
    for(int j = 0; j < B.size()+1; ++j) // Base Case
        t[0][j] = j;
    // In the optimal alignment of A[0, 1 ... i] and B[0, 1, ... j],
    // the last entry corresponds to exactly one of the cases:
    // 'Insertion', 'Deletion', 'Mismatch' or a 'Match'.
    
    // Using this, we can get the editing distance of
    // A[0, 1 ... i] and B[0, 1, ... j] from the editing distances of
    // 1. A[0, 1 ... i-1] and B[0, 1, ... j] ( given by t[i-1][j] )
    // 2. A[0, 1 ... i] and B[0, 1, ... j-1] ( given by t[i][j-1] )
    // 3. A[0, 1 ... i-1] and B[0, 1, ... j-1] ( given by t[i-1][j-1] )
    for(int i = 1; i < A.size()+1; ++i) {
        for(int j = 1; j < B.size()+1; ++j) {
            t[i][j] = A[i-1] == B[j-1] ? myMin(t[i-1][j-1], 1+t[i-1][j], 1+t[i][j-1]) : myMin(1+t[i-1][j-1], 1+t[i-1][j], 1+t[i][j-1]);
        }
    }
}

int main() {
    string A, B;
    cin >> A >> B;
    vector<vector<int>> t(A.size()+1, vector<int> (B.size()+1, 0));
    optimal_values(A, B, t);
    cout << t[A.size()][B.size()];
    return 0;
}

