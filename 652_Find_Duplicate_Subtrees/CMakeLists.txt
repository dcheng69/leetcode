add_library(652_solution Solution652.cc)

target_link_libraries(652_solution PUBLIC
        tools
        )

target_include_directories(652_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/652_Find_Duplicate_Subtrees"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(652_unit_test)
