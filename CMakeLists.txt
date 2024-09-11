cmake_minimum_required(VERSION 3.16)

# Specify the project name and version
project(qtgeoservices_sqlmaps VERSION 1.0 LANGUAGES CXX)

# Find the Qt packages required for the plugin
find_package(QT NAMES Qt6 REQUIRED COMPONENTS Location Sql Positioning)
find_package(Qt6 REQUIRED COMPONENTS Location Sql Positioning)

include_directories(${Qt6Location_PRIVATE_INCLUDE_DIRS})


# Specify the source files and header files
set(SOURCES
    qgeomapreplysql.cpp
    qgeoserviceproviderpluginsqlmaps.cpp
    qgeotiledmapsqlmaps.cpp
    qgeotiledmappingmanagerenginesqlmaps.cpp
    qgeotilefetchersqlmaps.cpp
)

set(HEADERS
    qgeomapreplysql.h
    qgeoserviceproviderpluginsqlmaps.h
    qgeotiledmapsqlmaps.h
    qgeotiledmappingmanagerenginesqlmaps.h
    qgeotilefetchersqlmaps.h
)

# Add a library target for the plugin
add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS})

# Set the properties for the library
set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    QT_NEEDS_OLD_LIBS TRUE
)

# Specify the required Qt components for linking
target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Location
    Qt6::Sql
    Qt6::Positioning
)

# Specify the plugin metadata file
set(PLUGIN_METADATA_FILE "sqlmaps_plugin.json")
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugins
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugins
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugins
)

# Configure the plugin's export symbols (if necessary)
# The following lines can be adapted according to your project's settings
if (WIN32)
    target_compile_definitions(${PROJECT_NAME} PRIVATE "Q_DECL_EXPORT")
endif ()

# If you want to copy the JSON metadata file to the output directory
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/${PLUGIN_METADATA_FILE} $<TARGET_FILE_DIR:${PROJECT_NAME}>
)
