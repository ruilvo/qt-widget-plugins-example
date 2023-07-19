cmake_minimum_required(VERSION 3.19 FATAL_ERROR)

project(
  QtPluginsWidgetsExample
  VERSION 0.1
  LANGUAGES CXX)

# Set a clean output structure
# This makes so things build in the right place out of the bat
# The `$<1:>"` are a hack. Why? Because in:
# https://cmake.org/cmake/help/latest/prop_tgt/LIBRARY_OUTPUT_DIRECTORY.html
# it says that "Multi-configuration generators (Visual Studio, Xcode, Ninja Multi-Config)
# append a per-configuration subdirectory to the specified directory unless a generator
# expression is used." and I don't want that.
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib$<1:>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib$<1:>")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin$<1:>")

set(QTPWE_PLUGINS_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/plugins$<1:>")

# Export compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Enable standard C++ 17 globally
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable PIC
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Enable standards-compliant exception handling
if(MSVC)
  add_compile_options("/EHsc")
endif()

# Setup Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QTPWE_QT_REQUIRED_COMPONENTS Core Widgets)

find_package(
  QT NAMES Qt6 Qt5
  COMPONENTS Core
  REQUIRED)
find_package(
  Qt${QT_VERSION_MAJOR}
  COMPONENTS ${QTPWE_QT_REQUIRED_COMPONENTS}
  REQUIRED)

# Helper to export compile_commands.json so clangd can use it
if(CMAKE_EXPORT_COMPILE_COMMANDS)
  # Copy the compilation database to the project folder
  if(("${CMAKE_GENERATOR}" MATCHES "Make") OR ("${CMAKE_GENERATOR}" MATCHES "Ninja$"))
    add_custom_target(
      copy-compile-commands ALL
      ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_BINARY_DIR}/compile_commands.json
      ${CMAKE_CURRENT_SOURCE_DIR})
  endif()
endif()

add_subdirectory(app)
add_subdirectory(plugins)
