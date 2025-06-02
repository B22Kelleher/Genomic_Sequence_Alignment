// Copyright 2025 Brendan Kelleher
#define BOOST_TEST_MODULE NBodyTest
#include <sstream>
#include<string>
#include <boost/test/included/unit_test.hpp>
#include "./EDistance.hpp"



BOOST_AUTO_TEST_CASE(Min3Test) {
    EDistance E("AACAGTTACC", "TAAGGTCA");
    int num = E.min3(8, 5, 19);
    BOOST_CHECK_EQUAL(num, 5);
    num = E.min3(4, 5, 4);
    BOOST_CHECK_EQUAL(num, 4);
}

BOOST_AUTO_TEST_CASE(PenaltyTest) {
    EDistance E("AACAGTTACC", "TAAGGTCA");
    int num = E.penalty('A', 'G');
    BOOST_CHECK_EQUAL(num, 1);
    num = E.penalty('A', 'A');
    BOOST_CHECK_EQUAL(num, 0);
}
BOOST_AUTO_TEST_CASE(OptDistanceTest) {
    EDistance E("AACAGTTACC", "TAAGGTCA");
    int num = E.optDistance();
    BOOST_CHECK_EQUAL(num, 7);
}
BOOST_AUTO_TEST_CASE(ALignmentTest) {
    std::string ExpOutput =
    "A T 1\nA A 0\nC - 2\nA A 0\nG G 0\nT G 1\nT T 0\nA - 2\nC C 0\nC A 1\n";
    std::string CutOutput =
    "A T 1\nA A 0\nC - 2\nA A 0\nG G 0\nT G 1\nT T 0\nA - 2\nC C 0\nC";
    EDistance E("AACAGTTACC", "TAAGGTCA");
    E.optDistance();
    std::string ActOutput = E.alignment();
    BOOST_CHECK_EQUAL(ActOutput, ExpOutput);
    BOOST_CHECK_EQUAL(ActOutput.length(), ExpOutput.length());
    BOOST_CHECK_NE(ActOutput, CutOutput);
}
