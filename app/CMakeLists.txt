add_library(app_interfaces INTERFACE)
target_include_directories(app_interfaces INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(
  app WIN32
  "main.cpp"
  "app.hpp"
  "app.cpp"
  "main_window.hpp"
  "main_window.cpp"
  "plugin_factory.hpp"
  "plugin_factory.cpp"
  "plugin_loader.hpp"
  "plugin_loader.cpp"
  "plugin_interface.hpp")

target_link_libraries(app PRIVATE app_interfaces Qt${QT_VERSION_MAJOR}::Widgets)
