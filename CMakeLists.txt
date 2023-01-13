#
# DANTE :: System Automatycznych Testów Jednostkowych oraz Akceptacyjnych
# Tomasz Jaworski, 2018-2020
#
# Plik wygenerowany automatycznie
# Znacznik czasowy: 2023-01-13 16:21:17.709894
#

cmake_minimum_required(VERSION 3.17)
project(project1 C)

# Przyjmij standard C11
set(CMAKE_C_STANDARD 11)

# Ustaw opcje kompilatora (z raportu Dante)
add_compile_options(
      "-ggdb3"
      "-Wno-error=unused-parameter"
      "-fdiagnostics-color"
      "-Wno-error=parentheses"
      "-DINSIDE_DANTE"
      "-D_ANSI_OUTPUT"
      "-Werror"
      "-pedantic"
      "-D_GNU_SOURCE"
      "-std=c11"
      "-Wno-error=implicit-fallthrough"
      "-Wno-parentheses"
      "-Werror=vla"
      "-xc"
      "-Wextra"
      "-Wall"
      "-fmax-errors=5"

)

# Ustaw opcje konsolidatora (z raportu Dante)
add_link_options(
        "-ggdb3"
        "-Wl,-cref"
        "-Wl,-Map=main.map"
        "-Wl,-wrap,main"
)

# Utwórz target 'project1' i dodaj do niego pliki źródlowe:
add_executable(project1
        "main.c"
        "file_reader.c"
        "unit_helper_v2.c"
        "unit_test_v2.c"
        "rdebug.c"
)

# Dołącz niezbędne biblioteki
target_link_libraries(project1
        "m"
)