set(TARGET_NAME GameHomework)

file(GLOB SRC_FILES *.cpp)

add_executable(${TARGET_NAME} ${SRC_FILES})

target_include_directories(${TARGET_NAME} PRIVATE
    ${SDL2_INCLUDE_DIR}
    ${SDL2_IMAGE_INCLUDE_DIRS}
    "${CMAKE_SOURCE_DIR}/include")

target_link_libraries(${TARGET_NAME} ${SDL2_LIBRARY})
target_link_libraries(${TARGET_NAME} ${SDL2_IMAGE_LIBRARY})
target_link_libraries(${TARGET_NAME} ${BOX2D_LIBRARY})
