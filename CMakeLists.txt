cmake_minimum_required(VERSION 2.8)
project(test-santizer)

include(CheckCXXCompilerFlag)

if(UNIX)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
add_definitions(-std=c++11)
elseif(COMPILER_SUPPORTS_CXX0X)
add_definitions(-std=c++0x)
endif()
endif()

add_definitions(-fsanitize=address)
add_definitions(-fno-omit-frame-pointer)



add_executable(test-santizer main.cpp ) 
target_link_libraries(test-santizer libasan.so) 
#SET_TARGET_PROPERTIES(test-santizer PROPERTIES LINK_FLAGS -Wl,-static-libasan)
