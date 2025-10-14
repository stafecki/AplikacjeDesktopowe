cmake_minimum_required(VERSION 4.0)
project(PPMQt)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

add_executable(PPMQt
        main.cpp
        MainWindow.cpp
        MainWindow.h
        PPMImage.cpp
        PPMImage.h
)

target_link_libraries(PPMQt
        Qt6::Core
        Qt6::Widgets
)
