#include "bibliomodel.h"

namespace BIBLIO {

BiblioModel::BiblioModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    // temporary
    DATA::BOOK *X = new DATA::Book();
    X->Author = "Vasya Pupkin";
    X->Title = "Hello, world!!!";
    List.append(X);
}

BiblioModel::~BiblioModel()
{   // java-styled parsing of list; cf. foreach
    QListIterator<DATA::Object*> it(List);
    while(it.hasNext())
    {
        DATA::Object *X = it.next();
        delete X;
    }
}

QVariant BiblioModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

int BiblioModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return List.size; // List.size() - number of rows in the model

    // FIXME: Implement me!
}

int BiblioModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return 2;

    // FIXME: Implement me!
}

QVariant BiblioModel::data(const QModelIndex &I, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole) {
        switch (I.column())
        {
            case 0:
                return List.at(I.row())->Author;
            case 1:
                return List.at(I.row())->Title;
            default:
                return QVariant();
        }
    } else {
        return QVariant();
    }

}

} // namespace BIBLIO
