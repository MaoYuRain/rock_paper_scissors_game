# 下载 Catch2（单文件头版本）
include(FetchContent)
FetchContent_Declare(
        catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.5.2
)
FetchContent_MakeAvailable(catch2)

add_executable(test_game test_game.cpp)
target_link_libraries(test_game PRIVATE game_lib Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(test_game)
