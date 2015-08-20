#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QAbstractItemModel>
#include <QPointF>

namespace blueprint {
class TreeItem;

class TreeModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    static TreeModel* instance();

    explicit TreeModel();
    ~TreeModel();

    void addItem(TreeItem* item, TreeItem* parent = 0);
    blueprint::TreeItem* itemFromIndex(const QModelIndex& index) const;

    QVariant data(const QModelIndex& index, int role) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role) override;

    QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex& child) const override;

    int rowCount(const QModelIndex& parent) const override;
    int columnCount(const QModelIndex& parent) const override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    inline void setRootItem(TreeItem* rootItem) { mRootItem = rootItem; }

private:
    TreeItem* mRootItem;
    static TreeModel* sInstance;
};
}

#endif // TREEMODEL_H