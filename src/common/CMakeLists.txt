# Check necessary modules.
PKG_CHECK_MODULES(GLIB REQUIRED glib-2.0)


# Add library include directories to search path.
INCLUDE_DIRECTORIES(
  ${GLIB_INCLUDE_DIRS}
)


# desktopnovad
ADD_LIBRARY(
  desktopnova-common
  common.c
  helpers.c
  profiles.c
  settings.c
)
TARGET_LINK_LIBRARIES(
  desktopnova-common
  ${GLIB_LIBRARIES}
)


# Install target into directory for binary executables.
INSTALL(
  TARGETS     desktopnova-common
  DESTINATION ${DIR_LIB}
)
