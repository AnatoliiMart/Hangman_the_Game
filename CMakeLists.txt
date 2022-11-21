
#[[
	the main purpose is making two binaries
	one for game
	and
	the other for tests
]]


#cmake minimum version
cmake_minimum_required (VERSION 3.8)


# c++ standart
set (CMAKE_CXX_STANDARD 11)


# compilers flags
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall") # "all wornings as error"


project(Hangman)


# headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Source/Includes)


# general sources for game and test framework
set (SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/Source/Private/Helper/Helper.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Source/Private/InputOutput/InputOutput.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Source/Private/Validation/Validation.cpp
)


# path to inludes
set (INCLUDES {CMAKE_CURRENT_SOURCE_DIR}/Source/Includes)

# headers
set (HEADERS
	${INCLUDES}/Constants/Constants.hpp
	${INCLUDES}/DataBase/DataBase.hpp
	${INCLUDES}/Hangman/Hangman.hpp
	${INCLUDES}/Helper/Helper.hpp
	${INCLUDES}/InputOutput/InputOutput.hpp
	${INCLUDES}/Validation/Validation.hpp
)


add_executable (${PROJECT_NAME}
				${CMAKE_CURRENT_SOURCE_DIR}/Source/main.cpp
				${CMAKE_CURRENT_SOURCE_DIR}/Source/Private/Hangman/Hangman.cpp
				${SOURCES}
)


add_executable (
				${PROJECT_NAME}_testing
				${CMAKE_CURRENT_SOURCE_DIR}/Testing/main.cpp
				${SOURCES}
)