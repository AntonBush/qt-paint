#include "workspace.h"
#include "penciltool.h"
#include <QDebug>

QRect Workspace::defaultWorkspaceRect = QRect(0, 0, 800, 400);

Workspace::Workspace(QObject * parent)
    : QGraphicsScene(parent),
      canvas(new Canvas()),
      activeTool(new PencilTool(canvas, 10))
{
    canvas->resize(defaultWorkspaceRect.width(),
                   defaultWorkspaceRect.height());
    addItem(canvas);
/*
    connect(canvas, &Canvas::mousePressed,
            this, &Workspace::mousePressEvent);
    connect(canvas, &Canvas::mouseReleased,
            this, &Workspace::mouseReleaseEvent);
    connect(canvas, &Canvas::mouseMoved,
            this, &Workspace::mouseMoveEvent);*/
}

void Workspace::mousePressEvent(QGraphicsSceneMouseEvent * e)
{
    qDebug() << "press";

    QGraphicsScene::mousePressEvent(e);
    if (activeTool) {
        qDebug() << e->lastPos() << e->pos();
        activeTool->onMouseDown(e);

        canvas->update(sceneRect());
    }
}

void Workspace::mouseReleaseEvent(QGraphicsSceneMouseEvent * e)
{
    qDebug() << "release";

    QGraphicsScene::mouseReleaseEvent(e);
    if (activeTool) {
        qDebug() << e->lastPos() << e->pos();
        activeTool->onMouseUp(e);

        canvas->update(sceneRect());
    }
}

void Workspace::mouseMoveEvent(QGraphicsSceneMouseEvent * e)
{
    qDebug() << "move";

    QGraphicsScene::mouseMoveEvent(e);
    if (activeTool) {
        qDebug() << e->lastPos() << e->pos();
        activeTool->onMouseMove(e);

        canvas->update(sceneRect());
    }
}

void Workspace::setActiveTool(std::shared_ptr<Tool> newTool)
{
    activeTool = newTool;
}

Canvas * Workspace::getCanvas()
{
    return canvas;
}
