
cmake_minimum_required (VERSION 3.0)
project (Project_PCSC)

set(CMAKE_CXX_STANDARD 17)


add_subdirectory(fparser4.5.2)
#add_library(fparser   fparser4.5.2/fparser.cc)

add_subdirectory(googletest)



#add_subdirectory(${CMAKE_BINARY_DIR}/googletest)
#add_subdirectory(fparser4.5.2)

# For Windows: Prevent overriding the parent project's compiler/linker settings
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Now simply link against gtest or gtest_main as needed. Eg

add_executable(Project_PCSC src/main.cpp src/AbstractOdeSolver.cpp src/AbstractImplicitOdeSolver.cpp src/ForwardEuler.cpp
        src/AdamsBashforth.cpp src/ExplicitRungeKutta.cpp src/AbstractParser.cpp src/Fparser.cpp src/BackwardEuler.cpp
        src/BDFSchemes.cpp src/AdamsMoulton.cpp test/test.cc src/ManageInput.cpp)


#add_executable(GoogleTest test/test.cc)
#target_link_directories(Project_PCSC PRIVATE fparser4.5.2)


target_link_libraries(Project_PCSC PUBLIC fparser)
target_link_libraries(Project_PCSC PUBLIC gtest_main)

target_include_directories(Project_PCSC PUBLIC "${PROJECT_BINARY_DIR}"   "${PROJECT_SOURCE_DIR}/fparser4.5.2"        )

#add_custom_target(test ./test_pcsc DEPENDS test_pcsc)
