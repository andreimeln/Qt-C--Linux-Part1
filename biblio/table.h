#ifndef TABLE_H
#define TABLE_H

#include <QTableView>

class QAction;

//#include "bibliomodel.h"

namespace BIBLIO {

class Table : public QTableView {

    Q_OBJECT

private:
    QAction *actEdit;
    QAction *actNew;
    QAction actDelete;
//    BiblioModel *pModel;

protected slots:
    void itemEditCurrent(void);
    void itemCreateNew(void);
    void itemDeleteCurrent(void);

public:
    Table(QWidget *parent = 0);
    virtual ~Table();
};

} // namespace BIBLIO

#endif // TABLE_H
