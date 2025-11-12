cmake_minimum_required(VERSION 3.16)
project(RockPaperScissorsGame)

set(CMAKE_CXX_STANDARD 17)


# 包含源码
add_subdirectory(src)

# 包含测试
enable_testing()
add_subdirectory(tests)
