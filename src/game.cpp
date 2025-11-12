//
// Created by maoyu on 2025/11/12.
//
#include <iostream>
#include "game.h"

#include <limits>
#include <string>
int readInt(const std::string& prompt, int min, int max) {
    while (true) {
        std::cout << prompt;
        std::string line;
        std::getline(std::cin, line);

        // 移除前后空格
        while (!line.empty() && std::isspace(line.back())) line.pop_back();
        size_t start = 0;
        while (start < line.size() && std::isspace(line[start])) start++;
        if (start > 0) line = line.substr(start);

        // 判空
        if (line.empty()) continue;

        bool valid = true;
        for (char c : line) {
            if (!std::isdigit(c)) { valid = false; break; }
        }

        if (!valid) {
            std::cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        int val = std::stoi(line);
        if (val < min || val > max) {
            std::cout << "Please enter a number between " << min << " and " << max << ".\n";
            continue;
        }
        return val;
    }
}