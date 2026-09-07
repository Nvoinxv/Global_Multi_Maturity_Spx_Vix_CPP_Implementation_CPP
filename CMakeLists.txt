cmake_minimum_required(VERSION 3.23)

project(GLOBAL_MULLTI_MATURITY VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
    main.cpp
    src/read_env_data.cpp
    src/get_data.cpp
    )

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    )


target_link_libraries(${PROJECT_NAME} PRIVATE
    curl
)