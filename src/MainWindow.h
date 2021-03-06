#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>

#include "Tool.h"

namespace Ui {
class MainWindow;
}

namespace blueprint {
class Blueprint;
class Canvas;
class Tool;
class Shape;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

    enum SaveAction {
        SAVE_IF_POSSIBLE,
        FORCE_SAVE_AS,
    };

private:
    void initToolbar();
    void initSignalSlots();
    void saveShapeToImage(blueprint::Shape& shape, const QString& filepath);

private slots:
    void setTool(blueprint::Tool::Type toolType);
    void exportShapeToImage();
    void newBlueprint();
    void saveBlueprint(SaveAction saveAction);
    void loadBlueprint();

private:
    Ui::MainWindow* mUi;
    QGraphicsScene* mScene;
    blueprint::Blueprint* mBlueprint;
    QList<blueprint::Tool*> mTools;
};

#endif // MAINWINDOW_H
