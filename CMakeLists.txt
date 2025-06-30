cmake_minimum_required(VERSION 3.10)

project(Optimizations_Vectorization&Algebra)

set(CMAKE_CXX_STANDARD 23)

# Compiler-specific flags
if (MSVC)
    set(VEC_FLAGS        )  # Default vectorization
    set(NOVEC_FLAGS      /arch:IA32)
    set(FAST_FLAGS       /fp:fast)
    set(NOFAST_FLAGS     /fp:precise)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(VEC_FLAGS        -march=native)
    set(NOVEC_FLAGS      -fno-vectorize -fno-slp-vectorize)
    set(FAST_FLAGS       -ffast-math)
    set(NOFAST_FLAGS     -fno-fast-math)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(VEC_FLAGS        -march=native)
    set(NOVEC_FLAGS      -fno-tree-vectorize)
    set(FAST_FLAGS       -ffast-math)
    set(NOFAST_FLAGS     -fno-fast-math)
endif()

# Helper function to create targets
function(make_target name)
    add_executable(${name} main.cpp)
    target_compile_options(${name} PRIVATE ${ARGN})
endfunction()

# Four combinations
make_target(no_vec_no_fast ${NOVEC_FLAGS} ${NOFAST_FLAGS})
make_target(yes_vec_no_fast ${VEC_FLAGS} ${NOFAST_FLAGS})
make_target(no_vec_yes_fast ${NOVEC_FLAGS} ${FAST_FLAGS})
make_target(yes_vec_yes_fast ${VEC_FLAGS} ${FAST_FLAGS})

set(EXECUTABLE_FOLDER $<TARGET_FILE_DIR:no_vec_no_fast>)

configure_file(include/config.hpp.in include/config.hpp.in)

add_custom_command(
    TARGET no_vec_no_fast
    POST_BUILD
    BYPRODUCTS "${CMAKE_BINARY_DIR}/include/config.hpp"
    COMMAND ${CMAKE_COMMAND}
        -DINPUT="${CMAKE_BINARY_DIR}/include/config.hpp.in"
        -DOUTPUT="${CMAKE_BINARY_DIR}/include/config.hpp"
        -DTARGET_NAME="no_vec_no_fast"
        -DTARGET_PATH="$<TARGET_FILE_DIR:no_vec_no_fast>"
        -P ${CMAKE_SOURCE_DIR}/replacer.cmake
    COMMENT "🔧 Patching config.hpp with real target path"
)
    
add_executable(runner runner.cpp)

target_include_directories(runner PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/include)

enable_testing()
add_test(NAME Main COMMAND runner)

