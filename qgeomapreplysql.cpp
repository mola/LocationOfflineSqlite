#include "qgeomapreplysql.h"
#include <QFile>
#include <QDateTime>
#include <QVariant>
#include <iostream>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlResult>
#include <QImage>
#include <QPainter>
#include <QBuffer>

QT_BEGIN_NAMESPACE

QGeoMapReplySqlMaps::QGeoMapReplySqlMaps(QString path, const QGeoTileSpec &spec, QObject *parent):
    QGeoTiledMapReply(spec, parent)
{
    QSqlQuery  query;
    QString    qq      = QString("SELECT id FROM tiles WHERE X = %1 and Y = %2 and Zoom = %3").arg(spec.x()).arg(spec.y()).arg(spec.zoom());
    QString    q       = QString("SELECT Tile FROM tilesdata WHERE id IN (%1)").arg(qq);
    auto       success = query.exec(q);

    if (success)
    {
        QByteArray  data;
        QImage      finalImg;
        QImage      img;
        QPainter    p;


        while (query.next())
        {
            data = query.value(0).toByteArray();

            if (finalImg.isNull())
            {
                finalImg = QImage::fromData(data);
                p.begin(&finalImg);
                continue;
            }

            img = QImage::fromData(data);

            if (!img.isNull())
            {
                p.setCompositionMode(QPainter::CompositionMode_SourceOver);
                p.drawImage(finalImg.rect(), img);
            }
        }

        p.end();

        if (!finalImg.isNull())
        {
            QByteArray  d;
            QBuffer     buffer(&d);

            buffer.open(QIODevice::WriteOnly);


            finalImg.save(&buffer, "jpg");
            buffer.close();

            setMapImageData(d);
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

QGeoMapReplySqlMaps::~QGeoMapReplySqlMaps()
{
}

QT_END_NAMESPACE
