cmake_minimum_required(VERSION 3.14)

project(iris LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE MIRROR_DASHBOARD_SOURCES
    apps/mirror/src/*.cpp
    apps/mirror/src/*.hpp
)

# file(GLOB_RECURSE BACKEND_SOURCES)

add_executable(${PROJECT_NAME} ${MIRROR_DASHBOARD_SOURCES})

# Link Qt6 libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

qt_add_resources(RESOURCES resources.qrc)
target_sources(${PROJECT_NAME} PRIVATE ${RESOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/mirror/src
)
