CMAKE_MINIMUM_REQUIRED(VERSION 3.0)     #最低版本要求

SET(CMAKE_CXX_COMPILER "g++")           #设置g++编译器

PROJECT(LeetCode)                          #设置工程名
MESSAGE(STATUS "Project LeetCode")         #打印消息

#SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
#SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3")

ADD_EXECUTABLE(leetcode2 leetcode2.cpp)         #生成可执行文件
SET_PROPERTY(TARGET leetcode2 PROPERTY CXX_STANDARD 11)
