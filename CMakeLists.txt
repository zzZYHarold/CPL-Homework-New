cmake_minimum_required(VERSION 3.20)

project(CPL C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# ------------------------------------------------------------
# 自动寻找项目中的所有 .c 文件
#
# 约定：
#   每个 .c 文件都是一个独立程序，并且拥有自己的 main()。
#
# CONFIGURE_DEPENDS：
#   新增/删除 .c 文件后，CMake 会重新检查文件列表。
# ------------------------------------------------------------

file(GLOB_RECURSE C_SOURCES
        CONFIGURE_DEPENDS
        RELATIVE "${PROJECT_SOURCE_DIR}"
        "${PROJECT_SOURCE_DIR}/*.c"
)

foreach(source_file IN LISTS C_SOURCES)

    # 排除 CLion / CMake 自动生成的构建目录。
    # 否则 cmake-build-debug 中 CMake 自己生成的 .c 文件
    # 也会被误认为是我们的作业程序。
    if(source_file MATCHES "^cmake-build-"
            OR source_file MATCHES "^build/"
            OR source_file MATCHES "^out/")
        continue()
    endif()

    # 去掉末尾的 .c
    # 例如：
    #   main.c              -> main
    #   week01/problem1.c   -> week01/problem1
    string(REGEX REPLACE "\\.c$" "" target_path "${source_file}")

    # 转换为合法且易识别的 CMake target 名称
    #
    # 例如：
    #   main.c
    #       -> main
    #
    #   week01/problem1.c
    #       -> week01_problem1
    #
    #   1-types-io/a+b.c
    #       -> _1_types_io_a_b
    string(MAKE_C_IDENTIFIER "${target_path}" target_name)

    # 极少数情况下，不同路径转换后可能得到相同 target 名。
    # 若发生冲突，则附加源文件路径的短 hash。
    if(TARGET "${target_name}")
        string(MD5 source_hash "${source_file}")
        string(SUBSTRING "${source_hash}" 0 8 source_hash)
        set(target_name "${target_name}_${source_hash}")
    endif()

    # 每个 .c 文件生成一个独立可执行程序
    add_executable("${target_name}" "${source_file}")

    # Linux 下使用 math.h 中部分函数时可能需要显式链接 libm
    if(UNIX AND NOT APPLE)
        target_link_libraries("${target_name}" PRIVATE m)
    endif()

endforeach()