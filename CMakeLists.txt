CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(rshell
	src/rshell.cpp
	src/And.cpp
	src/Or.cpp
	src/Semicolon.cpp
	src/parser.cpp
	src/Exec.cpp
)

ADD_EXECUTABLE(test
	unit_test/unit_test.cpp
	src/And.cpp
	src/Or.cpp
	src/Semicolon.cpp
	src/parser.cpp
	src/Exec.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
