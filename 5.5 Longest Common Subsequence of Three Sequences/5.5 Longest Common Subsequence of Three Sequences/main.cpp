//
//  main.cpp
//  5.5 Longest Common Subsequence of Three Sequences
//
//  Created by Vishweshwar Tyagi on 23/08/20.
//  Copyright © 2020 Vishweshwar Tyagi. All rights reserved.
//
//  Time Complexity: 𝑂( A.size() * B.size() * C.size() )
//  where A, B and C are input sequences
//  Auxiliary Space: 𝑂( A.size() * B.size() * C.size() )

#include <iostream>
#include <vector>

using std::vector;
using namespace std;

int myMax(int &a, int &b, int &c, int &d, int &e, int &f) {
    int max = a;
    if ( b > max )
        max = b;
    if( c > max )
        max = c;
    if( d > max )
        max = d;
    if( e > max )
        max = e;
    if ( f > max )
        max = f;
    return max;
}

void optimal_values(vector<int> &A, vector<int> &B, vector<int> &C, vector<vector<vector<int>>> &t) {
    // After this function is executed, t[i][j][k] will contain
    // the lenght of longest possible sequence common to
    // A[0, 1, ... i-1], B[0, 1, ... j-1] and C[0, 1, ... k-1]
    // for i = 0, 1, ... A.size(); j = 0, 1, ... B.size() and
    // k = 0, 1, ... C.size()
    for(int i = 1; i < A.size()+1; ++i) {
        for(int j = 1; j < B.size()+1; ++j) {
            for(int k = 1; k < C.size()+1; ++k) {
                t[i][j][k] = A[i-1] == B[j-1] &&  B[j-1] == C[k-1] ? 1 + t[i-1][j-1][k-1] : myMax( t[i-1][j][k], t[i][j-1][k], t[i][j][k-1], t[i-1][j-1][k], t[i-1][j][k-1],  t[i][j-1][k-1]);
            }
        }
    }
}

int main() {
    int a, b, c;
    cin >> a;
    vector<int> A(a);
    for(int i = 0; i < a; ++i)
        cin >> A[i];
    cin >> b;
    vector<int> B(b);
    for(int i = 0; i < b; ++i)
        cin >> B[i];
    cin >> c;
    vector<int> C(c);
    for(int i = 0; i < c; ++i)
        cin >> C[i];
    vector<vector<vector<int>>> t(A.size()+1, vector<vector<int>> (B.size()+1, vector<int> (C.size()+1, 0)));
    optimal_values(A, B, C, t);
    cout << t[A.size()][B.size()][C.size()] << "\n";
    return 0;
}
