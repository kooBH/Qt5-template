# CMAKE version of Ubuntu 16.04 is 3.5.
cmake_minimum_required(VERSION 3.5)
project(run)


set(LINKLIBS)
set(COMPILE_OPTION)
set(SRC)
set(INCL)
  
if(NOT MSVC)
	list(APPEND LINKLIBS
		m
	)
endif()

list(APPEND SRC
	src/main.cpp
)
	
list(APPEND INCL
	lib
  lib/verdigris
	
	lib/QtCore
	lib/QtGui
	lib/QtWidgets
)

## QtFramework ##
if(UNIX AND NOT APPLE)
  list(APPEND LINKLIBS
    ${PROJECT_SOURCE_DIR}/lib/libQt5Widgets.so.5
    ${PROJECT_SOURCE_DIR}/lib/libQt5Core.so.5
    ${PROJECT_SOURCE_DIR}/lib/libQt5Gui.so.5
	
  	### X11 ###
    ${PROJECT_SOURCE_DIR}/lib/libQt5XcbQpa.so.5
    ${PROJECT_SOURCE_DIR}/lib/platforms/libqxcb.so

    ### Input ###
    ${PROJECT_SOURCE_DIR}/lib/platforminputcontexts/libcomposeplatforminputcontextplugin.so
    ${PROJECT_SOURCE_DIR}/lib/platforminputcontexts/libibusplatforminputcontextplugin.so
	)
  list(APPEND COMPILE_OPTION
      -fPIC
    )
elseif(WIN32)
	list(APPEND LINKLIBS
	${PROJECT_SOURCE_DIR}/lib/Qt5Widgets.lib
  ${PROJECT_SOURCE_DIR}/lib/Qt5Core.lib
  ${PROJECT_SOURCE_DIR}/lib/Qt5Gui.lib
	)
endif()

add_executable(${PROJECT_NAME} ${SRC})
target_include_directories(${PROJECT_NAME}	PRIVATE	${INCL}  )
target_link_libraries(${PROJECT_NAME} ${LINKLIBS})
target_compile_options(${PROJECT_NAME} PRIVATE ${COMPILE_OPTION} )
set_target_properties(${PROJECT_NAME} PROPERTIES  CXX_STANDARD 14 )


