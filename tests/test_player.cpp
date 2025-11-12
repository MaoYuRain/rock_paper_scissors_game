//
// Created by maoyu on 2025/11/12.
//// ---------- choiceToString() 测试 ----------
TEST_CASE("getOrCreatePlayer works correctly", "[player]") {
    PlayerMap players;

    SECTION("creates new player if not exist") {
        Player& p = getOrCreatePlayer(players, "Alice");
        REQUIRE(players.count("Alice") == 1);
        REQUIRE(p.name == "Alice");
        REQUIRE(p.wins == 0);
        REQUIRE(p.losses == 0);
        REQUIRE(p.draws == 0);
    }

    SECTION("returns existing player if already exists") {
        Player& p1 = getOrCreatePlayer(players, "Bob");
        p1.wins = 2;
        Player& p2 = getOrCreatePlayer(players, "Bob");
        REQUIRE(&p1 == &p2);
        REQUIRE(p2.wins == 2);
    }
}