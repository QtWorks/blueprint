#ifndef BEZIERPOINT_H
#define BEZIERPOINT_H

#include <QGraphicsEllipseItem>

#include "BezierControlPoint.h"

class SketchItemBezier;

class BezierPoint : public QGraphicsEllipseItem
{
public:
    BezierPoint(SketchItemBezier* item, const int index);
    ~BezierPoint();

protected:
    QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant& value);

private:
    SketchItemBezier* mItem;
    int mIndex;
};

#endif // BEZIERPOINT_H