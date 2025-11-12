//
// Created by maoyu on 2025/11/12.
//
TEST_CASE("saveAllPlayers and loadAllPlayers handle files correctly", "[fileio]") {
    const std::string testFile = "tmp/test_players.txt";
    fs::create_directories("tmp");

    PlayerMap players;
    players["Alice"] = {"Alice", 3, 1, 2};
    players["Bob"] = {"Bob", 5, 0, 1};

    saveAllPlayers(testFile, players);
    REQUIRE(fs::exists(testFile));

    // 再加载回来
    PlayerMap loaded = loadAllPlayers(testFile);
    REQUIRE(loaded.size() == 2);
    REQUIRE(loaded["Alice"].wins == 3);
    REQUIRE(loaded["Bob"].losses == 0);

    // 删除临时文件
    fs::remove(testFile);
    fs::remove_all("tmp");
}


