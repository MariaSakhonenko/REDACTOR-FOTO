#include "MyGraphicsItems.h"
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsPolygonItem>
#include <QMenu>
#include <QContextMenuEvent>
#include <QGraphicsSceneContextMenuEvent>

//=================================================================================
// MyGraphicsTextItem
//
MyGraphicsTextItem::MyGraphicsTextItem(const QString &text, const QFont &font, const QColor &fontColor, QMenu *contextMenu, QGraphicsItem *parent)
    : QGraphicsTextItem(text, parent), myContextMenu(contextMenu)
{
    this->setFont(font);
    this->setDefaultTextColor(fontColor);
}

void MyGraphicsTextItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    if (myContextMenu)
    {
        scene()->clearSelection();
        setSelected(true);
        myContextMenu->popup(event->screenPos());
    }
}

//=================================================================================
//MyGraphicsRectItem
//
MyGraphicsRectItem::MyGraphicsRectItem(qreal x, qreal y, qreal width, qreal height, const QPen &pen, const QBrush &brush, QMenu *contextMenu, QGraphicsItem *parent)
    : QGraphicsRectItem(x, y, width, height, parent), myContextMenu(contextMenu)
{
    this->setPen(pen);
    this->setBrush(brush);
}

void MyGraphicsRectItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    if (myContextMenu)
    {
        scene()->clearSelection();
        setSelected(true);
        myContextMenu->popup(event->screenPos());
    }
}

void MyGraphicsRectItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qreal margin = 3;
    clickpos = event->pos();
    clickrect = rect();
    if (abs(clickrect.left() - clickpos.x()) < margin)
    {
        clickedge = 1;
    }
    else if (abs(clickrect.right() - clickpos.x()) < margin)
    {
        clickedge = 2;
    }
    else if (abs(clickrect.top() - clickpos.y()) < margin)
    {
        clickedge = 3;
    }
    else if (abs(clickrect.bottom() - clickpos.y()) < margin)
    {
        clickedge = 4;
    }
    else
    {
        clickedge = 0;
    }

    if (clickedge == 0)
    {
        QGraphicsRectItem::mousePressEvent(event);
    }
}

void MyGraphicsRectItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (clickedge != 0)
    {
        prepareGeometryChange();
        QPointF pos = event->pos();
        qreal xmove = pos.x() - clickpos.x();
        qreal ymove = pos.y() - clickpos.y();
        QRectF rect = QRectF(clickrect);

        if (clickedge == 1)
        {
            rect.adjust(xmove, 0, 0, 0);
        }
        else if (clickedge == 2)
        {
            rect.adjust(0, 0, xmove, 0);
        }
        else if (clickedge == 3)
        {
            rect.adjust(0, ymove, 0, 0);
        }
        else if (clickedge == 4)
        {
         rect.adjust(0, 0, 0, ymove);
        }
        setRect(rect);
        update();
    }
    else
    {
        QGraphicsRectItem::mouseMoveEvent(event);
    }
}

void MyGraphicsRectItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    clickedge = 0;
    QGraphicsRectItem::mouseReleaseEvent(event);
}

//=================================================================================
//MyGraphicsEllipseItem
//
MyGraphicsEllipseItem::MyGraphicsEllipseItem(qreal x, qreal y, qreal width, qreal height, const QPen &pen, const QBrush &brush, QMenu *contextMenu, QGraphicsItem *parent)
    : QGraphicsEllipseItem(x, y, width, height, parent), myContextMenu(contextMenu)
{
    this->setPen(pen);
    this->setBrush(brush);
}

void MyGraphicsEllipseItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    if (myContextMenu)
    {
        scene()->clearSelection();
        setSelected(true);
        myContextMenu->popup(event->screenPos());
    }
}

void MyGraphicsEllipseItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qreal margin = 3;
    clickpos = event->pos();
    clickrect = rect();
    if (abs(clickrect.left() - clickpos.x()) < margin)
    {
        clickedge = 1;
    }
    else if (abs(clickrect.right() - clickpos.x()) < margin)
    {
        clickedge = 2;
    }
    else if (abs(clickrect.top() - clickpos.y()) < margin)
    {
        clickedge = 3;
    }
    else if (abs(clickrect.bottom() - clickpos.y()) < margin)
    {
        clickedge = 4;
    }
    else
    {
        clickedge = 0;
    }

    if (clickedge == 0)
    {
        QGraphicsEllipseItem::mousePressEvent(event);
    }
}

void MyGraphicsEllipseItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (clickedge != 0)
    {
        prepareGeometryChange();
        QPointF pos = event->pos();
        qreal xmove = pos.x() - clickpos.x();
        qreal ymove = pos.y() - clickpos.y();
        QRectF rect = QRectF(clickrect);

        if (clickedge == 1)
        {
            rect.adjust(xmove, 0, 0, 0);
        }
        else if (clickedge == 2)
        {
            rect.adjust(0, 0, xmove, 0);
        }
        else if (clickedge == 3)
        {
            rect.adjust(0, ymove, 0, 0);
        }
        else if (clickedge == 4)
        {
            rect.adjust(0, 0, 0, ymove);
        }
        setRect(rect);
        update();
    }
    else
    {
        QGraphicsEllipseItem::mouseMoveEvent(event);
    }
}

void MyGraphicsEllipseItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    clickedge = 0;
    QGraphicsEllipseItem::mouseReleaseEvent(event);
}

//=================================================================================
//MyGraphicsPolygonItem
//
MyGraphicsPolygonItem::MyGraphicsPolygonItem(const QPolygonF &polygon, const QPen &pen, const QBrush &brush, QMenu *contextMenu, QGraphicsItem *parent)
    : QGraphicsPolygonItem(polygon, parent), myContextMenu(contextMenu)
{
    this->setPen(pen);
    this->setBrush(brush);
}

void MyGraphicsPolygonItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    if (myContextMenu)
    {
        scene()->clearSelection();
        setSelected(true);
        myContextMenu->popup(event->screenPos());
    }
}
