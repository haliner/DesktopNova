# Check necessary modules.
PKG_CHECK_MODULES(GLIB REQUIRED glib-2.0)
PKG_CHECK_MODULES(GTK REQUIRED gtk+-3.0)


# Add library include directories to search path.
INCLUDE_DIRECTORIES(
  ${GLIB_INCLUDE_DIRS}
  ${GTK_INCLUDE_DIRS}
)


# desktopnovad
ADD_EXECUTABLE(
  desktopnova
  main.c
)
TARGET_LINK_LIBRARIES(
  desktopnova
  ${GLIB_LIBRARIES}
  ${GTK_LIBRARIES}
)


# Install target into directory for binary executables.
INSTALL(
  TARGETS     desktopnova
  DESTINATION ${DIR_BIN}
)
