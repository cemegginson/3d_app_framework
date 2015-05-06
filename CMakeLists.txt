cmake_minimum_required(VERSION 2.6)
project(GameHomework)

set(CMAKE_USE_RELATIVE_PATHS TRUE)

# Use our modified FindSDL2* modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

# Set an output directory for our binaries
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Bump up warning levels appropriately for clang, gcc & msvc
# Also set debug/optimization flags depending on the build type. IDE users choose this when
# selecting the build mode in their IDE
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
	if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
	endif()
endif()

if(WIN32)
	set(SDL2_INCLUDE_DIR  "${CMAKE_SOURCE_DIR}/ThirdParty/SDL2-2.0.3/include")
	set(SDL2_LIBRARY_TEMP "${CMAKE_SOURCE_DIR}/ThirdParty/SDL2-2.0.3/lib/x86/SDL2.lib")
	set(SDL2MAIN_LIBRARY  "${CMAKE_SOURCE_DIR}/ThirdParty/SDL2-2.0.3/lib/x86/SDL2main.lib")
	set(SDL2_IMAGE_INCLUDE_DIR  "${CMAKE_SOURCE_DIR}/ThirdParty/SDL2_image-2.0.0/include")
	set(SDL2_IMAGE_LIBRARY "${CMAKE_SOURCE_DIR}/ThirdParty/SDL2_image-2.0.0/lib/x86/SDL2_image.lib")
	set(BOX2D_INCLUDE_DIR  "${CMAKE_SOURCE_DIR}/ThirdParty/Box2D/Box2D")
	set(BOX2D_LIBRARY "${CMAKE_SOURCE_DIR}/ThirdParty/Box2D/Box2D/") #Fix for Windows :TODO
endif()

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(Box2D REQUIRED)

message(STATUS "SDL2_LIBRARY...... ${SDL2_LIBRARY}")
message(STATUS "SDL2_INCLUDE_DIR.. ${SDL2_INCLUDE_DIR}")
message(STATUS "BOX2D_LIBRARY..... ${BOX2D_LIBRARY}")
message(STATUS "BOX2D_INCLUDE_DIR. ${BOX2D_INCLUDE_DIR}")

# Include directories with relevant items
add_subdirectory(Source)
