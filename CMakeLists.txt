cmake_minimum_required(VERSION 4.0)
project(untitled)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Widgets
        Gui
        REQUIRED)

add_executable(untitled main.cpp)
target_link_libraries(untitled
        Qt::Core
        Qt::Widgets
        Qt::Gui
)

