cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject2 LANGUAGES CXX)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
include_directories(include)
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main src/main.cpp "src/engine.cpp" "src/UI/Button.cpp" "src/UI/Map/GameBoard.cpp" "src/UI/Map/Cell.cpp"  "src/Elem.cpp" "src/UI/Checkers/Ckecker.cpp" "include/GameBoardController.h" "src/GameBoardController.cpp")
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics)
