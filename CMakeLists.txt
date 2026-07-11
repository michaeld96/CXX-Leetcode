cmake_minimum_required(VERSION 3.14)
project(leetcode LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build Type" FORCE) # single config generator.
endif()

# grabs all the .cpp files
file(GLOB_RECURSE LEETCODE_SOURCES CONFIGURE_DEPENDS 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

foreach(src IN LISTS LEETCODE_SOURCES)
    # extracts the name of the file without dir and extension and assigns it to name.
    get_filename_component(name "${src}" NAME_WE)
    add_executable("${name}" "${src}")

    # create the target name based on just the leetcode problem bumber.
    if(name MATCHES "^([0-9]+)_")
        set(problem_number "${CMAKE_MATCH_1}")
        add_custom_target("${problem_number}"
            COMMAND $<TARGET_FILE:${name}>
            DEPENDS "${name}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
        )
    endif()
endforeach()


