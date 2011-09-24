# Check necessary modules.
PKG_CHECK_MODULES(GLIB REQUIRED glib-2.0)


# Add library include directories to search path.
INCLUDE_DIRECTORIES(
  ${GLIB_INCLUDE_DIRS}
)


# desktopnovad
ADD_EXECUTABLE(
  desktopnovad
  daemon.c
)
TARGET_LINK_LIBRARIES(
  desktopnovad
  desktopnova-common
  ${GLIB_LIBRARIES}
)


# Install target into directory for binary executables.
INSTALL(
  TARGETS     desktopnovad
  DESTINATION ${DIR_BIN}
)
