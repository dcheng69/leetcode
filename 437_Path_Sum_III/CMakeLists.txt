add_library(437_solution Solution437.cc)

target_link_libraries(437_solution PUBLIC
        tools
        )

target_include_directories(437_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/437_Path_Sum_III"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(437_unit_test)
