find_package(Threads REQUIRED)

add_library(449_solution Solution449.cc)

target_link_libraries(449_solution PUBLIC
        Threads::Threads
        tools
        )

target_include_directories(449_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/449_Serialize_and_Deserialize_BST"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(449_unit_test)
