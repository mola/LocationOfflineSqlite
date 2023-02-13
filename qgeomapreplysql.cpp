#include "qgeomapreplysql.h"
#include <QFile>
#include <QDateTime>
#include <QVariant>
#include <iostream>
#include <QSqlQuery>
#include <QSqlError>

QT_BEGIN_NAMESPACE

QGeoMapReplySqlMaps::QGeoMapReplySqlMaps(QString path, const QGeoTileSpec &spec, QObject *parent):
        QGeoTiledMapReply(spec, parent)
{
        QSqlQuery  query;
        QString    q = QString("SELECT id FROM tiles WHERE X = %1 and Y = %2 and Zoom = %3").arg(spec.x()).arg(spec.y()).arg(spec.zoom());
        QString    tile;
        auto       success = query.exec(q);

        if (success)
        {
                if (query.next())
                {
                        tile = query.value(0).toString();
                }
        }
        else
        {
                std::cout << "removePerson error:"
                          << query.lastError().text().toStdString() << std::endl;
        }

        if (tile.isEmpty())
        {
                setError(QGeoTiledMapReply::CommunicationError, "Tile not found in path (" + path + ").");
                setFinished(true);
        }
        else
        {
                QString  q = QString("SELECT Tile FROM tilesdata WHERE id = %1").arg(tile);

                success = query.exec(q);

                if (success)
                {
                        if (query.next())
                        {
                                auto  data = query.value(0).toByteArray();

                                setMapImageData(data);
                                setMapImageFormat("jpg");
                                setFinished(true);
                        }
                }
                else
                {
                        std::cout << "removePerson error:"
                                  << query.lastError().text().toStdString() << std::endl;
                }
        }
}

QGeoMapReplySqlMaps::~QGeoMapReplySqlMaps()
{
}

QT_END_NAMESPACE
