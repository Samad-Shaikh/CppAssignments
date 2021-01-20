cmake_minimum_required(VERSION 3.17)
project(cppredis)

set(CMAKE_CXX_STANDARD 14)

add_executable(cppredis main.cpp values/ValueBase.cpp values/ValueBase.h values/KeyValueStore.cpp values/KeyValueStore.h values/ValueInt.cpp values/ValueInt.h values/ValueString.cpp values/ValueString.h)