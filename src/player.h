//
// Created by maoyu on 2025/11/12.
//

#ifndef ROCK_PAPER_SCISSORS_GAME_PLAYER_H
#define ROCK_PAPER_SCISSORS_GAME_PLAYER_H

#include <string>
#include <map>


struct Player {
    std::string name;
    int wins = 0;
    int losses = 0;
    int draws = 0;
};

using PlayerMap = std::map<std::string, Player>;

PlayerMap loadAllPlayers(const std::string& filename);
void saveAllPlayers(const std::string& filename, const PlayerMap& players);

#endif //ROCK_PAPER_SCISSORS_GAME_PLAYER_H