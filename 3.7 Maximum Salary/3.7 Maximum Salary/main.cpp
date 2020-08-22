//
//  main.cpp
//  3.7 Maximum Salary
//
//  Created by Vishweshwar Tyagi on 08/08/20.
//  Copyright © 2020 Vishweshwar Tyagi. All rights reserved.
//  Time Complexity: 𝑂(n.log n)
//  Auxiliary Space: 𝑂(n)

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool compare(int &A, int &B) {
    
    string strAB = std::to_string(A) + std::to_string(B);
    string strBA = std::to_string(B) + std::to_string(A);
    // strAB and strBA are of same length,
    // so we can compare directly without
    // converting them to long long int
    return strAB > strBA;
}

string largest_number(vector<int>& a) {
    
    if(a.size() == 1)
        return std::to_string(a[0]);
    
    sort(a.begin(), a.end(), compare);
    
    // Convert resultant array into string
    string result = "";
    for(int i = 0; i < a.size(); ++i)
        result += std::to_string(a[i]);
    
    return result;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        std::cin >> a[i];
    
    std::cout << largest_number(a) << "\n";
    
    return 0;
}
