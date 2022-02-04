#ifndef PENCILTOOL_H
#define PENCILTOOL_H

#include "tool.h"
#include "workspace.h"

#include <QColor>

class PencilTool : public Tool
{
    Canvas * canvas;
    QColor color;
    int width;
public:
    PencilTool(Canvas *, QColor = Qt::black, int width = 1);

    void onMouseDown(QGraphicsSceneMouseEvent *) override;
    void onMouseUp(QGraphicsSceneMouseEvent *) override;
    void onMouseMove(QGraphicsSceneMouseEvent *) override;
};

#endif // PENCILTOOL_H
