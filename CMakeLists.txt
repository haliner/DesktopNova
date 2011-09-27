################################################################################
# General Project Configuration
################################################################################
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(DesktopNova CXX)




################################################################################
# Target Directory Definitions
################################################################################

# Directory declarations where the project files should be installed into
# later.
SET(DIR_RUNTIME bin)
SET(DIR_ARCHIVE lib)
SET(DIR_LIBRARY lib)
SET(DIR_RUNTIME_HELPER lib/desktopnova/helpers)

# Predefine the destinations for the install directives. Makes things a lot
# easier later.
SET(
	DESTINATIONS
	RUNTIME DESTINATION ${DIR_RUNTIME}
	ARCHIVE DESTINATION ${DIR_ARCHIVE}
	LIBRARY DESTINATION ${DIR_LIBRARY}
)
SET(
	DESTINATIONS_HELPER
	RUNTIME DESTINATION ${DIR_RUNTIME_HELPER}
	ARCHIVE DESTINATION ${DIR_ARCHIVE}
	LIBRARY DESTINATION ${DIR_LIBRARY}
)

# Special directory declaration. This variable contains the relative path
# from the installed binaries (desktopnova, desktopnovad) to the helper
# directory. In other words: DIR_BIN -> DIR_HELPER
SET(DIR_HELPER_REL ../${DIR_RUNTIME_HELPER})




################################################################################
# Third-Party Stuff
################################################################################

FIND_PACKAGE(Boost REQUIRED COMPONENTS filesystem)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})




################################################################################
# Subdirectories
################################################################################

ADD_SUBDIRECTORY(src)
