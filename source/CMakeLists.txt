set(TARGET_NAME game_engine)

file(GLOB_RECURSE SRC_FILES *.cpp)


add_executable(${TARGET_NAME} ${SRC_FILES})

target_include_directories(${TARGET_NAME} PRIVATE
    "${GLEW_INCLUDE_DIRS}"
    "${GLM_INCLUDE_DIRS}"
    "${OPENGL_INCLUDE_DIR}"
    "${SDL2_INCLUDE_DIR}"
    "${CMAKE_SOURCE_DIR}/include")

target_link_libraries(${TARGET_NAME}
                      "${SDL2_LIBRARY}"
                      "${OPENGL_gl_LIBRARY}"
                      "${GLEW_LIBRARIES}"
                      "${GLEW_MX_LIBRARIES}")
