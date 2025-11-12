//
// Created by maoyu on 2025/11/12.
//
#include <iostream>
#ifdef _WIN32
#include <conio.h>   // Windows
#else
#include <termios.h> // macOS / Linux
#include <unistd.h>
#endif

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
int getMaskedChoice(int playerNumber) {
    while (true) {
        std::cout << "Player " << playerNumber
                  << ", enter your choice (1=rock, 2=paper, 3=scissors): ";

#ifdef _WIN32
        // Windows
        char ch = _getch();
#else
        // macOS / Linux
        termios oldt, newt;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        char ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
#endif

        std::cout << "*\n";

        if (ch >= '1' && ch <= '3')
            return ch - '0';
        else {
            std::cout << "Invalid input! Please enter 1, 2, or 3.\n";

#ifdef _WIN32
            while (_kbhit()) _getch(); // 清空缓冲
#else
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
#endif
        }
    }
}