cmake_minimum_required(VERSION 3.16)

project(Qt_modules LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core Sql Network)
find_package(Qt6 REQUIRED COMPONENTS Core Sql Network)

add_executable(Qt_modules
  main.cpp
)

target_link_libraries(Qt_modules PRIVATE
  Qt6::Core
  Qt6::Sql
  Qt6::Network
)

include(GNUInstallDirs)
install(TARGETS Qt_modules
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
