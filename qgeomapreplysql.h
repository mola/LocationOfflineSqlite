#ifndef QGEOMAPREPLYSQL_H
#define QGEOMAPREPLYSQL_H

#include <QtLocation/private/qgeotilespec_p.h>
#include <QtLocation/private/qgeotiledmapreply_p.h>
#include <QtCore/QPointer>

QT_BEGIN_NAMESPACE

class QGeoMapReplySqlMaps: public QGeoTiledMapReply
{
    Q_OBJECT

public:
    QGeoMapReplySqlMaps(QString path, const QGeoTileSpec &spec, QObject *parent = 0);

    ~QGeoMapReplySqlMaps();
};

QT_END_NAMESPACE

#endif
