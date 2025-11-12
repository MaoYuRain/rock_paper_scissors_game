//
// Created by maoyu on 2025/11/12.
//
#include <catch2/catch_test_macros.hpp>
#include "../src/game.h"


// ---------- decideWinner() 测试 ----------
TEST_CASE("decideWinner determines correct outcome", "[decideWinner]") {

    SECTION("Draw cases") {
        REQUIRE(decideWinner(1, 1) == 0);
        REQUIRE(decideWinner(2, 2) == 0);
        REQUIRE(decideWinner(3, 3) == 0);
    }

    SECTION("Player 1 wins") {
        REQUIRE(decideWinner(1, 3) == 1); // Rock beats Scissors
        REQUIRE(decideWinner(2, 1) == 1); // Paper beats Rock
        REQUIRE(decideWinner(3, 2) == 1); // Scissors beats Paper
    }

    SECTION("Player 2 wins") {
        REQUIRE(decideWinner(3, 1) == 2);
        REQUIRE(decideWinner(1, 2) == 2);
        REQUIRE(decideWinner(2, 3) == 2);
    }
}