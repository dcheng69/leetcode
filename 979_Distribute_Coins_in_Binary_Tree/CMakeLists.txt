add_library(979_solution Solution979.cc)

target_link_libraries(979_solution PUBLIC
        tools
        )

target_include_directories(979_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/979_Distribute_Coins_in_Binary_Tree"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(979_unit_test)
