#ifndef CANVAS_H
#define CANVAS_H

#include <QGraphicsItem>
#include <QPainter>
#include <QImage>
#include <QGraphicsSceneMouseEvent>

class Canvas : public QGraphicsObject
{
    Q_OBJECT

    QImage surface;
public:
    Canvas(QGraphicsObject * parent = nullptr);

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    QImage& getSurface();

    void resize(int width, int height);

    void mousePressEvent(QGraphicsSceneMouseEvent*) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent*) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent*) override;
/*
signals:
    void mousePressed(QGraphicsSceneMouseEvent*);
    void mouseReleased(QGraphicsSceneMouseEvent*);
    void mouseMoved(QGraphicsSceneMouseEvent*);
    */
};

#endif // CANVAS_H
