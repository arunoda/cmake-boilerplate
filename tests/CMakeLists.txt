## Testing the project

#include files including headers in the src
include_directories(. ../src)
include_directories(${INCLUDE_DIR})

#add test sources
file(GLOB TEST_SOURCES *.c)

#set enable testing
enable_testing()
add_definitions("${CFLAGS}")
link_libraries("${LINK_LIBS}")
link_libraries("${PRJ_NAME}-static")

#adding tests foreach test source file
foreach(filename ${TEST_SOURCES})
	
	#get the file name of the source file
	if(WIN32) 
		string(REGEX REPLACE ".*\\" "" testname "${filename}" )
	else(WIN32)
		string(REGEX REPLACE ".*/" "" testname "${filename}" )
	endif(WIN32)

	#remove .c extension
	string(REGEX REPLACE ".c" "" testname "${testname}" )

	#create executable
	add_executable(${testname} ${OBJECTS} ${filename})
	#configure for testing
	add_test(${testname} ${testname})

	message("${testname} ${filename}")
endforeach(filename)