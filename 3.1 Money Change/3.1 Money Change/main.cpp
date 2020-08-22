//
//  main.cpp
//  3.1 Money Change
//
//  Created by Vishweshwar Tyagi on 08/08/20.
//  Copyright © 2020 Vishweshwar Tyagi. All rights reserved.
//  Time Complexity: 𝑂(1)
//  Auxiliary Space: 𝑂(1)

#include <iostream>

int get_change(int &m) {
    // Greedy Choice: Have as many coins of higer denomination as possible
    
    int coins10 = 0, coins5 = 0, coins1 = 0;
    
    coins10 = m/10; // Number of coins of denomination 10
    m -= 10*coins10;
    coins5 = m/5; // Number of coins of denomination 5
    coins1 = m - 5*coins5; // Number of coins of denomination 1
    
    return coins10 + coins5 + coins1;
}

int main() {
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
}
