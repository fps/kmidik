cmake_minimum_required(VERSION 2.8)

project(KMidiKeyboard)
set(PROJECT_VERSION 0.1)

set(CMAKE_INSTALL_PREFIX /usr)

set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION}})
include(CPack)

find_package(KF5GlobalAccel REQUIRED)

add_executable(kmidikeyboard main.cc)
target_link_libraries(kmidikeyboard KF5::GlobalAccel)

