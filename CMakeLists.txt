cmake_minimum_required(VERSION 4.3)
project(
    ISUEE-Sem-2-Informatyka-i-podstawy-programowania
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB children RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/src ${CMAKE_CURRENT_SOURCE_DIR}/src/*)
foreach(child ${children})
	if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/${child})
		file(GLOB exercise RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/src/${child} ${CMAKE_CURRENT_SOURCE_DIR}/src/${child}/*)
		foreach(exercise ${exercise})
			add_executable(${child}_${exercise} src/${child}/${exercise}/main.cpp)
		endforeach()
	endif()
endforeach()
