cmake_minimum_required(VERSION 3.21)

# Create a project with name 'myapp'
set(TARGET_NAME myapp)
project(${TARGET_NAME})

# Depthai dependency
find_package(depthai REQUIRED)

# Dependencies (optional, only used for example)
find_package(OpenCV REQUIRED)

# Add source files
add_executable("${TARGET_NAME}"
    src/main.cpp
)

# Link with libraries
target_link_libraries(${TARGET_NAME}
    PUBLIC
        depthai::core
        ${OpenCV_LIBS} # optional, used for example
)

# Set some errors
if(NOT MSVC)
    target_compile_options(${TARGET_NAME} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-Werror=return-type>)
endif()

# Set compiler features (c++17)
set_property(TARGET ${TARGET_NAME} PROPERTY CXX_STANDARD 17)

# Windows - Add runtime dependencies
if(WIN32)
    ## Copy over depthai dlls
    add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${DEPTHAI_INSTALL_PREFIX}/bin"
        $<TARGET_FILE_DIR:${TARGET_NAME}>
    )

    ## Copy over other dependencies
    add_custom_command(TARGET ${TARGET_NAME} POST_BUILD COMMAND
        ${CMAKE_COMMAND} -E copy_if_different $<TARGET_RUNTIME_DLLS:${TARGET_NAME}> $<TARGET_FILE_DIR:${TARGET_NAME}>
        COMMAND_EXPAND_LISTS
    )
endif()
