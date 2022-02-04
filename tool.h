#ifndef TOOL_H
#define TOOL_H

#include <QGraphicsSceneMouseEvent>

class Tool
{
public:
    virtual ~Tool() = default;

    virtual void onMouseDown(QGraphicsSceneMouseEvent *) = 0;
    virtual void onMouseUp(QGraphicsSceneMouseEvent *) = 0;
    virtual void onMouseMove(QGraphicsSceneMouseEvent *) = 0;
};

#endif // TOOL_H
