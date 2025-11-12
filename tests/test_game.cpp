//
// Created by maoyu on 2025/11/12.
//
TEST_CASE("choiceToString returns correct string", "[choiceToString]") {
    REQUIRE(choiceToString(1) == "Rock");
    REQUIRE(choiceToString(2) == "Paper");
    REQUIRE(choiceToString(3) == "Scissors");
    REQUIRE(choiceToString(0) == "Invalid");
    REQUIRE(choiceToString(99) == "Invalid");
}