set(SOURCES
        game.cpp
        player.cpp
)

add_library(game_lib ${SOURCES})

add_executable(RockPaperScissorsGame main.cpp)
target_link_libraries(RockPaperScissorsGame PRIVATE game_lib)
