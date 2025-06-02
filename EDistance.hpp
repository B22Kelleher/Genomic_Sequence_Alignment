// Copyright 2025 Brendan Kelleher
#pragma once

#include <string>
#include <vector>
class EDistance {
 public:
    EDistance(const std::string& s1, const std::string& s2);

    static int penalty(char a, char b);
    static int min3(int a, int b, int c);

    int optDistance();
    std::string alignment();

    void populateEdges();
    void printMatrix();
 private:
std::vector<std::vector<int>> matrix;
int s1_len;
int s2_len;
std::string string1 = "";
std::string string2 = "";
int edit_distance;
};
