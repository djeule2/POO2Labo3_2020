cmake_minimum_required(VERSION 3.15)
project(POO2Labo3_2020)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(POO2Labo3_2020
        Bank.cpp
        Bank.h
        Boat.cpp
        Boat.h
        Container.cpp
        Container.h
        Controller.cpp
        Controller.h
        main.cpp
        Person.cpp
        Person.h)
