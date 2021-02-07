cmake_minimum_required(VERSION 3.2)

# Add depthai-core dependency
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/depthai-core EXCLUDE_FROM_ALL)

# Create a project with name 'myapp'
set(TARGET_NAME myapp)
project(${TARGET_NAME})

# Dependencies (optional, only used for example)
find_package(OpenCV REQUIRED)

# Add source files
add_executable("${TARGET_NAME}" 
    src/main.cpp
)

# Link with libraries
target_link_libraries(${TARGET_NAME} 
    PUBLIC 
        depthai-core
        ${OpenCV_LIBS} # optional, used for example
)

# Set some errors
if(NOT MSVC)
    target_compile_options(${TARGET_NAME} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-Werror=return-type>)
endif()

# Set compiler features (c++11), and disables extensions (g++)
set_property(TARGET ${TARGET_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${TARGET_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${TARGET_NAME} PROPERTY CXX_EXTENSIONS OFF)