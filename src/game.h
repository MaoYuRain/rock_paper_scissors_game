//
// Created by maoyu on 2025/11/12.
//

#ifndef ROCK_PAPER_SCISSORS_GAME_GAME_H
#define ROCK_PAPER_SCISSORS_GAME_GAME_H

int decideWinner(int p1, int p2);
int getMaskedChoice(int playerNumber);

std::string choiceToString(int choice);// ← 新增：数字转文字
int readInt(const std::string& prompt, int min, int max);

#endif //ROCK_PAPER_SCISSORS_GAME_GAME_H