cmake_minimum_required(VERSION 3.15)

project(MyCProject VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# 添加可执行文件：第一个参数是生成的程序名，后面是 C 源文件
add_executable(MatrixMul main.c matrix_multiply_c.c matrix_multiply_asm.c)

# 可选：设置可执行文件输出到 build/bin 目录，整洁易管理
set_target_properties(MatrixMul PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)