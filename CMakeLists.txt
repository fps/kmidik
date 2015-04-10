cmake_minimum_required(VERSION 2.8)

project(KMidiK)
set(PROJECT_VERSION 0.1)

set(CMAKE_INSTALL_PREFIX /usr)

set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION}})
include(CPack)

find_package(KF5GlobalAccel REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(PkgConfig REQUIRED)

pkg_check_modules(JACK jack REQUIRED)
pkg_check_modules(ALSA alsa REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

include_directories({Qt5Widgets_INCLUDE_DIRS})

add_executable(kmidik main.cc main_window.cc)
target_link_libraries(kmidik KF5::GlobalAccel Qt5Widgets ${JACK_LDFLAGS} ${ALSA_LDFLAGS})

install(TARGETS kmidik RUNTIME DESTINATION bin/)
