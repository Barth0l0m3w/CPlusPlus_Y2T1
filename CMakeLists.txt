cmake_minimum_required(VERSION 3.26)
project(week6)

set(CMAKE_CXX_STANDARD 17)

add_executable(week6 Game-Scenes/main.cpp
        Elements/sceneHandler.hpp
        Elements/sceneHandler.cpp
        Elements/gameObject.cpp
        Game-Scenes/scene.cpp
        Game-Scenes/scene.hpp
        Elements/spriteObject.cpp
        Elements/Button.cpp
        Elements/Button.h
        Game-Scenes/Game.cpp
        Game-Scenes/Game.h
        Elements/HighScore.cpp
        Elements/HighScore.h
        Elements/character.hpp
        Elements/character.cpp
)


find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(week6 PRIVATE sfml-system sfml-network sfml-graphics sfml-window)

find_package(glm CONFIG REQUIRED)
target_link_libraries(week6 PRIVATE glm::glm)
