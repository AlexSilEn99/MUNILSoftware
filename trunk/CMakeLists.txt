##---------------------------------------------------------------------------
## Author:      Jorgen Bodde
## Copyright:   (c) Jorgen Bodde
## License:     wxWidgets License
## Update:      2008/12 by Werner Smekal
##---------------------------------------------------------------------------
 
# define minimum cmake version
cmake_minimum_required(VERSION 2.6.2)
 
# Our project is called 'minimal' this is how it will be called in
# visual studio, and in our makefiles. 
project(wxMUN)
 
# Location where cmake first looks for cmake modules.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

find_package(LibXml++ REQUIRED)

##---------------------------------------------------
## Please set your wxWidgets configuration here
##--------------------------------------------------- 
 
# Here you can define what libraries of wxWidgets you need for your
# application. You can figure out what libraries you need here;
# http://www.wxwidgets.org/manuals/2.8/wx_librarieslist.html
# We need the Find package for wxWidgets to work
find_package(wxWidgets COMPONENTS base core REQUIRED)
 
##---------------------------------------------------
## Actual config file starts here
##--------------------------------------------------- 
 
# wxWidgets include directory
include_directories(include ${wxWidgets_INCLUDE_DIRS} ${LIBXMLPP_INCLUDE_DIR} ${GLIBMM_INCLUDE_DIR} ${GLIB_INCLUDE_DIR})
 
# add wxWidgets definitions
add_definitions(${wxWidgets_DEFINITIONS})
 
# For convenience we define the sources as a variable. You can add 
# header files and cpp/c files and CMake will sort them out
set(SRCS src/committee.cpp src/confirmtopicswapdialog.cpp src/country.cpp src/editcommitteedialog.cpp src/gui.cpp src/main.cpp src/moderatedcaucusdialog.cpp src/newcommitteedialog.cpp src/noname.cpp src/session.cpp src/unmoderatedcaucusdialog.cpp src/wxmunframe.cpp)

# If we build for windows systems, we also include the resource file
# containing the manifest, icon and other resources
#if(WIN32)
#  set(SRCS ${SRCS} minimal.rc)
#endif(WIN32)
 
# Here we define the executable minimal.exe or minimal on other systems
# the above paths and defines will be used in this build
add_executable(wxMUN WIN32 ${SRCS})
 
# We add to our target 'minimal' the wxWidgets libraries. These are
# set for us by the find script. If you need other libraries, you
# can add them here as well. 
target_link_libraries(wxMUN ${wxWidgets_LIBRARIES} ${LIBXMLPP_LIBRARIES})