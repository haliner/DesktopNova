# Project settings
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(DesktopNova C)


# Directory declarations where the project files should be installed into
# later.
SET(DIR_BIN      bin)
SET(DIR_LIB      lib)
SET(DIR_LIBEXEC  lib/desktopnova)
SET(DIR_HELPER   ${DIR_LIBEXEC}/helper)

# Special directory declaration. This variable contains the relative path
# from the installed binaries (desktopnova, desktopnovad) to the helper
# directory. In other words: DIR_BIN -> DIR_HELPER
SET(DIR_HELPER_REL ../${DIR_HELPER})


# Add the src/ subdirectory to the search path of the compiler. This way all
# c source files can include the project's header files easily.
# Also add the src/ subdirectory of the binary output directory, because
# some file will be automatically generated (config.h, etc.).
INCLUDE_DIRECTORIES(src)
INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR}/src)


# The PkgConfig is important, because it's enables to search library packages
# and automatically determine the compiler and linker flags.
FIND_PACKAGE(PkgConfig REQUIRED)


# Processes all the subdirectories.
ADD_SUBDIRECTORY(src)
