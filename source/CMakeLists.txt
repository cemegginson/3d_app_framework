add_subdirectory(components)
add_subdirectory(core)
# add_subdirectory(input)
add_subdirectory(render)
add_subdirectory(util)

add_subdirectory(shaders)

set(TARGET_NAME game_engine)

set(SRC_FILES main.cpp)

add_executable(${TARGET_NAME} ${SRC_FILES})

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
        components_lib
        core_lib
        # input_management_lib
        opengl_lib
        util_lib
)

install(TARGETS ${TARGET_NAME} DESTINATION bin)
