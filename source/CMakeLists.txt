set(TARGET_NAME GameHomework)

file(GLOB_RECURSE SRC_FILES *.cpp)


add_executable(${TARGET_NAME} ${SRC_FILES})

target_include_directories(${TARGET_NAME} PRIVATE
    glm::glm
    ${SDL2_IMAGE_INCLUDE_DIRS}
    "${BOX2D_INCLUDE_DIR}"
    "${OPENGL_INCLUDE_DIR}"
    "${SDL2_INCLUDE_DIR}"
    "${CMAKE_SOURCE_DIR}/include")

target_link_libraries(${TARGET_NAME}
                      "${SDL2_LIBRARY}"
                      "${SDL2_IMAGE_LIBRARY}"
                      "${BOX2D_LIBRARY}"
                      "${OPENGL_gl_LIBRARY}"
                      ${GLEW_LIBRARIES})
