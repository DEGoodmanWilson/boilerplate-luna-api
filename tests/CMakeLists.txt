cmake_minimum_required(VERSION 3.7)

enable_testing()

add_executable(${PROJECT_NAME}_tests
        main.cpp
#        basic.cpp
        )

target_link_libraries(${PROJECT_NAME}_tests ${CONAN_LIBS})

add_test(${PROJECT_NAME} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}_tests)