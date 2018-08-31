cmake_minimum_required(VERSION 3.9)
project(libft)

set(CMAKE_C_STANDARD 99)
#set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")


set(LIB_SRC libft/)

add_executable (Library_run main.c)

#*------------------------------------*\
#    CHAR
#*------------------------------------*/
file(GLOB FILE_CHAR "${LIB_SRC}char/*.c")

#*------------------------------------*\
#    DLL
#*------------------------------------*/
file(GLOB FILE_DLL_CONSTRUCT "${LIB_SRC}dll/*.c")
file(GLOB FILE_DLL_FILE "${LIB_SRC}dll/**/*.c")

#*------------------------------------*\
#    IO
#*------------------------------------*/
file(GLOB FILE_IO "${LIB_SRC}io/*.c")

#*------------------------------------*\
#    MEMORY
#*------------------------------------*/
file(GLOB FILE_MEMORY "${LIB_SRC}memory/*.c")

#*------------------------------------*\
#    PRINTF
#*------------------------------------*/
file(GLOB FILE_PRINTF_1 "${LIB_SRC}printf/*.c")
file(GLOB FILE_PRINTF_2 "${LIB_SRC}printf/**/*.c")
file(GLOB FILE_PRINTF_3 "${LIB_SRC}printf/**/**/*.c")
file(GLOB FILE_PRINTF_4 "${LIB_SRC}printf/**/**/**/*.c")


#*------------------------------------*\
#    STRING
#*------------------------------------*/
file(GLOB FILE_STRING "${LIB_SRC}string/*.c")

#*------------------------------------*\
#    TEST
#*------------------------------------*/
file(GLOB FILE_TEST "${LIB_SRC}test/*")
file(GLOB FILE_TEST_FILE "${LIB_SRC}test/test_file/*")

#*------------------------------------*\
#    HEADER
#*------------------------------------*/
file(GLOB HEADERS "${LIB_SRC}header/*")

add_library(libft STATIC
        #char
        ${FILE_CHAR}

        #dll
        ${FILE_DLL_CONSTRUCT}
        ${FILE_DLL_FILE}

        #io
        ${FILE_IO}

        #memory
        ${FILE_MEMORY}

        #printf
        ${FILE_PRINTF_1}
        ${FILE_PRINTF_2}
        ${FILE_PRINTF_3}
        ${FILE_PRINTF_4}

        #string
        ${FILE_STRING}

        #test
        ${FILE_TEST}
        ${FILE_TEST_FILE}

        #HEADER
        ${HEADERS}
        libft/ft_library_headerd.h
        libft/string/check_char_into_str.c)

target_include_directories(libft PUBLIC ${LIB_SRC}header/)

target_link_libraries(Library_run libft)