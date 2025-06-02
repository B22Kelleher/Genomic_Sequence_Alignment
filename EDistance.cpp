// Copyright 2025 Brendan Kelleher
#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include "/autograder/playground/EDistance.hpp"
EDistance::EDistance(const std::string& s1, const std::string& s2) {
    s1_len = s1.length();
    s2_len = s2.length();
    string1 = s1;
    string2 = s2;

    matrix.resize(s1_len + 1, std::vector<int>(s2_len + 1, 0));
    for (int x = 0; x <= static_cast<int>(s1.length()); x++) {
        for (int y = 0; y <=  static_cast<int>(s2.length()); y++) {
            matrix[x][y] = 0;
        }
    }
}
int EDistance::penalty(char a, char b) {
    if (a == b) {
        return 0;
    }
    return 1;
}
int EDistance::min3(int a, int b, int c) {
    return std::min(a, std::min(b, c));
}
int EDistance::optDistance() {
    populateEdges();
    for (int y = s2_len-1; y >= 0; y--) {
        for (int x = s1_len-1; x >= 0; x--) {
            matrix[x][y] = min3(matrix[x+1][y+1] +
                 penalty(string1[x], string2[y]), matrix[x+1][y] + 2,
                  matrix[x][y+1] + 2);
        }
    }
    edit_distance = matrix[0][0];
    return matrix[0][0];
}
std::string EDistance::alignment() {
    int x = 0;
    int y = 0;
    std::string alignOutput = "";
    while (x < static_cast<int>(string1.length())
    && y < static_cast<int>(string2.length())) {
    if (matrix[x][y] == matrix[x+1][y+1] && min3(matrix[x+1][y+1]
         + penalty(string1[x], string2[y]),
           matrix[x+1][y] + 2, matrix[x][y+1] + 2)
          == matrix[x+1][y+1] + penalty(string1[x], string2[y])) {
        alignOutput += std::string(1, string1[x]) +
         " " + std::string(1, string2[y]);
        alignOutput += " 0\n";
        x++;
        y++;
    } else if (matrix[x][y] == matrix[x+1][y+1]+1 && min3(matrix[x+1][y+1]
         + penalty(string1[x], string2[y]),  matrix[x+1][y] + 2,
          matrix[x][y+1] + 2) == matrix[x+1][y+1] +
           penalty(string1[x], string2[y])) {
        alignOutput +=  std::string(1, string1[x]) +
         " " + std::string(1, string2[y]);
        alignOutput += " 1\n";
        x++;
        y++;
    } else if (matrix[x][y] == matrix[x+1][y]+2 && min3(matrix[x+1][y+1]
         + penalty(string1[x], string2[y]),
           matrix[x+1][y] + 2, matrix[x][y+1] + 2)
            == matrix[x+1][y]+2) {
        alignOutput += std::string(1, string1[x]) + " -";
        alignOutput += " 2\n";
        x++;
    } else if (matrix[x][y] == matrix[x][y+1]+2) {
        alignOutput +=  "- " + std::string(1, string2[y]);
        alignOutput += " 2\n";
        y++;
    }
}
    while (x < static_cast<int>(string1.length())) {
        alignOutput += std::string(1, string1[x]) + " -";
        alignOutput += " 2\n";
        x++;
    }
    while (y < static_cast<int>(string2.length())) {
        alignOutput +=  "- " + std::string(1, string2[y]);
        alignOutput += " 2\n";
        y++;
    }
    return alignOutput;
}
void EDistance::populateEdges() {
    int num = 0;
    for (int x = s1_len; x >= 0; x--) {
        matrix[x][s2_len] = num;
        num += 2;
    }
    num = 0;
    for (int y = s2_len; y >= 0; y--) {
        matrix[s1_len][y] = num;
        num += 2;
    }
}
void EDistance::printMatrix() {
    for (int x = 0; x <= static_cast<int>(s1_len); x++) {
        for (int y = 0; y <=  static_cast<int>(s2_len); y++) {
            std::cout << matrix[x][y] << " ";
            if (matrix[x][y] <= 9)
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}
