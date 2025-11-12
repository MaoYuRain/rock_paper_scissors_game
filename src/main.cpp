//
// Created by maoyu on 2025/11/12.
//
#include <iostream>
#include <fstream>
#include <string>
#include "game.h"
#include "player.h"
int main() {
 // print hello world
    std::cout << "hello world!\n";

}


//--------------------------------------------
// 辅助函数：记录比赛
//--------------------------------------------
void logGame(const std::string& filename, const Player& p1, int c1,
             const Player& p2, int c2, int result) {
    std::ofstream file(filename, std::ios::app);
    if (!file.is_open()) return;

    std::time_t now = std::time(nullptr);
    char buf[64];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

    file << "[" << buf << "] "
         << p1.name << "(" << choiceToString(c1) << ") vs "
         << p2.name << "(" << choiceToString(c2) << ") -> ";

    if (result == 0) file << "Draw";
    else if (result == 1) file << p1.name << " wins";
    else file << p2.name << " wins";
    file << "\n";
    file.close();
}