#include "canvas.h"
#include <algorithm>
#include <QDebug>

Canvas::Canvas(QGraphicsObject * parent)
    : QGraphicsObject(parent), surface(1, 1, QImage::Format_RGB32)
{}

QRectF Canvas::boundingRect() const
{
    return QRectF(surface.rect());
}

void Canvas::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
                   QWidget *)
{
    painter->drawImage(0, 0, surface);
}

QImage& Canvas::getSurface()
{
    return surface;
}

void Canvas::resize(int width, int height)
{
    QImage newSurface(width, height, QImage::Format_RGB32);
    QPainter p(&newSurface);

    p.fillRect(newSurface.rect(), Qt::white);

    int target_width = std::min(width, surface.width());
    int target_height = std::min(height, surface.height());
    QRectF target_rect(QPointF(0,0), QSizeF(target_width, target_height));
    p.drawImage(target_rect, surface, target_rect);

    surface = newSurface;
}

void Canvas::mousePressEvent(QGraphicsSceneMouseEvent * e)
{
    qDebug() << "canvas press: " << e->pos();
    //emit mousePressed(e);
}
void Canvas::mouseReleaseEvent(QGraphicsSceneMouseEvent * e)
{
    qDebug() << "canvas release" << e->pos();
    //emit mouseReleased(e);
}
void Canvas::mouseMoveEvent(QGraphicsSceneMouseEvent * e)
{

    qDebug() << "canvas move" << e->pos();
    //emit mouseMoved(e);
}

