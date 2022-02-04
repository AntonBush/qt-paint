#ifndef WORKSPACE_H
#define WORKSPACE_H

#include "canvas.h"
#include "tool.h"

#include <memory>
#include <QGraphicsScene>
#include <QObject>

class Workspace : public QGraphicsScene
{
    Q_OBJECT

    Canvas * canvas;
    std::shared_ptr<Tool> activeTool;
public:
    static QRect defaultWorkspaceRect;

    Workspace(QObject * parent = nullptr);
    virtual ~Workspace() = default;

    void setActiveTool(std::shared_ptr<Tool>);
    Canvas * getCanvas();

    void mousePressEvent(QGraphicsSceneMouseEvent*) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent*) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent*) override;

//public slots:
//    void mousePressEvent(QGraphicsSceneMouseEvent*);
//    void mouseReleaseEvent(QGraphicsSceneMouseEvent*);
//    void mouseMoveEvent(QGraphicsSceneMouseEvent*);
};

#endif // WORKSPACE_H
