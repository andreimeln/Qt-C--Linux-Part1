#ifndef BIBLIOMODEL_H
#define BIBLIOMODEL_H

#include <QAbstractTableModel>
#include <QList>

#include "data.h"

namespace BIBLIO {

class BiblioModel : public QAbstractTableModel
{
    Q_OBJECT

private:
    //BiblioModel *pModel;
    //model();
    QList<DATA::Object*> List;

public:
    BiblioModel(QObject *parent = 0);
    virtual ~BiblioModel();

    QVariant data(const QModelIndex &I, int role = QDisplayRole) const;

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    DATA::Object *at(int k) {return List.at(k);}

private:
};

} // namespace BIBLIO

#endif // BIBLIOMODEL_H
