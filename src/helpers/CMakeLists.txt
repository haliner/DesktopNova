# Check necessary modules.
PKG_CHECK_MODULES(GLIB REQUIRED glib-2.0)
PKG_CHECK_MODULES(DCONF REQUIRED dconf)
PKG_CHECK_MODULES(GCONF REQUIRED gconf-2.0)
PKG_CHECK_MODULES(XFCONF REQUIRED libxfconf-0)


# Add library include directories to search path.
INCLUDE_DIRECTORIES(
  ${GLIB_INCLUDE_DIRS}
  ${DCONF_INCLUDE_DIRS}
  ${GCONF_INCLUDE_DIRS}
  ${XFCONF_INCLUDE_DIRS}
)


# gnome-shell
ADD_EXECUTABLE(
  gnome-shell
  gnome-shell.c
)
TARGET_LINK_LIBRARIES(
  gnome-shell
  ${GLIB_LIBRARIES}
  ${DCONF_LIBRARIES}
)


# gnome2
ADD_EXECUTABLE(
  gnome2
  gnome2.c
)
TARGET_LINK_LIBRARIES(
  gnome2
  ${GLIB_LIBRARIES}
  ${GCONF_LIBRARIES}
)


# xfce-xfconf
ADD_EXECUTABLE(
  xfce-xfconf
  xfce-xfconf.c
)
TARGET_LINK_LIBRARIES(
  xfce-xfconf
  ${GLIB_LIBRARIES}
  ${XFCONF_LIBRARIES}
)


# Install target into helper directory.
INSTALL(
  TARGETS     gnome-shell gnome2 xfce-xfconf
  DESTINATION ${DIR_HELPER}
)
