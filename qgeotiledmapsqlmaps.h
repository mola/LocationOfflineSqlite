#ifndef QGEOMAPSQLMAPS_H
#define QGEOMAPSQLMAPS_H

#include "QtLocation/private/qgeotiledmap_p.h"
#include <QtGui/QImage>
#include <QtCore/QPointer>

QT_BEGIN_NAMESPACE

class QGeoTiledMappingManagerEngineSqlMaps;

class QGeoTiledMapSqlMaps: public QGeoTiledMap
{
        Q_OBJECT

public:
        QGeoTiledMapSqlMaps(QGeoTiledMappingManagerEngineSqlMaps *engine, QObject *parent = 0);

        ~QGeoTiledMapSqlMaps();

        QString  getViewCopyright();

        void     evaluateCopyrights(const QSet<QGeoTileSpec> &visibleTiles);

private:
        // QImage m_logo;
        QImage                                          m_copyrightsSlab;
        QString                                         m_lastCopyrightsString;
        QPointer<QGeoTiledMappingManagerEngineSqlMaps>  m_engine;

        Q_DISABLE_COPY(QGeoTiledMapSqlMaps)
};

QT_END_NAMESPACE

#endif // QGEOMAPSQLmaps_H
