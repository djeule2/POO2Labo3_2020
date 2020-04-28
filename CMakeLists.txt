cmake_minimum_required(VERSION 3.15)
project(POO2Labo3_2020)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(POO2Labo3_2020
        src/Bank.cpp
        src/Bank.h
        src/Boat.cpp
        src/Boat.h
        src/Container.cpp
        src/Container.h
        src/Controller.cpp
        src/Controller.h
        src/main.cpp
        src/Person.cpp
        src/Person.h)
