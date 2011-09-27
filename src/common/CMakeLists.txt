# Replace the CMake variables in the template file and create a header file,
# which can be included in the C++ source code.
CONFIGURE_FILE(buildconfig.hpp.in buildconfig.hpp)

# The newly created header file is placed into the current binary directory.
# The current binary directory must be added to the include directories,
# otherwise the compiler can't find the header file.
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

# This library contains most of the common code and is necessary for building
# the other targets of the project.
ADD_LIBRARY(
	desktopnova-common STATIC
	configfile.cpp
	configuration.cpp
	path.cpp
	profile.cpp
)

# Link the library against the necessary third-party libraries.
TARGET_LINK_LIBRARIES(
	desktopnova-common
	${Boost_FILESYSTEM_LIBRARIES}
)
