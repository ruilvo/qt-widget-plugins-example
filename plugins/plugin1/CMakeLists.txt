add_library(plugin1 MODULE "plugin1.cpp" "plugin1.hpp" "plugin1_loader.cpp"
                           "plugin1_loader.hpp" "plugin1_widget.cpp" "plugin1_widget.hpp")
target_link_libraries(plugin1 PRIVATE app_interfaces Qt${QT_VERSION_MAJOR}::Widgets)
set_target_properties(plugin1 PROPERTIES LIBRARY_OUTPUT_DIRECTORY
                                         "${QTPWE_PLUGINS_OUTPUT_DIRECTORY}")
