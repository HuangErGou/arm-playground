# 指定 CMake 的最低版本要求（根据你的环境调整，如 3.10、3.16）
cmake_minimum_required(VERSION 3.15)

# 设置项目名称、版本，明确指定使用 C 语言（LANGUAGES C）
project(MyCProject VERSION 1.0 LANGUAGES C)

# 设置 C 语言标准（C99/C11/C17 等，按需选择，C99 兼容性最广）
set(CMAKE_C_STANDARD 99)
# 强制使用指定的 C 标准，不降级
set(CMAKE_C_STANDARD_REQUIRED ON)
# 禁用编译器特定的扩展
set(CMAKE_C_EXTENSIONS OFF)

# 添加可执行文件：第一个参数是生成的程序名，后面是 C 源文件
add_executable(MyCApp main.c rgb_deinterleave_c.c rgb_deinterleave_neon.c)
target_compile_options(MyCApp PRIVATE 
            -march=armv8-a  # ARM64 架构指定
        )

# 可选：设置可执行文件输出到 build/bin 目录，整洁易管理
set_target_properties(MyCApp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
