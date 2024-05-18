add_library(988_solution Solution988.cc)

target_link_libraries(988_solution PUBLIC
        tools
        )

target_include_directories(988_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/988_Smallest_String_Starting_From_Leaf"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(988_unit_test)
