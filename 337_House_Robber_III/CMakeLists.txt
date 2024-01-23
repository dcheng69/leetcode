add_library(337_solution Solution337.cc)

target_link_libraries(337_solution PUBLIC
        tools
        )

target_include_directories(337_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/337_House_Robber_III"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(337_unit_test)
