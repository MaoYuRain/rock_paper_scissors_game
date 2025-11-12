//
// Created by maoyu on 2025/11/12.
//
TEST_CASE("updateRecord updates stats correctly", "[player]") {
    Player p1{"Alice"}, p2{"Bob"};

    SECTION("draw") {
        updateRecord(p1, p2, 0);
        REQUIRE(p1.draws == 1);
        REQUIRE(p2.draws == 1);
    }

    SECTION("player1 wins") {
        updateRecord(p1, p2, 1);
        REQUIRE(p1.wins == 1);
        REQUIRE(p2.losses == 1);
    }

    SECTION("player2 wins") {
        updateRecord(p1, p2, 2);
        REQUIRE(p1.losses == 1);
        REQUIRE(p2.wins == 1);
    }
}