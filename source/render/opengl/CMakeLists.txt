set(TARGET_NAME opengl_lib)

set(SRC_FILES
    gl_camera.cpp
    gl_drawable.cpp
    gl_model_store.cpp
    gl_model.cpp
    opengl_renderer.cpp
)

add_library(${TARGET_NAME} STATIC ${SRC_FILES})

target_include_directories(
        ${TARGET_NAME} PRIVATE
        ${GLEW_INCLUDE_DIRS}
        ${GLM_INCLUDE_DIRS}
        "${OPENGL_INCLUDE_DIR}"
        "${SDL2_INCLUDE_DIR}"
        "${CMAKE_SOURCE_DIR}/include"
)

target_link_libraries(
        ${TARGET_NAME}
        ${GLEW_LIBRARIES}
        ${GLEW_MX_LIBRARIES}
        "${OPENGL_gl_LIBRARY}"
        "${SDL2_LIBRARY}"
)
