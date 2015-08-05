#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QGraphicsItem>
#include <QKeyEvent>

#include "model/SketchItem.h"
#include "Tool.h"

namespace Ui {
class MainWindow;
}

class QGraphicsScene;
class Blueprint;
class Sketch;
class GraphicalModel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

public slots:
    void setTool(Tool::Type toolType);

private slots:
    void onCanvasMousePressEvent(QPointF point);
    void onCanvasMouseMoveEvent(QPointF point);
    void onCanvasMouseReleaseEvent(QPointF point);
    void onFocusItemChanged(QGraphicsItem* newFocusItem, QGraphicsItem* oldFocusItem, Qt::FocusReason reason);
    void onCanvasKeyPressEvent(QKeyEvent *event);
    void onCanvasKeyReleaseEvent(QKeyEvent *event);

private:
    void initToolbar();

private:
    Ui::MainWindow* mUi;
    QGraphicsScene* mScene;
    Blueprint* mCurrentBlueprint;
    GraphicalModel* mModel;
    Sketch* mCurrentSketch;
    Tool* mCurrentTool;
    QList<Tool*> mTools;
    SketchItem* mCreatingItem;
    QPointF mCreatingLastPosition;
    SketchItem* mSelectedSketchItem;
};

#endif // MAINWINDOW_H
