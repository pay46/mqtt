# cmake 最低版本
cmake_minimum_required(VERSION 2.8)

# 项目名称
project(Momomqtt)

set (VERSION 0.0.1)


# 加入一个配置头文件
configure_file(
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)


option(WITH_TLS
	"Include SSL/TLS support?" ON)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRC
aux_source_directory(. DIR_SRCS)


#在这些目录下的头文件可以直接include
include_directories(./lib)


# 指定生成
add_executable(momomqtt ${DIR_SRCS})

# 添加链接库
target_link_libraries(momomqtt ${EXTRA_LIBS})
