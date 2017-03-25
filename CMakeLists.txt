# cmake 最低版本
cmake_minimum_required(VERSION 2.8)

# 项目名称
project(Demo)

# 加入一个配置头文件
configure_file(
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)

option(USE_MYMATH "使用自己的match方法" ON)


if(USE_MYMATH)
    include_directories("${PROJECT_SOURCE_DIR}/math")
    # 添加match子目录
    add_subdirectory(math)
    set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif(USE_MYMATH)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRC
aux_source_directory(. DIR_SRCS)



# 指定生成
add_executable(Demo ${DIR_SRCS})

# 添加链接库
target_link_libraries(Demo ${EXTRA_LIBS})
