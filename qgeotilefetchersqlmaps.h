#ifndef QGEOTILEFETCHERSQLMAPS_H
#define QGEOTILEFETCHERSQLMAPS_H

#include "qgeoserviceproviderpluginsqlmaps.h"

#include <QtLocation/private/qgeotilefetcher_p.h>
#include <QMutex>
#include <QSqlDatabase>
#include <QString>

QT_BEGIN_NAMESPACE

class QGeoTiledMapReply;
class QGeoTileSpec;
class QGeoTiledMappingManagerEngine;
class QGeoTiledMappingManagerEngineSqlMaps;

class QGeoTileFetcherSqlMaps: public QGeoTileFetcher
{
        Q_OBJECT

public:
        QGeoTileFetcherSqlMaps(const QVariantMap &parameters,
                               QGeoTiledMappingManagerEngineSqlMaps *engine, const QSize &tileSize);

        ~QGeoTileFetcherSqlMaps();

        QGeoTiledMapReply* getTileImage(const QGeoTileSpec &spec);

private:
        QString            _getURL(int type, int x, int y, int zoom);

private:
        Q_DISABLE_COPY(QGeoTileFetcherSqlMaps)

        QString mPath;
        QString                                         mFileSuffix;
        QPointer<QGeoTiledMappingManagerEngineSqlMaps>  m_engineXYZmaps;
        QSize                                           m_tileSize;
        QSqlDatabase                                    m_db;
};

QT_END_NAMESPACE

#endif
