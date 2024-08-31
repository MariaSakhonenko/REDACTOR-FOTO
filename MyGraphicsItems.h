#ifndef MYGRAPHICSITEMS_H
#define MYGRAPHICSITEMS_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMouseEvent>
#include <QMenu>
#include <QContextMenuEvent>
#include <QGraphicsSceneContextMenuEvent>

class MyGraphicsTextItem: public QGraphicsTextItem
{
public:
    using QGraphicsTextItem::QGraphicsTextItem;
    MyGraphicsTextItem(const QString &text, const QFont &font, const QColor &fontColor, QMenu *contextMenu, QGraphicsItem *parent = nullptr);

protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;

private:
    QMenu *myContextMenu;
};


class MyGraphicsRectItem: public QGraphicsRectItem
{
public:
    using QGraphicsRectItem::QGraphicsRectItem;
    MyGraphicsRectItem(qreal x, qreal y, qreal width, qreal height, const QPen &pen, const QBrush &brush, QMenu *contextMenu, QGraphicsItem *parent = nullptr);

protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QMenu *myContextMenu;
    int clickedge = 0; // 1 - left; 2 - right; 3 - top; 4 - bottom; 0 - not resizing
    QPointF clickpos;
    QRectF clickrect;
};


class MyGraphicsEllipseItem: public QGraphicsEllipseItem
{
public:
    using QGraphicsEllipseItem::QGraphicsEllipseItem;
    MyGraphicsEllipseItem(qreal x, qreal y, qreal width, qreal height, const QPen &pen, const QBrush &brush, QMenu *contextMenu, QGraphicsItem *parent = nullptr);

protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QMenu *myContextMenu;
    int clickedge = 0; // 1 - left; 2 - right; 3 - top; 4 - bottom; 0 - not resizing
    QPointF clickpos;
    QRectF clickrect;
};


class MyGraphicsPolygonItem: public QGraphicsPolygonItem
{
public:
    using QGraphicsPolygonItem::QGraphicsPolygonItem;
    MyGraphicsPolygonItem(const QPolygonF &polygon, const QPen &pen, const QBrush &brush, QMenu *contextMenu, QGraphicsItem *parent = nullptr);

protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;

private:
    QMenu *myContextMenu;

};


#endif // MYGRAPHICSITEMS_H
