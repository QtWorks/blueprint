#ifndef SKETCHITEMBEZIER_H
#define SKETCHITEMBEZIER_H

#include "SketchItem.h"

#include <QList>
#include <QGraphicsPathItem>
#include <QGraphicsEllipseItem>

#include "BezierElement.h"
#include "BoundingBox.h"

class QPointF;
class BezierPath;

class SketchItemBezier : public SketchItem
{
public:
    SketchItemBezier(qreal x, qreal y);
    ~SketchItemBezier();
    virtual QGraphicsItem* getGraphicsItem();
    void addPath(const QPointF& c1, const QPointF& c2, const QPointF& endPos);
    void closePath();
    void updateElement(BezierElement* bezierElement, const QPointF& pos);
    void boundingBoxEvent(const BoundingBoxEvent& event);
    void setIsSelected(bool isSelected);
    void setEditMode(EditMode mode);


protected:
    void updateBoundingBoxBezierVisibility();

    QGraphicsPathItem* mItem;
    QPainterPath mPath;
    QList<BezierElement*> mElements;
    BoundingBox* mBoundingBox;

    bool mIsPathClosed;
    bool mIsSelected;
};

#endif // SKETCHITEMBEZIER_H
