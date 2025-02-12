#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include <QWidget>
#include "people.h"
namespace Ui {
class searchWidget;
}

class searchWidget : public QWidget
{
    Q_OBJECT

public:
    explicit searchWidget(QWidget *parent = nullptr);
    ~searchWidget();
public:
    void searchforname(PNode* p,QString name);
    void searchforPhone(PNode* p,QStringList phone);
    void searchforPosition(PNode* p,QString position);
    void searchforAddress(PNode* p,QString address);

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::searchWidget *ui;
};

#endif // SEARCHWIDGET_H
