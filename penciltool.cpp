#include "penciltool.h"
#include <QDebug>

PencilTool::PencilTool(Canvas * c, QColor color, int width)
    : canvas(c), color(color), width(width)
{
    assert(c != nullptr);
    assert(width > 0);
}

void PencilTool::onMouseDown(QGraphicsSceneMouseEvent * e)
{
    QPainter p(&canvas->getSurface());

    p.setPen(QPen(color, 1));
    p.setBrush(QBrush(color));
    p.drawEllipse(
               e->pos().x() - width / 2,
               e->pos().y() - width / 2,
               width,
               width);
}
void PencilTool::onMouseUp(QGraphicsSceneMouseEvent * e)
{
    QPainter p(&canvas->getSurface());

    p.setPen(QPen(color, width));
    p.setBrush(QBrush(color));
    p.drawLine(e->lastPos(), e->pos());
}
void PencilTool::onMouseMove(QGraphicsSceneMouseEvent * e)
{
    onMouseUp(e);
}
