#include "qgeotiledmapsqlmaps.h"
#include "qgeotiledmappingmanagerenginesqlmaps.h"
#if QT_VERSION <= QT_VERSION_CHECK(5, 6, 0)
#include "QtLocation/private/qgeomapcontroller_p.h"
#endif

#include <QDebug>
#include <QObject>
#include <QColor>
#include <QFont>
#include <QPainter>
#include <QImage>
#include <QRect>

#include <QStaticText>

QT_BEGIN_NAMESPACE

/*!
   Constructs a new tiled map data object, which stores the map data required by
   \a geoMap and makes use of the functionality provided by \a engine.
 */
QGeoTiledMapSqlMaps::QGeoTiledMapSqlMaps(QGeoTiledMappingManagerEngineSqlMaps *engine, QObject *parent /*= 0*/):
        QGeoTiledMap(engine, parent),
        m_engine(engine)
{ }

QGeoTiledMapSqlMaps::~QGeoTiledMapSqlMaps() { }

void  QGeoTiledMapSqlMaps::evaluateCopyrights(const QSet<QGeoTileSpec> &visibleTiles)
{
        Q_UNUSED(visibleTiles);
}

QT_END_NAMESPACE
