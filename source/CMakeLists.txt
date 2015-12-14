set(TARGET_NAME game_engine)

file(GLOB_RECURSE SRC_FILES *.cpp)


add_executable(${TARGET_NAME} ${SRC_FILES})

target_include_directories(${TARGET_NAME} PRIVATE
    ${GLM_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIRS}
    "${OPENGL_INCLUDE_DIR}"
    "${SDL2_INCLUDE_DIR}"
    "${CMAKE_SOURCE_DIR}/include")

target_link_libraries(${TARGET_NAME}
                      "${SDL2_LIBRARY}"
                      "${SDL2_IMAGE_LIBRARY}"
                      "${OPENGL_gl_LIBRARY}"
                      ${GLEW_LIBRARIES})
