// Copyright 2025 Brendan Kelleher
#include<iostream>
#include<string>
#include <SFML/Graphics.hpp>
#include "./EDistance.hpp"
int main(int argc, char* argv[]) {
    sf::Clock clock;
    std::string input1;
    std::string input2;
    std::cin >> input1 >> input2;
    EDistance E(input1, input2);
    std::string output;
    int editDist = E.optDistance();
    output = E.alignment();
    sf::Time t = clock.getElapsedTime();
    std::cout << "Edit Distance = " << editDist << std::endl;
    std::cout << output;
    std::cout << "Execution time is " << t.asSeconds()
     << " seconds" << std::endl;
    return 0;
}
