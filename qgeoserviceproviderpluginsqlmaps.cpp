#include "qgeoserviceproviderpluginsqlmaps.h"
#include "qgeotiledmappingmanagerenginesqlmaps.h"


QGeoCodingManagerEngine *QGeoServiceProviderFactorySqlMaps::createGeocodingManagerEngine(
    const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const
{
    Q_UNUSED(parameters)
    Q_UNUSED(error)
    Q_UNUSED(errorString)
    return Q_NULLPTR;//new QGeoCodingManagerEngineBingmaps(parameters, error, errorString);
}

QGeoRoutingManagerEngine *QGeoServiceProviderFactorySqlMaps::createRoutingManagerEngine(
    const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const
{
    Q_UNUSED(parameters)
    Q_UNUSED(error)
    Q_UNUSED(errorString)

    return Q_NULLPTR;//new QGeoRoutingManagerEngineBingmaps(parameters, error, errorString);
}

QPlaceManagerEngine *QGeoServiceProviderFactorySqlMaps::createPlaceManagerEngine(
    const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const
{
    Q_UNUSED(parameters)
    Q_UNUSED(error)
    Q_UNUSED(errorString)

    return Q_NULLPTR;//new QPlaceManagerEngineBingmaps(parameters, error, errorString);
}

QGeoMappingManagerEngine *QGeoServiceProviderFactorySqlMaps::createMappingManagerEngine(
        const QVariantMap &parameters,
        QGeoServiceProvider::Error *error,
        QString *errorString) const
{
    return new QGeoTiledMappingManagerEngineSqlMaps(parameters, error, errorString);
}
