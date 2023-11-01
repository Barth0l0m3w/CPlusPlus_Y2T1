cmake_minimum_required(VERSION 3.26)
project(week6)

set(CMAKE_CXX_STANDARD 17)

add_executable(week6 main.cpp
        sceneHandler.hpp
        gameObject.cpp
        scene.cpp
        sceneHandler.cpp
        spriteObject.cpp
        Button.cpp
        Button.h
        Button.h)


find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(week6 PRIVATE sfml-system sfml-network sfml-graphics sfml-window)

find_package(glm CONFIG REQUIRED)
target_link_libraries(week6 PRIVATE glm::glm)
