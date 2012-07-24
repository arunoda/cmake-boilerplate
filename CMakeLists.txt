cmake_minimum_required(VERSION 2.6)

#set project name
set(PRJ_NAME foobar)
#indicate type of the project as executable, otherwise it is a library
set(PRJ_TYPE_EXECUTABLE 1)
#allways build libarary (with object files)
set(PRJ_BUILD_LIBRARY 1)
#main file name - used to filter this with object files
set(PRJ_MAIN_FILE "main.c")

#libraries to link
set(LINK_LIBS "")
#define cflags
set(CFLAGS "")
#define header include directories as list
set(INCLUDE_DIR )

project(${PRJ_NAME})

add_subdirectory(src)
add_subdirectory(tests)

#set enable testing
enable_testing()