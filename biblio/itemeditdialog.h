#ifndef ITEMEDITDIALOG_H
#define ITEMEDITDIALOG_H

#include <QDialog>
#include <QFrame>

#include "data.h"
#include "itemeditframe.h"

class QPushButton;

namespace BIBLIO {
/*****************************************************************/

namespace IED_HELPER {
    class Buttons : public QFrame
       {
            Q_OBJECT
        private:
            QPushButton *pOK;
            QPushButton *pCancel;
        public:
            Buttons(QWidget *parent = 0);
        signals:
            void accepting(void);
            void rejecting(void);
        };
} // namespace IED_HELPER
/**
 * @brief Editing data about edition in a separate window
 */

class ItemEditDialog : public QDialog
{

    Q_OBJECT

private:
//QPushButton *pOK;
//QPushButton *pCancel;
    ItemEditFrame *Edt;
    IED_HELPER::Buttons *Btn;

protected:
    void closeEvent(QCloseEvent *E);

public:
    ItemEditDialog(QWidget *parent=0);
    void attach(DATA::Object *X) { Edt->attach(X); } // inline func
    virtual ~ItemEditDialog();
};

} // namespace BIBLIO

#endif // ITEMEDITDIALOG_H
