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
    set(dir_path ${CMAKE_CURRENT_SOURCE_DIR}/src/${child})

    if(IS_DIRECTORY ${dir_path} AND EXISTS ${dir_path}/CMakeLists.txt)
        add_subdirectory(src/${child})

    endif()
endforeach()
