# CMakeList.txt : CMake project for PTZController, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project(obs-ptzcontroller)

find_package(FFmpeg COMPONENTS avutil avfilter REQUIRED)

set(CMAKE_PREFIX_PATH "${QTDIR}")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)


find_package(Qt5Core REQUIRED)
find_package(Qt5Network REQUIRED)	
find_package(Qt5Widgets REQUIRED)

	
set(LIBOBS_LIB "LIBOBS_LIB-NOTFOUND" CACHE FILEPATH "OBS library")
	if(OBS_FRONTEND_LIB EQUAL "LIBOBS_LIB-NOTFOUND")
		message(FATAL_ERROR "Could not find OBS library !")
	endif()

set(OBS_FRONTEND_LIB "OBS_FRONTEND_LIB-NOTFOUND" CACHE FILEPATH "OBS frontend library")
	if(OBS_FRONTEND_LIB EQUAL "OBS_FRONTEND_LIB-NOTFOUND")
		message(FATAL_ERROR "Could not find OBS Frontend API\'s library !")
	endif()	

set(PTHREAD_LIB "PTHREAD_LIB-NOTFOUND" CACHE FILEPATH "PTHREAD library")
	if(PTHREAD_LIB EQUAL "PTHREAD_LIB-NOTFOUND")
		message(FATAL_ERROR "Could not find PTHREAD library !")
	endif()

set(ptzcontroller_SOURCES
	PTZController.cpp
	mainwindow.cpp
	multicameras.cpp
	aboutus.cpp
	joystickdlg.cpp
	joystickwrapper.cpp
	QJoysticks.cpp
	SDL_Joysticks.cpp
	VirtualJoystick.cpp
	)

set(ptzcontroller_HEADERS
	PTZController.h
	mainwindow.h
	multicameras.h
	aboutus.h
	constants.h
	joystickdlg.h
	joystickwrapper.h
	JoysticksCommon.h
	QJoysticks.h
	SDL_Joysticks.h
	VirtualJoystick.h
	)
	

add_library(obs-ptzcontroller MODULE
	${ptzcontroller_SOURCES}
	${ptzcontroller_HEADERS}
	ptzqrc.qrc
	)
	
include_directories(
	"${LIBOBS_INCLUDE_DIR}/../UI/obs-frontend-api"
	${LIBOBS_INCLUDE_DIR}
	${FFMPEG_INCLUDE_DIRS}
	${SDL_INCLUDE_DIRS}

	${PTHREAD_INCLUDE_DIRS}
	${Qt5Core_INCLUDES}
	${Qt5Network_INCLUDES}
	${Qt5Widgets_INCLUDES}
	
	)
		
target_link_libraries(obs-ptzcontroller
	${LIBOBS_LIB}
	${OBS_FRONTEND_LIB}
	${FFMPEG_LIBRARIES}
	${PTHREAD_LIB}
	${SDL_LIB}
	Qt5::Core
	Qt5::Network
	Qt5::Widgets
	)
	

