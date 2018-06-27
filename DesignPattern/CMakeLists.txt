cmake_minimum_required(VERSION 3.10)
project(DesignPattern)

set(CMAKE_CXX_STANDARD 11)

add_executable(DesignPattern main.cpp Observer.cpp Observer.h Subject.cpp Subject.h DivObserver.cpp DivObserver.h)