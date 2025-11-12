//
// Created by maoyu on 2025/11/12.
//

#include "player.h"

#include <fstream>
#include <sstream>
#include <iostream>

#include <filesystem>

namespace fs = std::filesystem;

// 根据胜负结果更新记录
// result = 0 → 平局，1 → 玩家1赢，2 → 玩家2赢
void updateRecord(Player& p1, Player& p2, int result) {
    if (result == 0) {
        p1.draws++;
        p2.draws++;
    } else if (result == 1) {
        p1.wins++;
        p2.losses++;
    } else if (result == 2) {
        p1.losses++;
        p2.wins++;
    }
}