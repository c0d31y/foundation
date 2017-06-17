cmake_minimum_required (VERSION 3.0)

project ("algs4-cpp")
set (CMAKE_BUILD_TYPE debug)
set (CMAKE_CXX_STANDARD 11)

include_directories("base" "sort")

file (GLOB SRCS "base/*.cc" "sort/*.cc")
list(LENGTH SRCS FILE_NUMS)

if (FILE_NUMS GREATER 0)

	add_library(algs4 STATIC ${SRCS})

endif()


file (GLOB TESTS "tests/*.cc")
list (LENGTH TESTS FILE_NUMS)

if (FILE_NUMS GREATER 0)

	foreach(test ${TESTS})

		get_filename_component(bin ${test} NAME_WE) 
		add_executable(${bin} ${test})

		if (TARGET algs4)
			target_link_libraries(${bin} algs4)
		endif()

	endforeach()

endif()
