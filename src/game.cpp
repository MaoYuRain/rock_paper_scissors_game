//
// Created by maoyu on 2025/11/12.
//
#include <iostream>
int decideWinner(int p1, int p2) {
    // 1 = rock, 2 = paper, 3 = scissors
    if (p1 == p2) return 0;

    // 胜负规则
    if ((p1 == 1 && p2 == 3) ||   // rock beats scissors
        (p1 == 2 && p2 == 1) ||   // paper beats rock
        (p1 == 3 && p2 == 2))     // scissors beats paper
            return 1;
    else
        return 2;
}
// 数字转文字
std::string choiceToString(int choice) {
    switch (choice) {
        case 1: return "Rock";
        case 2: return "Paper";
        case 3: return "Scissors";
        default: return "Invalid";
    }
}