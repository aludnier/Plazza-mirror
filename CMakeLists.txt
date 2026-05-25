cmake_minimum_required(VERSION 3.20.0)
project(Plazza-mirror LANGUAGES CXX)


include_directories(${PROJECT_SOURCE_DIR}/include)

set( PLAZZA_SOURCE
    ${PROJECT_SOURCE_DIR}/src/Cook.cpp
    ${PROJECT_SOURCE_DIR}/src/Kitchen.cpp
    ${PROJECT_SOURCE_DIR}/src/Reception.cpp
    ${PROJECT_SOURCE_DIR}/src/LineParser.cpp
    ${PROJECT_SOURCE_DIR}/src/Order.cpp
    ${PROJECT_SOURCE_DIR}/src/IPC.cpp
)


add_executable(plazza ${PLAZZA_SOURCE} main.cpp)

