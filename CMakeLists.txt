cmake_minimum_required(VERSION 2.8)

project(KMidiKeyboard)
set(PROJECT_VERSION 0.1)

set(CMAKE_INSTALL_PREFIX /usr)

set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION}})
include(CPack)

find_package(KF5GlobalAccel REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories({Qt5Widgets_INCLUDE_DIRS})

add_executable(kmidikeyboard main.cc event_filter.cc)
target_link_libraries(kmidikeyboard KF5::GlobalAccel Qt5Widgets)

