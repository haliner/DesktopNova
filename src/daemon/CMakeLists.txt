# The daemon is responsibly for changing the background image. It should act
# completely without user interaction.
ADD_EXECUTABLE(
	desktopnovad
	daemon.cpp
	main.cpp
)

TARGET_LINK_LIBRARIES(
	desktopnovad
	desktopnova-common
)

INSTALL(
  TARGETS desktopnovad
  ${DESTINATIONS}
)
