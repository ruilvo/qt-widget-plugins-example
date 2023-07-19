add_library(plugin2 MODULE "plugin2.cpp" "plugin2.hpp" "plugin2_loader.cpp"
                           "plugin2_loader.hpp" "plugin2_widget.cpp" "plugin2_widget.hpp")
target_link_libraries(plugin2 PRIVATE app_interfaces Qt${QT_VERSION_MAJOR}::Widgets)
set_target_properties(plugin2 PROPERTIES LIBRARY_OUTPUT_DIRECTORY
                                         "${QTPWE_PLUGINS_OUTPUT_DIRECTORY}")
