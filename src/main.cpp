//
// Created by maoyu on 2025/11/12.
//
#include <iostream>
#include <fstream>
#include <string>
#include "game.h"
#include "player.h"


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

//--------------------------------------------
// 显示所有用户
//--------------------------------------------
void showAllUsers(const PlayerMap& players) {
    std::cout << "\n=== All Users ===\n";
    if (players.empty()) {
        std::cout << "No users found.\n";
        return;
    }
    for (const auto& [name, p] : players) {
        std::cout << name << " -> Wins: " << p.wins
                  << ", Losses: " << p.losses
                  << ", Draws: " << p.draws << "\n";
    }
}

//--------------------------------------------
// 显示比赛记录
//--------------------------------------------
void showGameHistory(const std::string& filename) {
    std::ifstream file(filename);
    std::cout << "\n=== Game History ===\n";
    if (!file.is_open()) {
        std::cout << "No history file found.\n";
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << "\n";
    }
    file.close();
}


//--------------------------------------------
// 开始一场对战（多轮）
//--------------------------------------------
void startMatch(PlayerMap& players, const std::string& logFile) {
    std::cout << "\n=== Current Player List ===\n";
    if (players.empty()) {
        std::cout << "No existing players yet. New players will be created automatically.\n";
    } else {
        int index = 1;
        for (const auto& [name, p] : players) {
            std::cout << " " << index++ << ". " << name << "\n";   // ✅ 只显示玩家名字
        }
    }

    std::string name1, name2;
    std::cout << "\nEnter Player 1 name (or new name to create): ";
    std::getline(std::cin, name1);
    std::cout << "Enter Player 2 name (or new name to create): ";
    std::getline(std::cin, name2);

    Player& p1 = getOrCreatePlayer(players, name1);
    Player& p2 = getOrCreatePlayer(players, name2);

    bool playAgain = true;
    while (playAgain) {
        int c1 = getMaskedChoice(1);
        int c2 = getMaskedChoice(2);

        int result = decideWinner(c1, c2);
        updateRecord(p1, p2, result);
        logGame(logFile, p1, c1, p2, c2, result);

        std::cout << "\n" << p1.name << " chose: " << choiceToString(c1)
                  << "\n" << p2.name << " chose: " << choiceToString(c2) << "\n";

        if (result == 0)
            std::cout << "It's a draw!\n";
        else if (result == 1)
            std::cout << p1.name << " wins!\n";
        else
            std::cout << p2.name << " wins!\n";

        std::cout << "\nUpdated Records:\n";
        std::cout << p1.name << " (W:" << p1.wins << " L:" << p1.losses << " D:" << p1.draws << ")\n";
        std::cout << p2.name << " (W:" << p2.wins << " L:" << p2.losses << " D:" << p2.draws << ")\n";

        int again = readInt("\nPlay again with same players? (1=Yes, 2=No): ", 1, 2);
        playAgain = (again == 1);
    }
}
int main() {
    const std::string userFile = "data/users.txt";
    const std::string logFile  = "data/game_log.txt";

    PlayerMap players = loadAllPlayers(userFile);
    std::cout << "=== Welcome to Rock Paper Scissors ===\n";

    bool running = true;
    while (running) {
        std::cout << "\n===== Main Menu =====\n";
        std::cout << "1. Start match\n";
        std::cout << "2. Show all users\n";
        std::cout << "3. Show game history\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";

        int choice = readInt("Enter your choice: ", 1, 4);

        switch (choice) {
        case 1:
            startMatch(players, logFile);
            break;
        case 2:
            showAllUsers(players);
            break;
        case 3:
            showGameHistory(logFile);
            break;
        case 4:
            running = false;
            break;
        default:
            std::cout << "Invalid choice. Please enter 1–4.\n";
        }
    }

    saveAllPlayers(userFile, players);
    std::cout << "\nAll records saved. Goodbye!\n";
    return 0;
}