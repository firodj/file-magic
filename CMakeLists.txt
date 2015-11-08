cmake_minimum_required (VERSION 3.2)
project (Magic VERSION 5.25)

include (CheckFunctionExists)
include (CheckIncludeFiles)

add_definitions(-DHAVE_CONFIG_H -D_REGEX_RE_COMP -DUNICODE)

check_function_exists (asctime_r HAVE_ASCTIME_R)
check_function_exists (asprintf HAVE_ASPRINTF)
check_function_exists (ctime_r HAVE_CTIME_R)
check_function_exists (fork HAVE_FORK)
check_function_exists (fmtcheck HAVE_FMTCHECK)
check_function_exists (getline HAVE_GETLINE)
check_function_exists (utime HAVE_UTIME)
check_function_exists (mkostemp HAVE_MKOSTEMP)
check_function_exists (mkstemp HAVE_MKSTEMP)

check_include_files (dlfcn.h HAVE_DLFCN_H)
check_include_files (getopt.h HAVE_GETOPT_H)
check_include_files (utime.h HAVE_UTIME_H)
check_include_files (err.h HAVE_ERR_H)
check_include_files (wchar.h HAVE_WCHAR_H)
check_include_files (wctype.h HAVE_WCTYPE_H)
check_include_files (memory.h HAVE_MEMORY_H)
check_include_files (fcntl.h HAVE_FCNTL_H)

configure_file (
  "${PROJECT_SOURCE_DIR}/src/magic.h.in"
  "${PROJECT_BINARY_DIR}/magic.h"
)
configure_file (
  "${PROJECT_SOURCE_DIR}/src/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
)

include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/regex")

set (CMAKE_C_FLAGS "--std=gnu99 ${CMAKE_C_FLAGS}")

add_library(gnurx
	regex/lib/localcharset.c
	regex/lib/regex.c
)
add_library(magic
    src/apprentice.c
    src/apptype.c
    src/ascmagic.c
    src/asctime_r.c
    src/asprintf.c
    src/cdf.c
    src/cdf.h
    src/cdf_time.c
    src/compress.c
    src/ctime_r.c
    src/elfclass.h
    src/encoding.c
    src/file.h
    src/fmtcheck.c
    src/fsmagic.c
    src/funcs.c
    src/getline.c
	src/gmtime_r.c
    src/is_tar.c
	src/localtime_r.c
    src/magic.c
	src/msutils.c
    src/pread.c
    src/print.c
    src/readcdf.c
    src/readelf.c
    src/readelf.h
    src/softmagic.c
    src/strcasestr.c
    src/strlcpy.c
    src/vasprintf.c
)

add_executable(file 
	src/file.c
	src/getopt_long.c
)
target_link_libraries (file	magic gnurx shlwapi)

add_library(magic-5 SHARED src/dummy.c)
target_link_libraries (magic-5 
	-Wl,--whole-archive
	magic gnurx shlwapi
	-Wl,--no-whole-archive
)