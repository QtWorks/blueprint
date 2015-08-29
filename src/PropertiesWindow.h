#ifndef PROPERTIESWINDOW_H
#define PROPERTIESWINDOW_H

#include <QWidget>

#include "model/Shape.h"

namespace Ui {
class PropertiesWindow;
}

class PropertiesWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PropertiesWindow(QWidget *parent = 0);
    ~PropertiesWindow();

public slots:
    void selectionsChanged(const QModelIndex& parent, int first, int last);
    void onBackgroundColorClicked();

private:
    Ui::PropertiesWindow *mUi;
    blueprint::Shape* mCurrentItem;
};

#endif // PROPERTIESWINDOW_H
