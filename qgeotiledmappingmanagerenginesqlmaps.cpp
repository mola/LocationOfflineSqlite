#include "QtLocation/private/qgeocameracapabilities_p.h"
#include "qgeotiledmappingmanagerenginesqlmaps.h"
#include "qgeotiledmapsqlmaps.h"
#include "qgeotilefetchersqlmaps.h"
#include "QtLocation/private/qgeotilespec_p.h"
#include "QtLocation/private/qgeofiletilecache_p.h"

#include <iostream>

#include <QDebug>
#include <QDir>
#include <QVariant>
#include <QtCore/QJsonArray>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonDocument>
#include <QtCore/qmath.h>
#include <QtCore/qstandardpaths.h>

QT_BEGIN_NAMESPACE

QGeoTiledMappingManagerEngineSqlMaps::QGeoTiledMappingManagerEngineSqlMaps(const QVariantMap          &parameters,
                                                                           QGeoServiceProvider::Error *error,
                                                                           QString                    *errorString):
        QGeoTiledMappingManagerEngine()
{
        Q_UNUSED(error);
        Q_UNUSED(errorString);

        for (auto k : parameters.keys())
        {
                std::cout << "PARAMS: " << k.toStdString() << " : " << parameters[k].toString().toStdString() << std::endl;
        }

        QGeoCameraCapabilities  capabilities;

        capabilities.setMinimumZoomLevel(0.0);
        capabilities.setMaximumZoomLevel(21.0);

        setCameraCapabilities(capabilities);

        int  tile = parameters.value(QStringLiteral("Xyzmaps.maps.tilesize"), 256).toInt();

        setTileSize(QSize(tile, tile));

        QList<QGeoMapType>  types;

#if QT_VERSION < QT_VERSION_CHECK(5, 9, 0)
        types << QGeoMapType(QGeoMapType::StreetMap, "Bing Street Map", "Bing street map", false, false, 1);

#elif QT_VERSION < QT_VERSION_CHECK(5, 10, 0)
        types << QGeoMapType(QGeoMapType::StreetMap, "Bing Street Map", "Bing street map", false, false, 1, "bingmaps");

#else
        types << QGeoMapType(QGeoMapType::SatelliteMapDay, "SQL Map", "SQL map", false, false, 1, "sqlmaps", capabilities, parameters);

#endif

        setSupportedMapTypes(types);

        QGeoTileFetcherSqlMaps *fetcher = new QGeoTileFetcherSqlMaps(parameters, this, tileSize());
        setTileFetcher(fetcher);

// if (parameters.contains(QStringLiteral("bingmaps.cachefolder")))
// {
// m_cacheDirectory = parameters.value(QStringLiteral("bingmaps.cachefolder")).toString().toLatin1();
// }
// else
// {
// m_cacheDirectory = QAbstractGeoTileCache::baseCacheDirectory() + QLatin1String("bingmaps");
// }

// QAbstractGeoTileCache *tileCache = new QGeoFileTileCache(m_cacheDirectory);
// setTileCache(tileCache);

        populateMapSchemes();
}

QGeoTiledMappingManagerEngineSqlMaps::~QGeoTiledMappingManagerEngineSqlMaps()
{
}

void  QGeoTiledMappingManagerEngineSqlMaps::populateMapSchemes()
{
        m_mapSchemes[0] = QStringLiteral("roadmap");
        m_mapSchemes[1] = QStringLiteral("roadmap");
        m_mapSchemes[2] = QStringLiteral("satellite");
        m_mapSchemes[3] = QStringLiteral("hybrid");
}

QString  QGeoTiledMappingManagerEngineSqlMaps::getScheme(int mapId)
{
        return m_mapSchemes[mapId];
}

QGeoMap * QGeoTiledMappingManagerEngineSqlMaps::createMap()
{
        return new QGeoTiledMapSqlMaps(this);
}

QT_END_NAMESPACE
