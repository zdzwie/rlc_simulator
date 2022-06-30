cmake_minimum_required(VERSION 3.10)

project(RLC_Sim)

add_executable(RLC_Sim
            app/main.cpp
            app/rlc.cpp)

target_include_directories(RLC_Sim PUBLIC
                        "${PROJECT_BINARY_DIR}"
                        "${PROJECT_SOURCE_DIR}/app"
                        "${PROJECT_SOURCE_DIR}/etl/include")

add_compile_definitions(DEFAULT_VOLTAGE=230 DEFAULT_FREQUENCY=50)
