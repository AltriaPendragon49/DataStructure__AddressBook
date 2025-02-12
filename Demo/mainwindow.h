#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <add.h>
#include <QProcess>
#include "create.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public:
    void displayPeople(PNode* p);
    //void searchPeo(PNode* p,QString name);
private slots:

    void on_pushButton_clicked();

    void on_delp_clicked();

    void on_modp_clicked();

    void on_seap_clicked();

    void on_creg_clicked();

    void on_seeg_clicked();

    void on_modg_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
