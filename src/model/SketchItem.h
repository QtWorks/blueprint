#ifndef SKETCHITEM_H
#define SKETCHITEM_H

#include <QGraphicsItem>

#include "model/BoundingBox.h"
#include "model/BoundingBoxPoint.h"

class SketchItem
{
public:

    enum Type {
        SKETCH_ITEM_BEZIER,
        BOUNDING_BOX_POINT,
        BEZIER_POINT,
        BEZIER_CONTROL_POINT
    };

    enum EditMode {
        BOUNDING_BOX,
        BEZIER
    };

    SketchItem();
    virtual ~SketchItem();

    virtual QGraphicsItem* getGraphicsItem() = 0;
    virtual void setIsSelected(bool isSelected) { }
    virtual void setEditMode(EditMode mode);
    virtual void boundingBoxEvent(const BoundingBoxEvent& event) = 0;

    QString name;

protected:
    EditMode mEditMode;


};

#endif // SKETCHITEM_H
