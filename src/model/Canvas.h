#ifndef CANVAS_H
#define CANVAS_H

#include <QList>

#include "ShapeRectangle.h"

namespace blueprint {

class Canvas : public ShapeRectangle
{
public:
    Canvas(Shape* parentShape, const qreal& x, const qreal& y);
    ~Canvas();

    SerializeInfo* serialize() const override;

};
}

#endif // CANVAS_H
