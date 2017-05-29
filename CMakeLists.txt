cmake_minimum_required(VERSION 3.6)
project(lem-in)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -Wall -Wextra -Werror -std=c99")

set(SOURCE_FILES main.c lem-in.h libft.h ft_printf.h get_next_line.h check_int.c base_set.c)
add_executable(lem-in ${SOURCE_FILES})
target_link_libraries(lem-in ${CMAKE_SOURCE_DIR}/libft.a)