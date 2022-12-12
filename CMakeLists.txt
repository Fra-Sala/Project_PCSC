
cmake_minimum_required (VERSION 3.0)
project (Project_PCSC)

set(CMAKE_CXX_STANDARD 17)


add_subdirectory(fparser4.5.2)

add_subdirectory(googletest)


enable_testing()


file(GLOB filesmain "src/*.cpp")
add_executable(ProjectOdeSolver src/main.cpp ${filesmain})

file(GLOB filestest "src/*.h" "src/*.cpp")

FOREACH(item ${filestest})
    IF(${item} MATCHES "src/main.cpp")
        LIST(REMOVE_ITEM filestest ${item})
    ENDIF(${item} MATCHES "src/main.cpp")
ENDFOREACH(item)

FOREACH(item ${filestest})
    IF(${item} MATCHES "src/ManageInput.cpp")
        LIST(REMOVE_ITEM filestest ${item})
    ENDIF(${item} MATCHES "src/ManageInput.cpp")
ENDFOREACH(item)

add_executable(test_main test/test.cc ${filestest})

target_link_libraries(ProjectOdeSolver PUBLIC fparser)
target_link_libraries(test_main PUBLIC fparser)
target_link_libraries(test_main PUBLIC gtest_main)

target_include_directories(ProjectOdeSolver PUBLIC "${PROJECT_BINARY_DIR}"   "${PROJECT_SOURCE_DIR}/fparser4.5.2"        )
target_include_directories(test_main PUBLIC "${PROJECT_BINARY_DIR}"   "${PROJECT_SOURCE_DIR}/fparser4.5.2"        )

