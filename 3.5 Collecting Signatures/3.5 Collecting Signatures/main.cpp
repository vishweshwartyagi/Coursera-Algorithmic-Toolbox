//
//  main.cpp
//  3.5 Collecting Signatures
//
//  Created by Vishweshwar Tyagi on 08/08/20.
//  Copyright © 2020 Vishweshwar Tyagi. All rights reserved.
//  Time Complexity: 𝑂(n.log n)
//  Auxiliary Space: 𝑂(n)

#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;

bool compare(pair<int, int> &a, pair<int, int> &b) {
    // Sort the segments in increasing order of end points
    // In case of clash, amoung two line segments sharing an end point,
    // the line segment with greater length will be placed before
    if( a.second == b.second )
        return a.second - a.first > b.second - b.first;
    return a.second < b.second;
}
vector<int> optimal_points(vector<pair<int, int>>& segments, int &n) {
    
    sort(segments.begin(), segments.end(), compare);
    // Collect common end points
    vector<int> points;
    points.push_back(segments[0].second);
    for(int i = 1, cnt = 1; i < n; ++i) {
        if(!(points[cnt-1] >= segments[i].first && points[cnt-1] <= segments[i].second)) {
            points.push_back(segments[i].second);
            cnt++;
        }
    }
    return points;
}

int main() {
    int n;
    std::cin >> n;
    vector<pair<int, int>> segments(n);
    for (int i = 0; i < n; ++i)
        std::cin >> segments[i].first >> segments[i].second;
    vector<int> points = optimal_points(segments, n);
    std::cout << points.size() << "\n";
    for (int i = 0; i < points.size(); ++i)
        std::cout << points[i] << " ";
    return 0;
}
