#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>

class QAction;

namespace BIBLIO {

/************************************************************/

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QAction *actNewItem;

    QMap<QString,QAction*> modeActions;
    QAction *actEditMode;
    QAction *actTableMode;

public:
    MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

protected slots:
    void newItem(void);
    void editMode(void);
    void tableMode(void);

signals:
    void cancelMode(bool *OK=0);

};

/************************************************************/

} // namespace BIBLIO

#endif // MAINWINDOW_H
