//
// Created by maoyu on 2025/11/12.
//
#include "player.h"

#include <fstream>
#include <sstream>
#include <iostream>

#include <filesystem>

namespace fs = std::filesystem;

// 从文件加载所有玩家到 map（支持自动创建目录+文件）
PlayerMap loadAllPlayers(const std::string& filename) {
    PlayerMap players;

    fs::path filePath(filename);
    fs::path dirPath = filePath.parent_path(); // 获取目录 "data/"

    // 1️⃣ 如果目录不存在，就创建它
    if (!fs::exists(dirPath)) {
        std::cout << "Directory '" << dirPath << "' not found. Creating...\n";
        try {
            fs::create_directories(dirPath);
        } catch (const std::exception& e) {
            std::cerr << "Error creating directory: " << e.what() << "\n";
        }
    }

    // 2️⃣ 如果文件不存在，就创建空文件
    if (!fs::exists(filePath)) {
        std::cout << "File '" << filePath << "' not found. Creating...\n";
        std::ofstream newFile(filename);
        newFile.close();
        return players; // 返回空 map
    }

    // 3️⃣ 如果文件存在，就读取玩家数据
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open " << filename << "\n";
        return players;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Player p;
        ss >> p.name >> p.wins >> p.losses >> p.draws;
        if (!p.name.empty())
            players[p.name] = p;
    }

    return players;
}
