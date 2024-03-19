add_library(513_solution Solution513.cc)

target_link_libraries(513_solution PUBLIC
        tools
        )

target_include_directories(513_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/513_Find_Bottom_Left_Tree_Value"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(513_unit_test)
