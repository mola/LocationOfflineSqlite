TARGET = qtgeoservices_sqlmaps
QT += location-private positioning-private sql
CONFIG += plugin shared

PLUGIN_TYPE = geoservices
PLUGIN_CLASS_NAME = QGeoServiceProviderFactorySqlMaps

load(qt_plugin)

HEADERS += \
    qgeomapreplysql.h \
    qgeoserviceproviderpluginsqlmaps.h \
    qgeotiledmapsqlmaps.h \
    qgeotiledmappingmanagerenginesqlmaps.h \
    qgeotilefetchersqlmaps.h

SOURCES += \
    qgeomapreplysql.cpp \
    qgeoserviceproviderpluginsqlmaps.cpp \
    qgeotiledmapsqlmaps.cpp \
    qgeotiledmappingmanagerenginesqlmaps.cpp \
    qgeotilefetchersqlmaps.cpp


OTHER_FILES += \
    sqlmaps_plugin.json

