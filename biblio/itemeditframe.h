#ifndef ITEMEDITFRAME_H
#define ITEMEDITFRAME_H

#include <QFrame>

#include "data.h"

class QVBoxLayout;
class QLabel;
class QLineEdit;
class QComboBox;

namespace BIBLIO {

class ItemEditFrame : public QFrame
{

    Q_OBJECT

private:
    DATA::Object *Dt;
    QLabel *lblTotalPages;
    QLineEdit *edtTotalPages;
    void setup_TotalPages(QLayout *L);

    QComboBox *cbxKind;
    void setup_Kind(QLayout *L);

    QLineEdit *edtAuthor;
    void setup_Author(QLayout *L);

    QLineEdit *edtTitle;
    void setup_Title(QLayout *L);
    void setup_Subtitle(QLayout *L);
    void setup_Location(QLayout *L);
    void setup_Publisher(QLayout *L);
    void setup_Year(QLayout *L);

    QLineEdit *edtJournal;
    void setup_Journal(QLayout *L);
    void setup_Volume(QLayout *L);
    void setup_Issue(QLayout *L);
    void setup_Pages(QLayout *L);
    void setup_Comment(QLayout *L);

protected slots:
    void kindSelected(int index);

public:
    ItemEditFrame(QWidget *parent = 0);
    virtual ~ItemEditFrame();

    void attach(DATA::Object *X);
    void save(void);
    void isValid() const;
};

} // namespace BIBLIO

#endif // ITEMEDITFRAME_H
