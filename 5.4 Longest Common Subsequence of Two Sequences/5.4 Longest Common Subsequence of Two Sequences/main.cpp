//
//  main.cpp
//  5.4 Longest Common Subsequence of Two Sequences
//
//  Created by Vishweshwar Tyagi on 23/08/20.
//  Copyright © 2020 Vishweshwar Tyagi. All rights reserved.
//
//  Time Complexity: 𝑂( A.size() * B.size() )
//  where A and B are the input sequences
//  Auxiliary Space: 𝑂( A.size() * B.size() ) (2D Dynamic Programming)
//  Auxiliary Space can be reduced to 𝑂( min(A.size(), B.size()) )
//  using 1D Dynamic Programming

#include <iostream>
#include <vector>

using std::vector;
using namespace std;

int myMax(int &a, int &b) {
    if( a > b )
        return a;
    return b;
}

void optimal_values(vector<int> &A, vector<int> &B, vector<vector<int>> &t) {
    // After this function is executed,
    // t[i][j] will contain the lenght of longest possible
    // sequence common to A[0, 1, ... i-1] and B[0, 1, ... j-1]
    // for i = 0, 1, ... A.size() and j = 0, 1, ... B.size()
    for(int i = 0; i < A.size()+1; ++i) // Base Case
        t[i][0] = 0;
    for(int j = 0; j < B.size()+1; ++j) // Base Case
        t[0][j] = 0;
    for(int i = 1; i < A.size()+1; ++i) {
        for(int j = 1; j < B.size()+1; ++j) {
            t[i][j] = A[i-1] == B[j-1] ? 1+t[i-1][j-1] : myMax(t[i-1][j], t[i][j-1]);
        }
    }
}

int main() {
    int m, n;
    cin >> m;
    vector<int> A(m);
    for(int i = 0; i < m; ++i)
        cin >> A[i];
    cin >> n;
    vector<int> B(n);
    for(int i = 0; i < n; ++i)
        cin >> B[i];
    vector<vector<int>> t(A.size()+1, vector<int> (B.size()+1, 0));
    optimal_values(A, B, t);
    cout << t[A.size()][B.size()] << "\n";
    return 0;
}
